class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer>st=new HashSet<Integer>();
        for(int i=0;i<arr1.length;i++){
            int no=arr1[i];
            while(no>0){
                st.add(no);
                no/=10;
            }
        }
        int mx=0;
        for(int i=0;i<arr2.length;i++){
            int no=arr2[i];
            while(no>0){
                if(st.contains(no)){
                    mx=Math.max(mx,(int)(Math.log10(no)+1));
                }
                no/=10;
            }
        }
        return mx;
    }
}