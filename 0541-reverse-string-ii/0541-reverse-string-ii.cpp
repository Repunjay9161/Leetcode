class Solution {
public:
    string reverseStr(string s, int k) {
       int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            // Find the boundary to reverse (either i + k or the end of string)
            int left = i;
            int right = min(i + k - 1, n - 1);
            
            // Reverse the first k characters of this 2k block
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};