class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      int maxi=INT_MIN;
      int result=INT_MAX;
      int ans=0;
      int n=nums.size();
      vector<int> vec(n);
      vec[n-1]=nums[n-1];
      for(int i=n-2;i>=0;i--){
        vec[i]=min(nums[i],vec[i+1]);
      }
      for(int i = 0; i<n; i++){
        maxi =max(nums[i],maxi);
           ans =maxi-vec[i];
           if(ans<=k){
            result = min(result,i);
           }
      }
      if(result==INT_MAX) return -1;
     else return result;

    }
};