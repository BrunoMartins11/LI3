package main.java.sort;

import main.java.common.Pair;
import java.util.Comparator;

public class PairSecondComparator implements Comparator<Pair<Long,Long>> {
    
    public int compare(Pair<Long,Long> pair1, Pair<Long,Long> pair2) {
        return -Long.compare(pair1.getSnd(), pair2.getSnd());
    }
}
