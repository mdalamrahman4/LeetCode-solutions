class Solution {
public:
    int getarea(vector<vector<int>>&dp , int row , int n)
    {
        
        vector<int> pre(n) ; 
        pre[0] = -1 ;
        vector<int> next(n) ;
        next[n-1] = n ; 
        stack<int> s ; 
        s.push(0) ; 
        
        for(int i = 1 ; i<n ; i++)
        {
            if(dp[row][s.top()] < dp[row][i]) 
            {
                pre[i] = s.top() ; 
                s.push(i) ; 
            }
            else
            {
                while(!s.empty() && dp[row][s.top()] >= dp[row][i]) 
                {
                    s.pop() ; 
                }
                if(s.empty())
                {
                    pre[i] = -1 ; 
                    s.push(i) ;
                }
                else
                {
                    pre[i] = s.top() ; 
                    s.push(i) ; 
                }
            }
        }
        // s.clear() ; 
        while(!s.empty()) s.pop() ; 
        
        s.push(n-1) ; 
        for(int i = n-2 ; i>=0 ; i--)
        {
            if(dp[row][s.top()] < dp[row][i]) 
            {
                next[i] = s.top() ; 
                s.push(i) ; 
            }
            else
            {
                while(!s.empty() && dp[row][s.top()] >= dp[row][i]) 
                {
                    s.pop() ; 
                }
                if(s.empty())
                {
                    s.push(i) ;
                    next[i] = n ; 
                }
                else
                {
                    next[i] = s.top() ; 
                    s.push(i) ; 
                }
            }
        }
        int ans = INT_MIN ; 
        int area ; 
        for(int i = 0 ; i<n ; i++)
        {
            area = ( next[i] - pre[i] - 1) * dp[row][i] ; 
            ans = max(ans , area) ; 
        }
        return ans ; 
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        vector<vector<int>> dp(n , vector<int> (m)) ; 
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(i == 0)
                {
                    if(matrix[i][j] == '0') dp[i][j] = 0 ;
                    else dp[i][j] = 1 ; 
                    continue ;  
                }
                if(matrix[i][j] == '0') dp[i][j] = 0 ; 
                else dp[i][j] = dp[i-1][j] + 1 ; 
            }
        }
        int ans = INT_MIN ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            int area = getarea(dp , i , m ) ; 
            ans = max(ans , area) ;
        }
        return ans ; 
    }
};