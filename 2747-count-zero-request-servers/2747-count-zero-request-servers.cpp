class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
       int m = queries.size();
        vector<int> ans(m, 0);
        vector<pair<int, int>> indexedQueries(m);
        for (int i = 0; i < m; ++i) {
            indexedQueries[i] = {queries[i], i};
        }
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        sort(indexedQueries.begin(), indexedQueries.end());
        
        int left = 0, right = 0;
        int l_logs = logs.size();
        unordered_map<int, int> serverCount;
        
        for (int i = 0; i < m; ++i) {
            int qTime = indexedQueries[i].first;
            int qIndex = indexedQueries[i].second;
            int windowStart = qTime - x;
            int windowEnd = qTime;
            while (right < l_logs && logs[right][1] <= windowEnd) {
                serverCount[logs[right][0]]++;
                right++;
            }
            while (left < l_logs && logs[left][1] < windowStart) {
                serverCount[logs[left][0]]--;
                if (serverCount[logs[left][0]] == 0) {
                    serverCount.erase(logs[left][0]);
                }
                left++;
            }
   
            ans[qIndex] = n - serverCount.size();
        }
        
        return ans; 
    }
};