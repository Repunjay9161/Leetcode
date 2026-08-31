class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> vec;
        unordered_map<char, char> arr;
        int n=s.length();
        int m = t.length();
        for(int i=0;i<m;i++){
            if(vec[s[i]]!=0&&vec[s[i]]!=t[i]){
                return false;
            }
         vec[s[i]]=t[i];
          if(arr[t[i]]!=0&&arr[t[i]]!=s[i]){
                return false;
            }
         arr[t[i]]=s[i];

        }

        return true;
    }
};