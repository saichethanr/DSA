import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class wordsubsets {
    public static void main(String[] args) {
        
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
            List<HashMap<Character,Integer>> lst1 = new ArrayList<>();
            List<HashMap<Character,Integer>> lst2 = new ArrayList<>();

            for (String w1 : words1) {
                HashMap<Character, Integer> freqMap = new HashMap<>();
                for (char c : w1.toCharArray()) {
                    freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
                }
                lst1.add(freqMap);
            }
    

            for (String w2 : words2) {
                HashMap<Character, Integer> freqMap = new HashMap<>();
                for (char c : w2.toCharArray()) {
                    freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
                }
                lst2.add(freqMap);
            }

        List<String> result = new ArrayList<>();

        for (int i = 0; i < words1.length; i++) {
            boolean isUniversal = true;

            for (HashMap<Character, Integer> freqMap2 : lst2) {
                for (Map.Entry<Character, Integer> entry : freqMap2.entrySet()) {
                    char c = entry.getKey();
                    int freqInLst2 = entry.getValue();
                    int freqInLst1 = lst1.get(i).getOrDefault(c, 0);

                    if (freqInLst1 < freqInLst2) {
                        isUniversal = false;
                        break;
                    }
                }
                if (!isUniversal) break;
            }

            if (isUniversal) {
                result.add(words1[i]);
            }
        }

        return result;

            
    }
}
