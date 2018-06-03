package main.java.engine;

import java.time.LocalDateTime;


public abstract class Post {

    private long id;
    private long ownerID;
    private long score;
    private int commentCount;
    private LocalDateTime date;

    public Post(){
        this.id = 0;
        this.ownerID = 0;
        this.score = 0;
        this.commentCount = 0;
        this.date = LocalDateTime.now();
    }

    public Post(long id, long owner_id, long score, int cc, LocalDateTime date){
        this.id = id;
        this.ownerID = id;
        this.score = score;
        this.commentCount = cc;
        this.date = date;
    }

    public Post(Post object){
        this.id = object.getID();
        this.ownerID = object.getOwnerID();
        this.score = object.getScore();
        this.commentCount = object.getCommentCount();
        this.date = object.getDate();
    }

    

    public long getID(){
        return this.id;
    }

    public long getOwnerID(){
        return this.ownerID;
    }

    public long getScore(){
        return this.score;
    }

    public int getCommentCount(){
        return this.commentCount;
    }

    public LocalDateTime getDate(){
        return this.date;
    }

    public void setID(long id){
        this.id = id;
    }

    public void setOwnerID(long id){
        this.ownerID = id;
    }

    public void setScore(long score){
        this.score = score;
    }

    public void setCommentCount(int number){
        this.commentCount = number;
    }

    public void setDate(LocalDateTime date){
        this.date = date;
    }

    

}

