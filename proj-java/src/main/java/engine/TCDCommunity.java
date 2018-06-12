package engine;

import common.*;
import li3.TADCommunity;
import sort.*;

import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;


public class TCDCommunity implements TADCommunity {

    private Map<Long, Post> posts;
    private Map<Long, User> users;
    private Map<String, Tag> tags;

    /**
     * Construtor vazio da estrutura principal
     */
    public TCDCommunity(){
        this.posts = new HashMap<>();
        this.users = new HashMap<>();
        this.tags = new HashMap<>();
    }

    /**
     * Adiciona Post ao HashMap dos posts
     * @param p Post
     */
    public void addPost(Post p){
        if(p instanceof Answer){
            Question q;
            if((q = (Question)this.posts.get(((Answer)p).getParentID())) != null) {
                q.addAnswer(p.getID());
            }
        }
        User u = (User)this.users.get(p.getOwnerID());
        u.addPost(p.getID());
        this.posts.put(p.getID(), p);

    }

    /**
     * Adiciona User ao HashMap dos users
     * @param u User
     */
    public void addUser(User u){
        this.users.put(u.getID(), u);
    }

    /**
     * Adiciona Tag ao HashMap das tags
     * @param t Tag
     */
    public void addTag(Tag t){
        this.tags.put(t.getName(), t);
    }



    public void load(String dumpPath){
        Parser.parseAllFiles(dumpPath, this);
    }





    //Query1

    /**
     * Titulo de uma pergunta e nome do respetivo utilizador que a fez (em caso de ser resposta retornar
     a informaçao da pergunta a que responde)
     * @param id ID da pergunta
     * @return Par de strings em que a primeira é o nome do utilizador e a segunda é o titulo da pergunta
     */
    public Pair<String,String> infoFromPost(long id){

        Post p = this.posts.get(id);
        Question q;

        if(p instanceof Question) q = (Question) p;
            else{

                q = (Question) this.posts.get(((Answer) p).getParentID());
        }
        return new Pair<>(this.users.get(q.getOwnerID()).getName(), q.getTitle());
    }

    // Query 2

    /**
     * Procura os N IDs dos utilizadores que mais posts fizeram.
     * @param N Numero de utilizadores a retornar
     * @return Lista que contém IDs de utilizadores
     */
    public List<Long> topMostActive(int N){

        return this.users.values().stream().sorted(new UserPostCountComparator())
                .limit(N).map(User::getID).collect(Collectors.toList());
    }


    //Query 3

