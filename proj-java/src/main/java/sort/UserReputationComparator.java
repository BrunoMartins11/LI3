package sort;


import common.User;

import java.util.Comparator;

public class UserReputationComparator implements Comparator<User> {

    public int compare(User usr1, User usr2) {
        return -Long.compare(usr1.getReputation(), usr2.getReputation());
    }
}
