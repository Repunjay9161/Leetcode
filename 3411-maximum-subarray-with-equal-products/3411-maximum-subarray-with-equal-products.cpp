class Solution {
public:
    int maxLength(vector<int>& nums) {
      int n = static_cast<int>(nums.size()), ans = 0;

        for (int i = 0; i < n; ++i) {
            unsigned long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                int x = nums[j];
                g = (j == i) ? x : std::gcd(g, x);
                l = (l / std::gcd(l, static_cast<long long>(x))) * x;

                if (prod > ULLONG_MAX / static_cast<unsigned long long>(x)) break;
                prod *= static_cast<unsigned long long>(x);

                if (prod > 2520ULL * static_cast<unsigned long long>(g)) break;

                if (static_cast<__int128>(prod) == static_cast<__int128>(l) * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;  
    }
};