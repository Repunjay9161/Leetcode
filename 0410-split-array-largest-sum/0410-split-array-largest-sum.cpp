class Solution {
public:
 int countSub(vector<int>& nums, int mid){
         int c=1;
        int sum=0;
        for(int num : nums){
             if (sum + num <=mid) {
                sum += num;
            } else {
               c++;
                sum = num;
            }
        }
        return c;
   }
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(), nums.end());
       int high=0;
       for(int num : nums){
          high = high+ num;
       }
       while(low<=high){
        int mid = low+(high-low)/2;
        int sub = countSub(nums,mid);
        if(sub>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }
       return low;
    }
};