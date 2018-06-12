package common;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Question extends Post {

    /**
     * Título da pergunta
     */
    private String title;

    /**
     * Tags da pergunta
     */
    private List<String> tags;

    /**
     * ID's das respostas a esta pergunta
     */
    private List<Long> answers;


    /**
     * Construtor vazio
     */
    public Question(){
        super();
        this.title = "";
        this.tags = new ArrayList<>();
        this.answers = new ArrayList<>();
    }


    /**
     * Construtor parametrizado
     * @param id ID do post
     * @param owner_id ID do utilizador que criou o post
     * @param score Pontuação do post
     * @param cc Quantidade de comentários
     * @param date Data de criação do post
     * @param title Título do post
     * @param tags Tags do post
     */
    public Question(long id, long owner_id, long score, long cc, LocalDate date,
                    String title, String tags){//Sai daqui a lista de answers, porque so adiciono nas answers

        super(id, owner_id, score, cc, date);
        this.title = title;
        
        this.tags = this.filterTags(tags);
        
        this.answers = new ArrayList<>();

    }

    /**
     * Construtor de cópia
     * @param object Pergunta a ser copiada
     */
    public Question(Question object){
        super(object);
        this.title = object.getTitle();

        this.tags = new ArrayList<>();
        this.tags.addAll(object.getTags());
        
        this.answers = new ArrayList<>();
        this.answers.addAll(object.getAnswers());
    }

    /**
     * Parser das tags extraídas do xml no formato <tag1><tag2>...
     * @param tags String com as tags
     * @return Lista com as tags
     */
    public List<String> filterTags(String tags){
        String finString = Pattern.quote("<") + "(.*?)" + Pattern.quote(">");
        Pattern pat = Pattern.compile(finString);
        Matcher lig = pat.matcher(tags);
        List<String> tmp = new ArrayList<>();
        while(lig.find()){
            String textBetween = lig.group(1);
            tmp.add(textBetween);
        }
        return tmp;
    }

    /**
     * Retorna o titulo da pergunta
     * @return Titulo
     */
    public String getTitle(){
        return this.title;
    }

    /**
     * Retorna o numero de respostas a uma pergunta
     * @return numero de respostas
     */
    public int getAnswerCount(){
        return this.answers.size();
    }

    /**
     * Retorna as Tags de uma pergunta
     * @return Lista de Tags
     */
    public List<String> getTags(){
        return new ArrayList<>(this.tags);
    }

    /**
     * Retorna os IDs das respostas as perguntas
     * @return Lista de IDs das respostas
     */
    public List<Long> getAnswers(){
        return new ArrayList<>(this.answers);
    }

    /**
     * Adiciona um id de uma resposta à lista de respostas
     * @param answer Id da respostas
     */
    public void addAnswer(Long answer){
        this.answers.add(answer);
    }

    /**
     * Verifica se uma Questão tem uma Tag
     * @param tag Tag a verificar
     * @return Boolean
     */
    public boolean containsTag(String tag){
        return this.tags.contains(tag);
    }

    /**
     * Clona uma Questão
     * @return Questão
     */
    public Question clone(){
        return new Question(this);
    }

    /**
     * Verifica se duas questões são iguais
     * @param o Questão a comparar
     * @return Boolean
     */
    public boolean equal(Object o){

        if (super.equals(o)){
            Question q = (Question) o;
            return (this.getAnswers().equals(q.getAnswers()) && this.getTags().equals(q.getTags()) &&
                    this.getTitle().equals(q.getTitle()));
        }
        
        else 
            return false;
    }
        
}