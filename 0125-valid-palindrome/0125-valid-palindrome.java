class Solution {
    public boolean isPalindrome(String s) {
        if(s.isEmpty())    return true;
        int h=0,t=s.length()-1;
        while(h<=t){
            char currf=s.charAt(h);
            char curre=s.charAt(t);
            if(!Character.isLetterOrDigit(currf)){
                h++;
            }
            else if(!Character.isLetterOrDigit(curre)){
                t--;
            }
            else{
                if(Character.toLowerCase(currf)!=Character.toLowerCase(curre))  return false;
                h++;
                t--;
            }
        }
        return true;
    }
}