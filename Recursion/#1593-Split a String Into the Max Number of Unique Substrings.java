//M1
//Using recursion and hashset
//Faster than 5.23% (182ms)

class Solution {
    int res = 1;

    public void helper(String s, int index, StringBuilder temp, HashSet<String> st) {
        if (index == s.length()) {
            res = Math.max(res, st.size());
            return;
        }
        temp.append(s.charAt(index));
        if (!st.contains(temp.toString())) {
            st.add(temp.toString());
            helper(s, index + 1, new StringBuilder(), st);
            st.remove(temp.toString());
        }
        helper(s, index + 1, temp, st);
    }

    public int maxUniqueSplit(String s) {
        HashSet<String> st = new HashSet<String>();
        helper(s, 0, new StringBuilder(), st);
        return res;
    }
}
