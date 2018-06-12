package common;

import java.util.ArrayList;
import java.util.List;

public class User {
    
    /**
     * Nome do utilizador
     */
    private String name;

    /**
     * Informação sobre o utilizador
     */
    private String about;

    /**
     * ID do utlizador
     */
    private long id;

    /**
     * Reputação
     */
    private long reputation;

    /**
     * Lista com os ID's de todos os posts feitos pelo utlizador
     */
    private List<Long> posts;


    /**
     * Construtor vazio
     */
    public User(){
        this.name = "";
        this.about = "";
        this.id = 0;
        this.reputation = 0;
        this.posts = new ArrayList<>();
    }

    /**
     * Construtor parametrizado
     * @param name Nome
     * @param about Informação sobre o utilizador
     * @param id ID do utilizador
     * @param reputation Reputação
     */
    public User(String name, String about, long id, long reputation){
        this.name = name;
        this.about = about;
        this.id = id;
        this.reputation = reputation;
        
        this.posts = new ArrayList<>();
    }

    /**
     * Construtor cópia
     * @param object User a ser copiado
     */
    public User(User object){
        this.name = object.getName();
        this.about = object.getAboutMe();
        this.id = object.getID();
        this.reputation = object.getReputation();
        
        this.posts = new ArrayList<>();
        this.posts.addAll(object.getPosts());
    }

    public String getName(){
        return this.name;
    }

    public String getAboutMe(){
        return this.about;
    }

    public long getID(){
        return this.id;
    }

    public long getReputation(){
        return this.reputation;
    }

    public List<Long> getPosts(){
        return new ArrayList<>( this.posts);
    }

    public int getPostCount(){
        return this.posts.size();
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAboutMe(String about){
        this.about = about;
    }

    public void setID(long id){
        this.id = id;
    }

    public void setReputation(long reputation){
        this.reputation = reputation;
    }

    public void setPosts(List<Long> posts){
        this.posts.addAll(posts);
    }

    public void addPost(Long p){
        this.posts.add(p);
    }
}