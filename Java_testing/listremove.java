package Java_testing;

import java.util.ArrayList;
import java.util.List;

public class listremove {
    public static void main(String [] args){
        List<Integer> arr = new ArrayList<>();
        arr.add(3);
        arr.add(8);
        arr.add(10);
        arr.remove(1);
        System.out.println(arr);
    }
}
