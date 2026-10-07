class Solution {
    public char findTheDifference(String s, String t) {

        HashMap<Character,Integer> mpp = new HashMap<>();

        int n1 = s.length();
        int n2 = t.length();

        for(int i=0; i<n1; i++){
            char c = s.charAt(i);
            mpp.put(c, mpp.getOrDefault(c,0)+1);
        }
        for(int i=0; i<n2; i++){
            char c = t.charAt(i);
            mpp.put(c, mpp.getOrDefault(c,0)-1);
        }

        for(Character key : mpp.keySet()){
            if(mpp.get(key) == -1){
                return key;
            }
        }
        return '\0';
    }
}