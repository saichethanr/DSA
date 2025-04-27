package array;

import java.util.ArrayList;
import java.util.List;

public class pivotdivide {
    public static void main(){
        
    }



    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> bef = new ArrayList<>();
        int piv_cnt=0;
        List<Integer> after = new ArrayList<>();


        for(int i=0;i<nums.length;i++){
            if(nums[i]<pivot){
                bef.add(nums[i]);
            } else if (nums[i]>pivot) {
                after.add(nums[i]);
            }else{
                piv_cnt++;
            }
        }

        List <Integer> result = new ArrayList<>(bef);

        while(piv_cnt>0){
            result.add(pivot);
            piv_cnt--;
        }
        result.addAll(after);

            
    }
}
