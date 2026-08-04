class Solution {
    public int largestAltitude(int[] gain) {

        int size = gain.length;
        int [] prefixSum = new int[size + 1];

        prefixSum[0] = 0;
        int maximum = 0;

        for(int i=1; i<size+1; i++){
            prefixSum[i] = prefixSum[i-1] + gain[i-1];
            if(prefixSum[i] > maximum){
                maximum = prefixSum[i];
            }
        }
        return maximum;
    }
}