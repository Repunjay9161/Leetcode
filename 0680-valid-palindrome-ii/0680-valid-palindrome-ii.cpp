class Solution {
public:
    bool validPalindrome(string s) {
      int left = 0, right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                int l1 = left + 1, r1 = right;
                bool isPal1 = true;
                while (l1 < r1) {
                    if (s[l1] != s[r1]) {
                        isPal1 = false;
                        break;
                    }
                    l1++;
                    r1--;
         
                }
                int l2 = left, r2 = right - 1;
                bool isPal2 = true;
                while (l2 < r2) {
                    if (s[l2] != s[r2]) {
                        isPal2 = false;
                        break;
                    }
                    l2++;
                    r2--;
                }
                return isPal1 || isPal2;
            }
            left++;
            right--;
        }

        return true;
    }
};