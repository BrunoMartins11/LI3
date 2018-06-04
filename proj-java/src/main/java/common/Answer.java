package main.java.common;

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

    public Answer clone(){
        return new Answer(this);
    }

    public boolean equals(Object o){
       
        if (super.equals(o)){
            Answer ans = (Answer) o;
            return (this.getParentID() == ans.getParentID());
        }
        
        else
            return false;
    }
}