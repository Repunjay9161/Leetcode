class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long  r= 0;
        int sign=1;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            r = r * 10 + (s[i] - '0');
            
            if (sign == 1 && r > INT_MAX) return INT_MAX;
            if (sign == -1 && -r < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return r * sign;
    }
};