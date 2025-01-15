package array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class maximumgap {
    public static void main(String[] args) {
        
    }
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        
        int l=0;
        int r=1;
        int max = Integer.MIN_VALUE;
        if(nums.length<2){
            return 0;
        }
        while(r<nums.length){
            int diff = nums[r] - nums[l];
            max = Math.max(max, diff);
            r++;
            l++;
        }
        return max;
    }
    public int solve(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        List<Integer> lst = new ArrayList<>();
        int ans = Integer.MIN_VALUE;
        for(int n:nums){
             lst.add(n);
             max = Integer.max(max, n);
             min = Integer.min(min, n);
        }
        int prev = 0;
        for(int i=min;i<=max;i++){
             if(lst.contains(i)){
                  int diff = i - prev;
                  ans = Math.max(ans, diff);
                  prev = i;
             }
        }

        return ans;
    }
}
