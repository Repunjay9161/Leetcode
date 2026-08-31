class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        vector<pair<char , int>> vec;
        for(const auto& [ch,count] : freq ){
            vec.push_back({ch,count});
        }
      sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char,   int>& b) {
            return a.second > b.second;
        });;
        string result="";
        for(int i=0;i<vec.size();i++){
            int k= vec[i].second;
            while(k>0){
                result+=vec[i].first;
                k--;
            }
        }
      return result;
    }
};