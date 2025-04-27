package math;

public class querypalindrome {

        public long[] kthPalindrome(int[] queries, int intLength) {
            int start = (int) Math.pow(10, intLength - 1);
            int end = (int) Math.pow(10, intLength) - 1;
            System.out.println(start);
            System.out.println(end);
            long[] ans = new long[queries.length];
            int ind =1;
            int k=0;
            for (int i = start; i <= end; i++) {
                if(k>=queries.length){
                    break;
                }
                if(isPalindrome(i)){
                    if(ind == queries[k]){
                        ans[k] = i;
                        k++;
                    }
                    ind++;
                }
                    
                }
    
            
            return ans;
        }
    
        public boolean isPalindrome(int num){
            String str = String.valueOf(num);
            String rev = new StringBuilder(str).reverse().toString();
            if(str.equals(rev)){
                return true;
            }
            return false;
        }
    
    
}
