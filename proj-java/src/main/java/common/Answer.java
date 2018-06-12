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

    /**
     * Retorna o ID da Questão a que esta Resposta estám associada
     * @return ID de Questão
     */
    public long getParentID(){
        return this.parentID;
    }

    /**
     * Clona uma Resposta
     * @return Resposta
     */
    public Answer clone(){
        return new Answer(this);
    }

    /**
     * Verifica se uma Resposta é igual a outra
     * @param o Resposta
     * @return Boolean
     */
    public boolean equals(Object o){
       
        if (super.equals(o)){
            Answer ans = (Answer) o;
            return (this.getParentID() == ans.getParentID());
        }
        
        else
            return false;
    }
}