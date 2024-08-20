class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size(),m=image[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                int temp=image[i][j];
                image[i][j]=(1+image[i][m-j-1])%2;
                image[i][m-j-1]=(1+temp)%2;
            }
            if (m % 2 == 1) {
                image[i][m / 2] = (image[i][m / 2] + 1) % 2;
            }
        }
        return image;
    }
};