public class isprefixorsufixcount {
    public static void main(String[] args) {
        
    }
    public int countPrefixSuffixPairs(String[] words) {
        int cnt=0;
        for(int i=0;i<words.length-1;i++){
            for(int j=i+1;j<words.length;j++){
                if(words[j].startsWith(words[j]) && words[i].endsWith(words[j]) && !words[i].equals(words[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
