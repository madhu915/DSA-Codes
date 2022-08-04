class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>warm(n,0);
        stack<int>st;
        while(--n>=0){
            while(!st.empty() && temperatures[st.top()]<=temperatures[n])
                st.pop();
            if(!st.empty())
                warm[n]=st.top()-n;
            st.push(n);            
        }
        return warm;
    }
};