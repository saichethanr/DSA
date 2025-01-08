package slidingWindow;

public class sumofsubarrayranges {
    public static void main(String [] args){

    
    }


    public long subArrayRanges(int[] nums) {
          int l = 0;
          int r =0;

          int min = Integer.MAX_VALUE;
          int max = Integer.MIN_VALUE;

          while(r<nums.length){              
              min = Integer.min(nums[r],min);
              max = Integer.max(nums[r], max);

              
              r++;
          }
    }

}
