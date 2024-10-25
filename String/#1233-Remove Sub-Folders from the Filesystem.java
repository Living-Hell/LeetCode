//M1
//Using ArrayList, sort and startsWith inbuilt function
//Faster than 91.43% (38ms)

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new ArrayList<>();
        int ind = 0;
        while (ind < folder.length) {
            String s = folder[ind];
            res.add(s);
            ind++;
            while (ind < folder.length && folder[ind].startsWith(s + "/")) {
                ind++;
            }
        }
        return res;
    }
}
