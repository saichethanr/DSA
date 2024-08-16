
class seniorcitizens {
    public int countSeniors(String[] details) {
        int cnt=0;
        for(String det : details){
            String age = "";
            age+=det.charAt(11);
            age+=det.charAt(12);

            int a = Integer.parseInt(age);
            System.out.println(a);
            if(a>60){
                cnt++;
            }
        }
        return cnt;
    }
}