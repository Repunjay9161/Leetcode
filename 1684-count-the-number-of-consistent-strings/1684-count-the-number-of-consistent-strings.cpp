class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        int count=0;
        for(int i=0; i<words.size(); i++ ){
            string s=words[i];
            for(char ch : s){
                if(allowed.contains(ch)){
                    c++;
                }
            }
            if(c==s.length()){
                count++;
            }
            c=0;
        }
        return count;
    }
};