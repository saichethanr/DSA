package prefixsum;

import java.util.ArrayList;
import java.util.List;

public class oprtomoveballs {
    public static void main(String [] args){
      String boxes  = "110";
      minOperations(boxes);
    }

    public static int[] minOperations(String boxes) {
        List <Integer> lst =  new ArrayList<>();
        int [] result  = new int[boxes.length()];
        char [] box = boxes.toCharArray();
        for(int i=0;i<boxes.length();i++){
             if(box[i]=='1'){
                lst.add(i);
             }
        }

      System.out.println(lst);
    return result;
    }
}
