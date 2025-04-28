package math;

public class solvequerypalindrome {
    public static void main(String[] args) {
        int [] queries = {1, 2, 3, 4, 5};
        int intLength = 3;
        solvequerypalindrome obj = new solvequerypalindrome();
        long[] result = obj.kthPalindrome(queries, intLength);
        for (long num : result) {
            System.out.print(num + " ");
        }
    }
    public long[] kthPalindrome(int[] queries, int intLength) {
        int n = queries.length;
        long[] ans = new long[n];
        
        int halfLength = (intLength + 1) / 2;
        long start = (long) Math.pow(10, halfLength - 1);
        
        for (int i = 0; i < n; i++) {
            long firstHalf = start + queries[i] - 1;
            String firstHalfStr = Long.toString(firstHalf);
            
            // Check if the length exceeds
            if (firstHalfStr.length() > halfLength) {
                ans[i] = -1;
                continue;
            }
            
            String secondHalf = new StringBuilder(firstHalfStr.substring(0, intLength / 2)).reverse().toString();
            String palindromeStr = firstHalfStr + secondHalf;
            ans[i] = Long.parseLong(palindromeStr);
        }
        
        return ans;
    }
}
