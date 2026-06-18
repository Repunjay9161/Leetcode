class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
      stack<int> st;
    int maxA=0, n=h.size();

    for(int i=0;i<=n;i++){
        int cur = (i==n ? 0 : h[i]);
        while(!st.empty() && cur < h[st.top()]){
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;  
    }
};