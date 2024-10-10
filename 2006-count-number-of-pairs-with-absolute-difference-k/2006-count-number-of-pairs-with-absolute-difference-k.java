class Solution {
    public int countKDifference(int[] arr, int k) {
        int n=arr.length;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            int x = arr[i];
            for(int j = 0; j < n; j++)
            {
                if(arr[j] == (x+k) || arr[j] == (x-k))
                {
                    count++;
                }
            }
        }
        return count/2;
    }
}