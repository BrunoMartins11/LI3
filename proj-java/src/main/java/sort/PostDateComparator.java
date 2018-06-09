package main.java.sort;

import java.time.LocalDate;
import java.util.Comparator;
import main.java.common.Post;


public class PostDateComparator implements Comparator<Post> {
    
    public int compare(Post p1, Post p2){
        if(p1.getDate().isBefore(p2.getDate())) {
            return 1;
        } else {
            return -1;
        }
    }

}