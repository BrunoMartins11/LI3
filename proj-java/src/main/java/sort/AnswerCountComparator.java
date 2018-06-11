package sort;


import common.Question;

import java.util.Comparator;

public class AnswerCountComparator implements Comparator<Question> {

    public int compare(Question o1, Question o2) {
        return Integer.compare(o1.getAnswerCount(),o2.getAnswerCount());
    }
}
