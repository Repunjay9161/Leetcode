class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
      int n =num1.length();
      int m=num2.length();
    vector<int> result(n+m,0);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int x=num1[i]-'0';
            int y =num2[j]-'0';
            int mul =x*y;

            int posHigh =i+j+1;
            int poslow =i+j;
            
            int sum =mul + result[posHigh];
             
             result[posHigh] =sum%10;
             result[poslow] += sum/10;
        }
    }
     string ans= ""; 
     int i =0;
       while(i<result.size()&&result[i]==0){
        i++;
       }
       while(i<result.size()){
        ans +=result[i]+'0';
        i++;
       }
       return ans;
    }
};