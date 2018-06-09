package main.java.engine;

import main.java.common.*;
import main.java.sort.PostDateComparator;
import main.java.sort.UserPostCountComparator;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public class TCDCommunity /*implements TADCommunity*/ {

    private Map<Long,Post> posts;
    private Map<Long,User> users;
    private Map<Long,Tag> tags;

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
    public Pair<Long,Long> totalPosts(LocalDateTime begin, LocalDateTime end){

        Stream posts_dates = posts.entrySet().stream().map(p -> p.getValue()).
            filter(p -> p.getDate().isAfter(begin) && p.getDate().isBefore(end));

        long ans = posts_dates.filter(p -> p instanceof Answer).count();
        long qst = posts_dates.filter(p -> p instanceof Question).count();

        return new Pair<Long,Long>(ans, qst);
    }

    //Query 4
    public List<Long> questionsWithTag(String tag, LocalDateTime begin, LocalDateTime end){

        List<Question> question_tag = posts.entrySet().stream().map(p -> p.getValue()).
                filter(p -> p.getDate().isAfter(begin) && p.getDate().isBefore(end))
                .filter(q -> q instanceof Question).map(p -> (Question) p)
                .filter(q -> q.containsTag(tag)).collect(Collectors.toList());


        return question_tag.stream().sorted(new PostDateComparator()).map(p -> p.getID()).collect(Collectors.toList());
    }

    //Query 8
    public List<Long> containsWord(int N, String word){

        List<Question> question_word = posts.entrySet().stream()
                .filter(p -> p.getValue() instanceof Question).map(p -> (Question) p)
                .sorted(new PostDateComparator())
                .collect(Collectors.toList());

        return question_word.stream().filter(q -> q.getTitle().contains(word)).limit(N).
            map(q -> q.getID()).collect(Collectors.toList());
    }
}