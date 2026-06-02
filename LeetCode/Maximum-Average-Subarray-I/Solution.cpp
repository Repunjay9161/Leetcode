1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4       double currentsum = 0;
5        for (int i = 0; i < k; i++) {
6            currentsum += nums[i];
7        }
8        double maxsum = currentsum;    
9        for (int i = k; i < nums.size(); i++) {   
10            currentsum += nums[i] - nums[i - k] ; 
11            maxsum = max(maxsum, currentsum);
12        }
13        return maxsum / k; 
14    }
15};