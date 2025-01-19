import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

public class anagramsteps {
    public static void main(String [] args){
         List <Integer> lst = new ArrayList<>();
        lst.add(2);
        lst.add(5);
        lst.add(7);
        lst.add(9);
        lst.add(19);
        lst.add(20);
        lst.add(22);

        List <Integer> ans = lst.stream().filter(num -> num%2==0).collect(Collectors.toList());
        for(Integer a : ans){
            System.out.println(a);
        }
    }
}
