class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
       int i=0;
       int j=nums.size()-1;
       while(i<=j){
       int mid=j+(i-j)/2;
        int ele=j-mid;
        if(ele%2==0){
            if(mid>0&&nums[mid]==nums[mid-1]){
                j=mid-2;
            }
            else if(mid<nums.size()-1&&nums[mid]==nums[mid+1]){
                i=mid+2;
            }
             else{
                return nums[mid];
            }
        }
        else{
             if(mid>0&&nums[mid]==nums[mid-1]){
                i=mid+1;
            }
            else if(mid<nums.size()-1&&nums[mid]==nums[mid+1]){
                j=mid-1;
            }
            else{
                return nums[mid];
            }
        }
       }
       return -1;  
    }
};