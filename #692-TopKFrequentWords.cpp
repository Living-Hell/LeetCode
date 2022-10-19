//M1
//Using Hashmap and Vector
//Faster than 66.08% (21ms)

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(string word : words){
            mp[word]++;
        }
        
        vector<string> v[501];
        vector<string> ans;
        
        for(auto it:mp){
            v[it.second].push_back(it.first);
        }
        
        for(int i=500; i>=0; i--){
            if(k==0) break;
            if(v[i].size()>0){
                sort(v[i].begin(), v[i].end());
                for(string word : v[i]){
                    if(k==0) break;
                    ans.push_back(word);
                    k--;
                }
            }
        }
        
        return ans;
        
    }
};

//M2
//Using hashmap and Priority Queue
//Faster than 8.16% (40ms)

class Solution {
public:
    class cmp {
        public:
        bool operator() (const pair<int,string>&a, const pair<int,string>&b){
            
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        
        for(string word : words){
            mp[word]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        
        for(auto i = mp.begin(); i!= mp.end(); i++){
            pq.push(make_pair(i->second,i->first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};