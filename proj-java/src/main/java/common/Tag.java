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

    /**
     * Retorna ID de uma Tag
     * @return ID da Tag
     */
    public long getID(){
        return this.id;
    }

    /**
     * Retorna nome de uma Tag
     * @return Nome da Tag
     */
    public String getName(){
        return this.name;
    }

    /**
     * Clone de uma Tag
     * @return Tag
     */
    public Tag clone(){
        return new Tag(this);
    }

}