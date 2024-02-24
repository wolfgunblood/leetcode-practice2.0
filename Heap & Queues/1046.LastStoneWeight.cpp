class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>> pq;

        for(auto stone : stones) pq.push(stone);
        
        // while(pq.size() > 0){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        

        while(pq.size() != 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int diff = y-x;
            pq.push(diff);
        }

        return pq.top();
        // return 0;
    }
};