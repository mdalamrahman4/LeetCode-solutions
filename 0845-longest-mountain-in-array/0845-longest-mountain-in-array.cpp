class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int mx=0,n=arr.size();
        for(int i=1;i<n-1;i++){
            if((arr[i]>arr[i-1]) && (arr[i]>arr[i+1])){
                int leftroot=i;
                int rightroot=i;
                while(leftroot>0 && arr[leftroot]>arr[leftroot-1]){
                    leftroot--;
                }
                while(rightroot<n-1 && arr[rightroot]>arr[rightroot+1]){
                    rightroot++;
                }
                mx=max(mx,rightroot-leftroot+1);
                i=rightroot;
            }
        }
        return mx;
    }
};