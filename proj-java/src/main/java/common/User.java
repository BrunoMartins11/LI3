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

    /**
     * Retorna nome de um User
     * @return Nome do User
     */
    public String getName(){
        return this.name;
    }

    /**
     * Retorna About me de um User
     * @return About me de um User
     */
    public String getAboutMe(){
        return this.about;
    }

    /**
     * Retorna o ID de um User
     * @return ID do User
     */
    public long getID(){
        return this.id;
    }

    /**
     * Retorna reputação de um User
     * @return Reputaçao do User
     */
    public long getReputation(){
        return this.reputation;
    }

    /**
     * Retorna a Lista que contém o ID dos posts do User
     * @return Lista que contém o ID dos Posts do User
     */
    public List<Long> getPosts(){
        return new ArrayList<>( this.posts);
    }

    /**
     * Retorna o numero de Posts de um User
     * @return Numero de Posts de um User
     */
    public int getPostCount(){
        return this.posts.size();
    }

    /**
     * Adiciona um ID de um Post à lista de posts de um User
     * @param p ID do post
     */
    public void addPost(Long p){
        this.posts.add(p);
    }
}