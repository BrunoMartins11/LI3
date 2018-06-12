package common;
import java.time.LocalDate;

public class Answer extends Post {

    /**
     * ID da pergunta a qual a reposta está vinculada
     */
    private long parentID;

    /**
     * Contrutor vazio
     */
    public Answer(){
        super();
        this.parentID = 0;
    }

    /**
     * Construtor parametrizado
     * @param id ID do post
     * @param owner_id ID do utilizador que criou o post
     * @param score Pontuação do post
     * @param cc Quantidade de comentários
     * @param date Data de criação do post
     * @param parentID ID da pergunta a qual a reposta está vinculada
     */
    public Answer(long id, long owner_id, long score, long cc, LocalDate date, long parentID){

        super(id, owner_id, score, cc, date);
        this.parentID = parentID;
    }

    /**
     * Construtor de cópia
     * @param object Resposta a ser copiada
     */
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