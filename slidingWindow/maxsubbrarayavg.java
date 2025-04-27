package slidingWindow;

public class maxsubbrarayavg {
    public double findMaxAverage(int[] nums, int k) {
        int l=0;
        int r=0;
        double ans = Integer.MIN_VALUE;
        int sum =0;
        while(r<nums.length){
            sum+=nums[r];
            if((r-l+1)==k){
                ans = Math.max(ans,(double) sum / (r-l+1));
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
}
