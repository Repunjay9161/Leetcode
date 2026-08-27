class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
     auto maxele = max_element(nums.begin(),nums.end());
     int end = *maxele;
     int start = 1;
     int minval =INT_MAX;
     while(start<=end){
        int mid = start + (end - start) / 2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid!=0){
                sum = sum + nums[i]/mid+1;
            }
            else{
                sum = sum +nums[i]/mid;
            }
        }
            if(sum>threshold){
              start = mid + 1;
            }
            else if(sum<=threshold){
                minval=min(minval,mid);
                end = mid - 1; 
            }
     }
     return minval;
    }
};