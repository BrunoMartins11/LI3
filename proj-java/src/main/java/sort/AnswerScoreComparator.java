package main.java.sort;


import common.Answer;

import java.util.Comparator;

public class AnswerScoreComparator implements Comparator<Answer> {

    public int compare(Answer asw1, Answer asw2){
        return -Long.compare(asw1.getScore(), asw2.getScore());
    }
}