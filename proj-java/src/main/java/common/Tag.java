package common;

public class Tag {
    
    /**
     * ID da tag
     */
    private long id;

    /**
     * Nome da tag
     */
    private String name;

    /**
     * Construtor vazio
     */
    public Tag(){
        this.id = 0;
        this.name = "";
    }

    /**
     * Construtor parametrizado
     * @param id ID da tag
     * @param name Nome da tag
     */
    public Tag(long id, String name){
        this.id = id;
        this.name = name;
    }

    /**
     * Construtor cópia
     * @param object Tag a ser copiada
     */
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