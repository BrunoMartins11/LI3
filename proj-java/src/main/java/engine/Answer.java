package main.java.engine;

public class Answer extends Post {

    private long parentID;

    public Answer(){
        super();
        this.parentID = 0;
    }

    public Answer(long id, long owner_id, long score, int cc, LocalDateTime date, long parentID){
        super(id, owner_id, score, cc, date);
        this.parentID = parentID;
    }

    public Answer(Answer object){
        super(object);
        this.parentID = object.getParentID();
    }

    public long getParentID(){
        return this.parentID;
    }

    public void setParentID(long parentID){
        this.parentID = parentID;
    }
}