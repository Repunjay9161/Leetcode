class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
      if(need1 ==0 && need2 ==0) return 0;
       long long c1 =cost1;
       long long c2 =cost2;
       long long cB =costBoth;
       long long n1=need1;
       long long n2=need2 ;      
      long long ans= INT_MAX;
      long long option1 =(c1*n1)+(c2*n2);
      long long option2 = 0;
      long long option3 =0;
      int diff = abs(n1-n2);
      if(n1>n2){
      option3 = (cB*n2)+(diff*c1);
      }
      else{
         option3 = (cB*n1)+(diff*c2);
      }
      if(need1>need2) option2 = cB*n1;
      else option2 = costBoth*n2;
      ans= min(option1 ,option2); 
      return min(ans,option3);
    }
};