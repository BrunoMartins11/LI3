package main.java.engine;

import main.java.common.*;
import main.java.sort.AnswerCountComparator;
import main.java.sort.PostDateComparator;
import main.java.sort.UserPostCountComparator;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class TCDCommunity /*implements TADCommunity*/ {

    private Map<Long,Post> posts;
    private Map<Long,User> users;
    private Map<Long,Tag> tags;

    public TCDCommunity(){
        this.posts = new HashMap<>();
        this.users = new HashMap<>();
        this.tags = new HashMap<>();
    }


    public void addPost(Post p){
        this.posts.put(p.getID(), p);

    }

    public void addUser(User u){
        this.users.put(u.getID(), u);
    }

    public void addTag(Tag t){
        this.tags.put(t.getID(), t);
    }

    //Query1
    public Pair<String,String> infoFromPost(long id){

        Post p = posts.get(id);
        Question q;

        if(p instanceof Question) q = (Question) p;
            else{

                q = (Question) posts.get(((Answer) p).getParentID());
        }
        return new Pair<>(users.get(q.getOwnerID()).getName(),q.getTitle());
    }

    // Query 2
    public List<Long> topMostActive(int N){

        return users.values().stream().sorted(new UserPostCountComparator())
                .limit(N).map(User::getID).collect(Collectors.toList());
    }


    //Query 3
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end){

        // Se é stream, é stream de algo, cabeça de piça ~ herulume
        Stream<Post> posts_dates = posts.entrySet().stream().map(Map.Entry::getValue).
            filter(p -> p.getDate().isAfter(begin) && p.getDate().isBefore(end));

        long ans = posts_dates.filter(p -> p instanceof Answer).count();
        long qst = posts_dates.filter(p -> p instanceof Question).count();

        return new Pair<Long,Long>(ans, qst);
    }

    //Query 4
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end){

        List<Question> question_tag = posts.entrySet().stream().map(Map.Entry::getValue).
                filter(p -> p.getDate().isAfter(begin) && p.getDate().isBefore(end))
                .filter(q -> q instanceof Question).map(p -> (Question) p)
                .filter(q -> q.containsTag(tag)).collect(Collectors.toList());


        return question_tag.stream().sorted(new PostDateComparator()).map(Post::getID).collect(Collectors.toList());
    }

    // Query 5
    public Pair<String, List<Long>> getUserInfo(long id){
        List<Long> l = users.get(id).getPosts().stream().sorted(new PostDateComparator())
                .limit(10).map(Post::getID).collect(Collectors.toList());

        return new Pair<>(users.get(id).getAboutMe(),l);
    }

    // Query 7
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end){

        List<Question> lq = posts.values().stream().filter(p -> p instanceof Question)
                            .map(p->(Question) p).sorted(new AnswerCountComparator()).limit(N).collect(Collectors.toList());

        return lq.stream().map(Question::getID).collect(Collectors.toList());

    }

    //Query 8
    public List<Long> containsWord(int N, String word){

        List<Question> question_word = posts.entrySet().stream()
                .filter(p -> p.getValue() instanceof Question).map(p -> (Question) p)
                .sorted(new PostDateComparator())
                .collect(Collectors.toList());

        return question_word.stream().filter(q -> q.getTitle().contains(word)).limit(N).
            map(Post::getID).collect(Collectors.toList());
    }

    // Query 10
    public long betterAnswer(long id){
        Question q = (Question) posts.get(id);
        List<Answer> l = q.getAnswers();
        double max = 0;
        double sc = 0;
        long bid = 0;
        for(Answer a : l){
            sc = a.getCommentCount()*0.1+users.get(a.getOwnerID()).getReputation()*0.25+a.getScore()*0.65;
            if(max<sc){
                max = sc;
                bid = a.getID();
            }
        }
        return bid;
    }
}