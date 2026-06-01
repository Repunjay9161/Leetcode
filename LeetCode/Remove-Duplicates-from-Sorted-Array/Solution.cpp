1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int i=0;
5      int c=1;
6      for(int j=1;j<nums.size();j++){
7        if(nums[i]!=nums[j]){
8            nums[c]=nums[j];
9            i=j; 
10            c++;
11        }
12      } 
13      return c; 
14    }
15};