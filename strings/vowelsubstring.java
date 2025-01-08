import java.util.HashSet;
import java.util.Set;

public class vowelsubstring {
    public int countVowelSubstrings(String word) {
        HashSet<Character> vowels = new HashSet<>();
            vowels.add('a');
            vowels.add('e');
            vowels.add('i');
            vowels.add('o');
            vowels.add('u');
    
            int cnt = 0;
            int start = 0; 
    
            for (int end = 0; end < word.length(); end++) {
                HashSet<Character> cv = new HashSet<>();
    
                for (int j = end; j < word.length(); j++) {
                    char c = word.charAt(j);
                    if (!vowels.contains(c)){
                        break;
                    } 
    
                    cv.add(c);
    
                    if (cv.size() == 5) {
                        cnt++;
                    }
                }
            }
    
            return cnt;
        }
}
