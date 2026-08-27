class Solution {
public:
    int shipWithinDays(vector<int>& weight, int days) {
    int start = *max_element(weight.begin(),weight.end());
    int end =0;
    for(int i=0;i<weight.size();i++){
     end =end+weight[i];
    }
    int minval = INT_MAX;
    while(start<=end){
        int mid = start +(end -start)/2;
        int sum =0;
        int c=1;
        for(int i=0;i<weight.size();i++){
            sum=sum+weight[i];
            if(sum>mid){
                sum=weight[i];
                c++;
            }
        }
            if(c>days){
                start=mid+1;
            }
            else{
                end = mid-1;
                minval =min(minval,mid);
            }
        }
        return minval;
    }
};