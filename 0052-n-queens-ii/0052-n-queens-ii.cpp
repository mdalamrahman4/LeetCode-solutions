class Solution1 {
public:
    bool safe(int row,int col,vector<string>&board,int n)
    {
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupcol;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(safe(i,col,board,n))
            {
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }
    int solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};
class Solution {
public:
    int totalNQueens(int n) {
        Solution1 sl;
        return sl.solveNQueens(n);
    }
};