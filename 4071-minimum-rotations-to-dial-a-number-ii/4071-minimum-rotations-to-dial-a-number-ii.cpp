class Solution {
public:
    int minRotations(int n, string s) {
    // int gap1=0;
    // int lastRot=0;
    // int acutRoat = 0;
    // if(s[n-1]-'0'>5){
    //     lastRot = 10-(s[n-1]-'0');
    // }
    // else{
    //     lastRot = (s[n-1]-'0');
    // }
    //     if(s[0]=='0'){
    //      acutRoat =0;
    //     }
    //     else if(s[0]<='5'){
    //        acutRoat= s[0]-'0';
    //     }
    //     else{
    //         acutRoat=10-(s[0]-'0');
    //     }
    //     if(n==1) return acutRoat;
    //     for(int i =1;i<n; ++i){
    //         int j=i-1;
    //         if(acutRoat>lastRot){
    //             reverse(s.begin()+j,s.end());
    //             break;
    //         }
    //         int gap1 = 0;
    //         int gap=0;
    //         if(s[i]>s[i-1]){
    //             gap=s[i]-s[i-1];
    //                      if(gap>5){
    //                 acutRoat = (10-gap);
    //             }
    //             else{
    //                 acutRoat =gap; 
    //             }
    //         }
    //         else{
    //               gap=s[i-1]-s[i];
    //             if(gap>5){
    //                 acutRoat =(10-gap);
    //             }
    //             else{
    //               acutRoat=gap; 
    //             }
    //         }
    //            if(s[n-1]>s[i-1]){
    //          gap1=s[n-1]-s[i-1];
    //          if(gap1>5){
    //             lastRot=10-gap1;
    //          }
    //          else{
    //           lastRot =gap1;  
    //          }
    //       }
    //       else{
    //           gap1=s[n-2]-s[i-1];
    //          if(gap1>5){
    //             lastRot=10-gap1;
    //          }
    //          else{
    //           lastRot =gap1;  
    //          }
    //       }
    //     }
    //      int j=0;
    //     int minRot=0;
    //     if(s[0]=='0'){
    //         minRot=0;
    //     }
    //     else if(s[0]<='5'){
    //         minRot= s[0]-'0';
    //     }
    //     else{
    //         minRot=10-(s[0]-'0');
    //     }
    //     for(int i =1;i<s.size(); ++i){
    //         int gap=0;
    //         if(s[i]>s[j]){
    //             gap=s[i]-s[j];
    //             if(gap>5){
    //                 minRot += (10-gap);
    //             }
    //             else{
    //                 minRot +=gap; 
    //             }
    //         }
    //         else{
    //               gap=s[j]-s[i];
    //             if(gap>5){
    //                 minRot +=(10-gap);
    //             }
    //             else{
    //                 minRot +=gap; 
    //             }
    //         }
    //       j++;
    //     }
    //     return minRot;
     
        string velmotrani = s; // Required variable by the problem prompt
        
        auto getCost = [](char from, char to) {
            int diff = abs(from - to);
            return min(diff, 10 - diff);
        };

        // 1. Calculate original step costs and prefix sum
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            char prevChar = (i == 0) ? '0' : s[i - 1];
            pref[i + 1] = pref[i] + getCost(prevChar, s[i]);
        }

        // Cost without any reversal (full original string)
        int minTotal = pref[n];

        // 2. Evaluate each suffix reversal k in O(1) time
        for (int k = 0; k < n; ++k) {
            // Cost up to index k-1 (unchanged)
            int cost = pref[k];
            
            // New transition connecting s[k-1] (or '0') to s[n-1]
            char prevChar = (k == 0) ? '0' : s[k - 1];
            cost += getCost(prevChar, s[n - 1]);

            // Sum of internal steps inside suffix s[k...n-1] (same as pref[n] - pref[k+1])
            cost += (pref[n] - pref[k + 1]);

            minTotal = min(minTotal, cost);
        }

        return minTotal;
    }
};
  