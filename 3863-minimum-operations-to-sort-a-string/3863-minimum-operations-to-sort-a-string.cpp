
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Case 1: Already sorted
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // Case 2: A reversed string of length 2
        // cannot be sorted because the entire string
        // cannot be selected as a substring.
        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // Case 3: Minimum is already at the start
        // OR maximum is already at the end.
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        // Case 4: Minimum occurs before the last
        // position OR maximum occurs after the first.
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        // Case 5: Both extremes are trapped at
        // the opposite ends.
        return 3;
    }
};
