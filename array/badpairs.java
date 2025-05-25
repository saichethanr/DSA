import java.util.HashMap;
import java.util.Map;

public class badpairs {

    //TLE
    public long countBadPairs(int[] nums) {
        long ans = 0;
        for(int i=0;i<nums.length-1;i++){
            for(int j=i+1;j<nums.length;j++){
                if(j-i != nums[j] - nums[i]){
                    ans++;
                }
            }
        }

        return ans;
    }


    public long countsolve(int [] nums){
        long ans=0;
        long totalpairs =0L;
        long goodpairs = 0L;
        Map <Integer,Long> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int diff = nums[i]-i;
            long countkey = map.getOrDefault(diff, 0L);
            goodpairs+=countkey;
            map.put(diff, countkey+1);
        }

        totalpairs = ((long) nums.length * (nums.length - 1)) / 2;
        ans = totalpairs-goodpairs;
        return ans;
    }
}
