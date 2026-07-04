class Solution {
public:
    double myPow(double x, int n) {
     double r=1;
     if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    if(n%2==0){
     r = pow(x*x , n/2);
    }
    else{
        r = pow(x , n);
    }
     return r;
    }
};