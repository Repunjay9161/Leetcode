class Solution {
public:
    int minMoves(vector<int>& nums) {
       int maxEle= *max_element(nums.begin(), nums.end());
       long long ans =0;
    //    sort(nums.begin(), nums.end());
       for(int num : nums){
             ans += (maxEle - num);
       } 
       return ans;
    }
};