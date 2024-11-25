//import java.util.HashMap;
//
//class smallest_value_of_rearranged_number {
//    public boolean longestNiceSubstring(String s) {
//        String lower = "";
//        HashMap <Character,Integer> map1 = new HashMap<>();
//        HashMap <Character,Integer> map2 = new HashMap<>();
//        for(int i=0;i<s.length();i++){
//            if(s.charAt(i).isLowerCase()){
//                lower+=s.charAt(i);
//                map1.put(s.charAt(i),1);
//            }
//            else{
//                map2.put(s.charAt(i),1);
//            }
//        }
//
//        for(int i=0;i<lower.length();i++){
//           if(map2.containsKey(Character.toUpperCase(lower.charAt(i)))){
//                map1.remove(lower.charAt(i));
//           }
//        }
//
//        int size = map1.size();
//        if(size==0){
//            return true;
//        }
//        return false;
//    }
//}