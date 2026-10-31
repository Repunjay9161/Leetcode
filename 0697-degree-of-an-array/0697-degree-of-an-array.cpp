class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
       unordered_map<int, int> count;     
     unordered_map<int, int> firstIndex; 
        unordered_map<int, int> lastIndex;  
        
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (firstIndex.find(num) == firstIndex.end()) {
                firstIndex[num] = i;
            }
            lastIndex[num] = i;
            count[num]++;
            
            degree = max(degree, count[num]);
        }
        
        int minLength = nums.size();
        for (auto& pair : count) {
            int num = pair.first;
            if (pair.second == degree) {
                int length = lastIndex[num] - firstIndex[num] + 1;
                minLength = std::min(minLength, length);
            }
        }
        
        return minLength; 
    }
};