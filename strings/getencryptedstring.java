public class getencryptedstring {
    public static void main(String[] args) {
        String s = "dart";
        int k=3;
        String ans =getEncryptedString(s,k);
        System.out.println(ans);    
    }

    public static String getEncryptedString(String s, int k) {
          String ans = "";
          char str [] = new char[s.length()];
          str = s.toCharArray();
          for(int i=0;i<s.length();i++){
             ans += str[(i+k)%s.length()];
          }
          return ans;
    }
}
