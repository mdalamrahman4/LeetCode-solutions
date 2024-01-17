class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        int direction=0;
        vector<int>dir;
        while(left<=right && top<=bottom){
            if(direction==0 && left<=right)
            {
                for(int i=left;i<=right;i++){
                    dir.push_back(matrix[top][i]);
                }
                direction=1;
                top++;
            }
            if(direction==1 && top<=bottom){
                for(int i=top;i<=bottom;i++){
                    dir.push_back(matrix[i][right]);
                }
                direction=2;
                right--;
            }
            if(direction==2 && right>=left){
                for(int i=right;i>=left;i--){
                    dir.push_back(matrix[bottom][i]);
                }
                bottom--;
                direction=3;
            }
            if(direction==3 && bottom>=top)
            {
                for(int i=bottom;i>=top;i--)
                {
                    dir.push_back(matrix[i][left]);
                }
                left++;
                direction=0;
            }
        }
        return dir;
    }
};