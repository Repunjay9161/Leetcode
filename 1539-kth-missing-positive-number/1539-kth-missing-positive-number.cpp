class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int n=arr.size();
      int missing = arr[n-1]-n;
       int start = 0 ;
        int end= n-1;
      if(missing<k){
        return k-missing+arr[n-1];
      }
      else{
         while(start<=end){
            int mid= start+ (end-start)/2;
            int miss = arr[mid]-(mid+1);
            if(miss<k){
              start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
      }
       return start+k;       
    }
};