import java.util.HashMap;
import java.util.Map;

public class canconstruct {
    public static void main(String[] args) {
        String s =  "leetcode";
        int k = 2;
        boolean flag = canConstruct(s,k);
        System.out.println(flag);
    }

    public static boolean canConstruct(String s, int k) {
          HashMap <Character , Integer> map = new HashMap<>();
          for(Character c : s.toCharArray()){
              map.put(c, map.getOrDefault(c, 0)+1);
          }
          int evenOccChar =0;
          int oddOccChar =0;
          

          for(Map.Entry<Character,Integer> entry : map.entrySet()){
              if(entry.getValue()%2==0){
                evenOccChar++;
              }
              else{
                oddOccChar++;
              }
          }
          
        if(k>s.length() &&  k<oddOccChar){
            return false;
        }

        return true;
    }
}
