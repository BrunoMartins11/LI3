package common;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Question extends Post {

    private String title;
    private List<String> tags;
    private List<Long> answers;

    public Question(){
        super();
        this.title = "";
        this.tags = new ArrayList<>();
        this.answers = new ArrayList<>();
    }

    public Question(long id, long owner_id, long score, int cc, LocalDate date,
                    String title, List<String> tags, List<Long> answers){

        super(id, owner_id, score, cc, date);
        this.title = title;
        
        this.tags = new ArrayList<>();
        for (String t : tags)
            this.tags.add(t);
        
        this.answers = new ArrayList<>();
        for (Long a : answers)
            this.answers.add(a);
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
        return new ArrayList<>(this.tags);
    }

    public List<Long> getAnswers(){
        return new ArrayList<>(this.answers);
    }

    public void setTtitle(String title){
        this.title = title;
    }

    public void setTags(List<String> tags){
        this.tags.addAll(tags);
    }

    public void setAnswers(List<Long> answers){
        this.answers.addAll(answers);
    }

    public void addTag(String tag){
        this.tags.add(tag);
    }

    public void addAnswer(Long answer){
        this.answers.add(answer);
    }

    public boolean containsTag(String tag){
        return this.tags.contains(tag);
    }

    public Question clone(){
        return new Question(this);
    }

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