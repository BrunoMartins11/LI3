package main.java.engine;

import java.util.ArrayList;
import java.util.List;

public class Question extends Post {

    private String title;
    private List<Tags> tags;
    private List<Answer> answers;

    public Question(){
        super();
        this.title = "";
        this.answerCount = 0;
        this.tags = new ArrayList<>();
        this.answers = new ArrayList<>();
    }

    public Question(long id, long owner_id, long score, int cc, LocalDateTime date, 
                    String title, List<Tag> tags, List<Answer> answers){

        super(id, owner_id, score, cc, date);
        this.title = title;
        this.answerCount = answerCount;
        
        this.tags = new ArrayList<>();
        this.tags.addAll(tags);
        
        this.answers = new ArrayList<>();
        this.answers.addAll(answers);
    }

    public Question(Question object){
        super(object);
        this.title = object.getTitle();

        this.tags = new ArrayList<>();
        this.tags.addAll(object.getTags());
        
        this.answers = new ArrayList<>();
        this.answers.addAll(object.getAnswers());
    }

    public String getTitle(){
        return this.title;
    }

    public int getAnswerCount(){
        return this.answers.size();
    }

    public List<String> getTags(){
        return this.tags;
    }

    public List<Answer> getAnswers(){
        return this.answers;
    }

    public void setTtitle(String title){
        this.title = title;
    }

    public setTags(List<Tag> tags){
        this.tags.addAll(tag);
    }

    public void setAnswers(List<Answer> answers){
        this.answers.addAll(answers);
    }

    public void addTag(Tag tag){
        this.tags.add(tag);
    }

    public void addAnswer(Answer answer){
        this.answers.add(answer);
    }

}