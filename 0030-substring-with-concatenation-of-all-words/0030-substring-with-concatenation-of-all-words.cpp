class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
     vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.length();

        unordered_map<string, int> wordCount;
        for (const string& w : words) {
            wordCount[w]++;
        }

        // Loop 'wordLen' times to check all possible starting offsets
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0;

            while (right + wordLen <= n) {
                // Extract a full word chunk at once
                string sub = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.count(sub)) {
                    seen[sub]++;
                    count++;

                    // If we have more instances of this word than allowed, shrink from the left
                    while (seen[sub] > wordCount[sub]) {
                        string leftSub = s.substr(left, wordLen);
                        seen[leftSub]--;
                        count--;
                        left += wordLen;
                    }

                    // If the valid window size matches the total words required
                    if (count == numWords) {
                        ans.push_back(left);
                    }
                } else {
                    // Reset window if an invalid word is hit
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ans;
    }
};