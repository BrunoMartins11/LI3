package sort;

import common.Post;

import java.time.LocalDate;
import java.util.Comparator;


public class PostDateComparator implements Comparator<Post> {
    
    public int compare(Post p1, Post p2){
        return p1.getDate().compareTo(p2.getDate());
    }

}