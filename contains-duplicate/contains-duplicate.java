class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int it:nums){
            mp.put(it,mp.getOrDefault(it,0)+1);
        }
        for(int it:mp.values()){
            if(it>1)    return true;
        }
        return false;
    }
}