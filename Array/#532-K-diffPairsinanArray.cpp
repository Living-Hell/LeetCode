//M1
//Using Set and Map
//Faster than 60.66% (34ms)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        
        if(k==0){
            unordered_map<int,int> mp;
            for(int i:nums) mp[i]++;
            for(auto i=mp.begin(); i!= mp.end(); i++){
                if(i->second>1) count++;
            }
        }
        
        else{
            unordered_set<int> s;
            for(int i:nums) s.insert(i);
            for(auto i = s.begin(); i!=s.end(); i++){
                if(s.find(*i+k)!= s.end())
                    count++;
            }
        }

        return count;
    }
};