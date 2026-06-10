class Solution {
public:
    int strStr(string haystack, string needle) {
     int m = haystack.length();
        int n = needle.length();
        
        if (n == 0) return 0;
        std::vector<int> lps(n, 0);
        int len = 0; 
        int i = 1;
        
        while (i < n) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int haystackIdx = 0; 
        int needleIdx = 0;   
        
        while (haystackIdx < m) {
            if (haystack[haystackIdx] == needle[needleIdx]) {
                haystackIdx++;
                needleIdx++;
            }
            
            if (needleIdx == n) {
                return haystackIdx - n; 
            } 
            
            else if (haystackIdx < m && haystack[haystackIdx] != needle[needleIdx]) {
                if (needleIdx != 0) {
                    needleIdx = lps[needleIdx - 1]; 
                } else {
                    haystackIdx++;
                }
            }
        }
        
        return -1; 
    }
};