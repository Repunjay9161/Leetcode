class Solution {
public:
      void  answer(vector<int>& nums,int j, vector<vector<int>> &result){
            if(j==nums.size()){
                result.push_back(nums);
                return;
            }
            for(int i=j;i<nums.size();i++){
            swap(nums[j],nums[i]);
            answer(nums,j+1,result);
            swap(nums[j],nums[i]);
            }
        }
      public:
    vector<vector<int>> permute(vector<int>& nums) {
   vector<vector<int>> result;
     answer(nums,0,result);
     return result;
    
    }
};