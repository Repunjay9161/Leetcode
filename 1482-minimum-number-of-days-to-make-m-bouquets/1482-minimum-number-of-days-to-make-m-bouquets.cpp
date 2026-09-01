class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
      int n =nums.size();
      long long total = 1LL * k * m;
      if(total>n)return -1;
      int mini= *min_element(nums.begin(),nums.end());
      int maxi = *max_element(nums.begin(),nums.end());
       int low = mini;
       int high = maxi;
       int result =-1;
       while(low<=high){
        int mid = (low+high)/2;
        if(possible(nums,mid,m,k)){
            result = mid;
            high =mid-1;
        }
        else{
            low=mid+1;
        }
       }
     return result;
    }
    private:
        bool possible(vector<int>& nums,int mid, int m, int k ){
            int c=0;
            int bouquets=0;
            for(int num : nums){
                if(num<=mid){
                  c++;
                  if(c==k){
                    bouquets++;
                    c=0;
                  }
                }
                else{
                    c=0;
                }
            }
            return bouquets>=m;
        }
};