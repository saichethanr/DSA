package prefixsum;

public class shufflestrings {
    public static  void main(String [] args){
        String s = "abc";
        int[][] shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};

        String ans = letter(s,shifts);
        System.out.println(ans);

    }

    public static String shiftingLetters(String s, int[][] shifts) {
        for(int [] arr : shifts){
            String str ="";
            for(char c : s.toCharArray()){
                  int diff = arr[1] - arr[0];

                  if(arr[2]==1){
                      c = (char) ('a' + (c - 'a' + diff + 26) % 26);
                  }
                  else{
                      c = (char) ('a' + (c - 'a' - diff + 26) % 26);
                  }
                  str += c;

            }

            s=str;
        }
        return s;
    }

    public static String letter(String s, int[][] shifts) {
        char [] chars = s.toCharArray();
        for(int [] arr : shifts){

              int start = arr[0];
              int end = arr[1];
              int direction = arr[2];
              if(direction==0){
                  direction=-1;
              }

              for(int i=start;i<=end;i++){
                   chars[i] = (char) ('a' + (chars[i] - 'a' + direction + 26) % 26);
              }
        }

        return new String(chars);
    }


    public static String optimise(String s, int[][] shifts) {
        char [] chars = s.toCharArray();
        int [] a = new int[s.length()+1];
        for(int [] arr : shifts){

            int start = arr[0];
            int end = arr[1];
            int direction = arr[2];
            if(direction==0){
                direction=-1;
            }

            a[start] += direction;
            a[end+1] -= direction;
        }

        for(int i=1;i<s.length();i++){
            a[i] += a[i-1];
        }

        char [] result = s.toCharArray();
        for(int i=0;i<s.length();i++){
             int shift = a[i]%26;
             result[i] = (char) ('a' + (result[i] - 'a' + shift + 26) % 26);
        }

        return new String(result);
    }
}
