class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if(B.size()<A.size()) {
            return findMedianSortedArrays(B,A);
        }
     int n =A.size();
     int m =B.size();
      int i=0;
      int j=n;
      while(i<=j){
         int cut1= (i+j)/2;
      int cut2 = ((n+m+1)/2)-cut1;
      int l1;
      int l2;
      int r1;
      int r2;
      if(cut1==0){
         l1=INT_MIN;
      }
      else    l1 =A[cut1-1];
       if(cut2==0) l2=INT_MIN; 
      else l2 = B[cut2-1];

      if(cut1>=n) r1=INT_MAX;
       else r1=A[cut1];

       if(cut2>=m) r2=INT_MAX;
      else r2 =B[cut2];

      if(l1<=r2&&l2<=r1){
        if((n+m)%2==0){
            return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else{
            return max(l1,l2);
        }
      }
        else if(l1>r2){
            j=cut1-1;
        }
      else i =cut1+1;
      }
       return 0.0;
        }
};