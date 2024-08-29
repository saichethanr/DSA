class Solution {
    public String removeTrailingZeros(String num) {
        Integer l = num.length();
        String ans = "";
        for(int i=l-1;i>=0;i--){
            if(num.charAt(i)!='0'){
                ans = num.substring(0,i+1);
                break;
            }
        }
        return ans;
    }
}