class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n =arr.size();
        if(n<3) return false;
       int i=1;
       while(i<n){
        if(arr[i]<=arr[i-1]){
            return false;
        }
        else if(arr[i]>arr[i+1]){
            break;
        }
        i++;
       }
       if(i==n-1) return false;
       while(i<n-1){
        if(arr[i]<=arr[i+1]) return false;
        i++;
       }
       return true;
    }
};