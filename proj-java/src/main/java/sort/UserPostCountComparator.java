package sort;


import common.User;

import java.util.Comparator;

public class UserPostCountComparator implements Comparator<User> {
    @Override
    public int compare(User o1, User o2) {
        return -Double.compare(o1.getPostCount(),o2.getPostCount());
    }
}
