package common;

import java.util.ArrayList;
import java.util.List;

public class User {
    
    private String name;
    private String about;
    private long id;
    private long reputation;
    private List<Long> posts;


    public User(){
        this.name = "";
        this.about = "";
        this.id = 0;
        this.reputation = 0;
        this.posts = new ArrayList<>();
    }

    public User(String name, String about, long id, long reputatio, List<Long> posts){
        this.name = name;
        this.about = about;
        this.id = id;
        this.reputation = reputatio;
        
        this.posts = new ArrayList<>();
        this.posts.addAll(posts);
    }

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