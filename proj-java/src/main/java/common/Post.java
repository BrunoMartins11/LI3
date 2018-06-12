package common;

import java.time.LocalDate;

public abstract class Post {

    /**
     * Id do post
     */
    private long id;

    /**
     * ID do utilizador que criou o post
     */
    private long ownerID;

    /**
     * Pontuação do post
     */
    private long score;

    /**
     * Quantidade de comentários
     */
    private long commentCount;

    /**
     * Data de criação
     */
    private LocalDate date;
    

    /**
     * Contrutor vazio
     */
    public Post(){
        this.id = 0;
        this.ownerID = 0;
        this.score = 0;
        this.commentCount = 0;
        this.date = LocalDate.now();
    }

    /**
     * Construtor parametrizado
     * @param id ID do post
     * @param owner_id ID do utilizador que criou o post
     * @param score Pontuação do post
     * @param cc Quantidade de comentários
     * @param date Data de criação do post
     */
    public Post(long id, long owner_id, long score, long cc, LocalDate date){
        this.id = id;
        this.ownerID = owner_id;
        this.score = score;
        this.commentCount = cc;
        this.date = date;
    }

    /**
     * Construtor de cópia
     * @param object Post a ser copiado
     */
    public Post(Post object){
        this.id = object.getID();
        this.ownerID = object.getOwnerID();
        this.score = object.getScore();
        this.commentCount = object.getCommentCount();
        this.date = object.getDate();
    }


    /**
     * Retorna o ID de um Post
     * @return ID do post
     */
    public long getID(){
        return this.id;
    }

    /**
     * Retorna o ID do User que fez o Post
     * @return ID do User
     */
    public long getOwnerID(){
        return this.ownerID;
    }

    /**
     * Retorna o Score de um Post
     * @return Score de um Post
     */
    public long getScore(){
        return this.score;
    }

    /**
     * Retorna o numero de comentarios de um Post
     * @return Numero de comentarios de um Post
     */
    public long getCommentCount(){
        return this.commentCount;
    }

    /**
     * Retorna a data do Post
     * @return Data do Post
     */
    public LocalDate getDate(){
        return this.date;
    }

    /**
     * Clona um Post
     * @return Post
     */
    public abstract Post clone();

    /**
     * Verifica de dois Posts são iguais
     * @param o Post
     * @return Boolean
     */
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