    /**
     * Dado um intervalo de tempo arbitrário obte o número total de posts
     (identificando perguntas e respostas separadamente) neste período.
     * @param begin Início do intervalo de tempo
     * @param end Fim do intervalo de tempo
     * @return Par de longs em que o primeiro é o número de perguntas e o segundo o número de respostas
     */
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end){

        List<Post> posts_date = this.posts.values().stream().
            filter(p ->( p.getDate().isAfter(begin) && p.getDate().isBefore(end)) || p.getDate().equals(begin) || p.getDate().equals(end))
                    .collect(Collectors.toList());

        long qst = posts_date.stream().filter(p -> p instanceof Question).count();
        long ans = posts_date.stream().filter(p -> p instanceof Answer).count();

        return new Pair<Long,Long>(qst, ans);
    }

    //Query 4

    /**
     * Dado um intervalo de tempo arbitrario, retornar todas as perguntas contendo uma determinada tag.
     O retorno da funçao devera ser uma lista com os IDs das perguntas ordenadas em cronologia inversa.
     * @param tag A tag procurada
     * @param begin Início do intervalo de tempo
     * @param end Fim do intervalo de tempo
     * @return Lista de longs com os IDs das perguntas que contenham a tag procurada, em ordem cronológica inversa
     */
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end){

        return this.posts.values().stream().filter(p -> p instanceof Question)
            .filter(p -> (p.getDate().isAfter(begin) && p.getDate().isBefore(end)) || p.getDate().equals(begin) || p.getDate().equals(end))
                .map(p -> (Question) p)
                .filter(q -> q.containsTag(tag)).sorted(new PostDateComparator()).map(Question::getID)
                .collect(Collectors.toList());
    }

    // Query 5

    /**
     * Procura o About Me de um utilizador e os seus respetivos ultimos 10 Posts.
     * @param id ID do utilizador
     * @return  Par que contém About Me e lista com os ultimos 10 Posts ordenados por cronologia inversa
     */
    public Pair<String, List<Long>> getUserInfo(long id){
        List<Long> laux1 = users.get(id).getPosts();
        List<Post> laux2 = new ArrayList<>();
        for (Long l: laux1){
            laux2.add(posts.get(l));
        }

        List<Long> l = laux2.stream().sorted(new PostDateComparator())
                .limit(10).map(Post::getID).collect(Collectors.toList());

        return new Pair<>(users.get(id).getAboutMe(),l);
    }

    //Query 6

    /**
     * Dado um intervalo de tempo arbitrario, devolver os IDs das N respostas com mais votos,
     em ordem decrescente do numero de votos; O nuumero de votos devera ser obtido pela diferença entre
     Up Votes (UpMod6) e Down Votes (DownMod).
     * @param N Número de IDs esperados na lista de retorno
     * @param begin Início do intervalo de tempo
     * @param end Fim do intervalo de tempo
     * @return Lista de longs com os IDs das N respostas com mais votos por ordem decrescente
     */
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end){

        List<Answer> answer_list = posts.values().stream().filter(a -> a instanceof Answer).
            filter(a -> a.getDate().isAfter(begin) && a.getDate().isBefore(end)).map(a -> (Answer) a).
            sorted(new AnswerScoreComparator()).collect(Collectors.toList());

        List<Long> ret = answer_list.stream().limit(N).map(Answer::getID).collect(Collectors.toList());

        return ret;
    }

    // Query 7

    /**
     * Dado um intervalo de tempo arbitrario, devolver os IDs das N perguntas com mais respostas
     * em ordem decrescente do numero
     * @param N Número de IDs esperados na lista de retorno
     * @param begin Início do intervalo de tempo
     * @param end Fim do intervalo de tempo
     * @return Lista de longs com os IDs das N perguntas com mais respostas, em ordem decrescente
     */
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end){

        List<Long> lq = this.posts.values().stream().filter(p -> p instanceof Question)
            .filter(p -> (p.getDate().isAfter(begin) && p.getDate().isBefore(end)) || p.getDate().equals(end) || p.getDate().equals(begin))
            .map(p -> (Question) p).sorted(new AnswerCountComparator())
            .map(Question::getID).limit(N).collect(Collectors.toList());

        return lq;

    }

    //Query 8

    /**
     * Dado uma palavra, devolver uma lista com os IDs de N perguntas cujos tıtulos a contenham,
     ordenados por cronologia inversa
     * @param N Número de IDs esperados na lista de retorn
     * @param word Palavra a ser procurada nos títulos dos posts
     * @return Lista de longs com os IDs das N perguntas em que o título contenha, em ordem cronológica inversa
     */
    public List<Long> containsWord(int N, String word){

        List<Long> question_word = this.posts.values().stream().filter(p -> p instanceof Question).
            map(p -> (Question) p).filter(p -> p.getTitle().contains(word)).sorted(new PostDateComparator()).
            limit(N).map(Question::getID).collect(Collectors.toList());

        return question_word;
    }


    // Query 9

    /**
     * Verifica se existem posts em que dois utilizadores interagiram.
     * @param N Top N
     * @param id1 Utilizador1
     * @param id2 Utilizador2
     * @return Lista com os N IDs dos posts em que interagiram
     */
    public List<Long> bothParticipated(int N, long id1, long id2){

        List<Long> l1 = users.get(id1).getPosts();
        List<Long> l2 = users.get(id2).getPosts();
        Post p;
        List<Post> ret = new ArrayList<>();

        for(Long lh: l1) {
            p = posts.get(lh);
            for (Long le : l2) {
                if (p instanceof Question) {
                    if(((Question) p).getAnswers().contains(le))
                     if(!ret.contains(p))   ret.add(p);
                }
            }
        }
        for(Long l: l2) {
            p = posts.get(l);
            for (Long lp : l1) {
                if (p instanceof Question) {
                    if(((Question) p).getAnswers().contains(lp))
                        if(!ret.contains(p))   ret.add(p);
                }
            }
        }

        for(Long h: l1){
            p = posts.get(h);
            if(p instanceof Answer){
                p = posts.get(((Answer) p).getParentID());
                for (Long  h1: l2){
                    if(posts.get(h1) instanceof Answer && ((Answer) posts.get(h1)).getParentID()==p.getID()){
                        if(!ret.contains(p))   ret.add(p);
                    }
                }

            }
        }
        return ret.stream().sorted(new PostDateComparator()).map(Post::getID).limit(N)
                .collect(Collectors.toList());
    }


    // Query 10

    /**
     * Procura a melhor resposta a uma pergunta.
     * @param id ID da pergunta
     * @return ID da melhor resposta
     */
    public long betterAnswer(long id){
        Question q = (Question) posts.get(id);
        List<Long> answer_id = q.getAnswers();
        List<Answer> l = new ArrayList<>();
        
        for (Long ans_d : answer_id) {
            l.add((Answer) posts.get(ans_d));
        }
        
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


    //Query 11

    /**
     * Dado um intervalo arbitrario de tempo, devolver os identificadores das N tags mais usadas pelos N
     utilizadores com melhor reputaçao. Em ordem decrescente do numero de vezes em que a tag foi usada
     * @param N Quantida de Tags para fazer o retorno e também a quantidade de utilizadores a considerar
     * @param begin  Início do intervalo de tempo
     * @param end Fim do intervalo de tempo
     * @return Lista com os IDs das tags mais usadas pelos N utilizadores com melhor reputação
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end){

        ArrayList<Pair<Long,Long>> pair_list = new ArrayList<>();
        List<Long> tags_id = new ArrayList<>();
        Set<Long> hs = new HashSet<>();

        //Lista com os N utilizadores com maior reputação
        List<Long> user_list = this.users.values().stream().sorted(new UserReputationComparator()).
            limit(N).map(User::getID).collect(Collectors.toList());

        //Posts feitos pelos N utilizadores com maior reputação compreendidos entre as datas passadas
        //como argumento
        List<Question> posts_date = this.posts.values().stream().filter(p -> p instanceof Question).
            filter(p -> (p.getDate().isAfter(begin) && p.getDate().isBefore(end)) || p.getDate().equals(begin) || p.getDate().equals(begin) ).
            filter(p -> user_list.contains(p.getOwnerID())).map(p -> (Question) p).
            collect(Collectors.toList());

        //Adiciono o id de todas as tags em uma lista
        for (Question q : posts_date)
            for (String tag : q.getTags())
                tags_id.add(tags.get(tag).getID());
        
        //Adiciono todas os id's das tags em um HashSet, que não aceita valor repetido
        hs.addAll(tags_id);

        //Por cada id no HashSet, vejo quantas vezes ele aparece na lista tags_id
        for (Long id : hs){
            long occ = (long) Collections.frequency(hs, id);
            Pair<Long,Long> pair = new Pair<>(id, occ);
            pair_list.add(pair);
        }

        List<Long> ret = pair_list.stream().sorted(new PairSecondComparator())
            .map(Pair::getFst).limit(N).collect(Collectors.toList());

        return ret;
    }


    public void clear(){
        posts.clear();
        users.clear();
        tags.clear();

    }
}