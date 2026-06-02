1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxsum = INT_MIN, sum = 0;
5        for (int i = 0; i < nums.size(); i++) {
6            sum += nums[i];
7            maxsum = max(sum, maxsum);
8            if (sum < 0) {
9                sum = 0;
10            }
11        }
12        return maxsum;
13    }
14};
15