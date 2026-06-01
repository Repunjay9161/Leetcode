1class Solution {
2public:
3    void rotate(vector<vector<int>>& m) {
4     int n=m.size();
5    for(int i=0;i<n;i++){
6        for(int j=i;j<n;j++){
7            swap(m[i][j], m[j][i]);
8        }
9    }
10    for(auto &row:m) reverse(row.begin(), row.end());   
11    }
12};