class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int >> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string curr =q.front().first;
            int level= q.front().second;
            q.pop();
               if (curr == endWord) return level;
             for(int i =0; i<curr.size();i++){
                char original =curr[i];
                for(char ch ='a'; ch <= 'z';ch++){
                    curr[i]=ch;
                    if(st.find(curr)!=st.end()){
                        st.erase(curr);
                        q.push({curr , level+1});
                    }
                }
                curr[i] = original;
             }
        }
        return 0;
    }
};