class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        int i=s.lastIndexOf(' ');
        return i==-1?s.length():s.substring(i+1).length();
                            
    }
}