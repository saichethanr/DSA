package Restart;

import java.lang.reflect.Array;
import java.util.*;

public class most_beautiful_item_for_each_query {
    public static void main(String [] args){
      int [][] items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
      int [] queries = {1,2,3,4,5,6};
        int [] ans = maximumBeauty(items,queries);
        for(int i : ans){
            System.out.println(i);
        }
    }
    public static int[] maximumBeauty(int[][] items, int[] queries) {
        int [] ans = new int[queries.length];
        Arrays.sort(items, Comparator.comparingInt(row -> row[0]));
        List <Integer> list = new ArrayList<>();
        int prevbeauty = items[0][0];
        for(int q : queries){
            for(int []i : items){
                  if(q<i[0]){
                      break;
                  }
                  prevbeauty = Math.max(prevbeauty,i[1]);
            }
            list.add(prevbeauty);
        }
        ans = list.stream().mapToInt(Integer::intValue).toArray();

        return ans;


    }
}
