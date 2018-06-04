package main.java.engine;

public class Tag {
    
    private long id;
    private String name;

    public Tag(){
        this.id = 0;
        this.name = 0;
    }

    public Tag(long id, String name){
        this.id = id;
        this.name = name;
    }

    public Tag(Tag object){
        this.name = object.getName();
        this.id = object.getID();
    }

    public long getID(){
        return this.id;
    }

    public String getName(){
        return this.name;
    }

    public void setID(long id){
        this.id = id;
    }

    public void setName(String name){
        this.name = name;
    }

    public Tag clone(){
        return new Tag(this);
    }
}