class Solution {
    public int[] buildArray(int[] nums) {
        int [] arr = new int[nums.length];
        int i=0;
        for(int num: nums){
            if(i>=nums.length){
                break;
            }
            arr[i] = nums[num];
            i++;
        }

        return arr;
    }
}