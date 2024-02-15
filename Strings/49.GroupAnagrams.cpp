class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        // sort(strs.begin(),strs.end());

        for(auto str : strs) 
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            
            map[temp].push_back(str);
            
        }
        for(auto itr : map){
            // cout<<itr.first<<" ";
            // for(auto i : itr.second){
            //     cout<<i<<" ";
            // }
            // cout<<"/n";
            sort(itr.second.begin(),itr.second.end());
            res.push_back(itr.second);
        }

        return res;
    }
};