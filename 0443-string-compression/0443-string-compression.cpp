class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();

        int i = 0;
        int j = 0;

        while(i < n){

            char current = chars[i];

            int count = 0;

            while(i < n && chars[i] == current){
                i++;
                count++;
            }

            chars[j] = current;
            j++;

            if(count > 1){
                string str = to_string(count);

                for(auto it : str){
                    chars[j] = it;
                    j++;
                }
            }
        }
        return j;
    }
};