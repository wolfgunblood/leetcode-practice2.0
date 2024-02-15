class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> map;

        for(auto chr : nums){
            
            if(map.find(chr) != map.end())
            return chr;
            else
            map[chr]++;
        }

        return 0;
    }
};
