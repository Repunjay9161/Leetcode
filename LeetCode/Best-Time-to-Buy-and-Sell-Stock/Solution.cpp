1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4       int minp=INT_MAX, profit=0;
5    for(int p:prices){
6        minp=min(minp,p);
7        profit=max(profit,p-minp);
8    }
9    return profit;  
10    }
11};