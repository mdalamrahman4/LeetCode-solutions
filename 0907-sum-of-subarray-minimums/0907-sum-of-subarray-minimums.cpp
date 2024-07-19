class Solution {
public:
    vector<int> next(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> v(n);
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            v[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return v;
    }
    
    vector<int> prev(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> v(n);
        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            v[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = next(arr, n);
        vector<int> pse = prev(arr, n);
        long long total = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right * arr[i])) % mod;
        }
        
        return total;
    }
};