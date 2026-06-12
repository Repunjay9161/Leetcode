class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;
        while (i < chars.size()) {
            int j = i;
            while (j < chars.size() && chars[j] == chars[i]) {
                j++;
            }
            chars[write++] = chars[i];
            int count = j - i;
            if (count > 1) {
                std::string count_str = std::to_string(count);
                for (char c : count_str) {
                    chars[write++] = c;
                }
            }
            i = j;
        }
        return write;
    }
};