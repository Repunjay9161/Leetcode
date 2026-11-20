class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;
        int n = static_cast<int>(s.length());

        for (int i = 1; i < n; ++i) {
            unsigned char prev = static_cast<unsigned char>(s[i - 1]);
            unsigned char curr = static_cast<unsigned char>(s[i]);

            if (tolower(prev) != tolower(curr)) {
                ++changes;
            }
        }

        return changes;
    }
};