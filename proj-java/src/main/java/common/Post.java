package main.java.common;

import java.time.LocalDate;

public abstract class Post {

    private long id;
    private long ownerID;
    private long score;
    private int commentCount;
    private LocalDate date;

    public Post(){
        this.id = 0;
        this.ownerID = 0;
        this.score = 0;
        this.commentCount = 0;
        this.date = LocalDate.now();
    }

    public Post(long id, long owner_id, long score, int cc, LocalDate date){
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

    public LocalDate getDate(){
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

    public void setDate(LocalDate date){
        this.date = date;
    }

    public abstract Post clone();

    public boolean equals(Object o){
        if (this == o)
            return true;

        else if (o == null || this.getClass() != o.getClass())
            return false;

        else {
            Post p = (Post) o;

            return (this.getID() == p.getID() && this.getOwnerID() == p.getOwnerID() && 
                    this.getScore() == p.getScore() && this.getDate().equals(p.getDate()) && 
                    this.getCommentCount() == p.getCommentCount());
        }
    }
}

