class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> pq;
        queue<vector<int>> q;
        vector<int> count(26);

        for(auto task : tasks){
            count[task-'A']++;
        }
        for(int i =0;i<26;i++){
            if(count[i]) pq.push(count[i]);
        }
        int time = 0;
        
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                if(pq.top() - 1){
                    q.push({pq.top() - 1,time+n});
                }
                pq.pop();
            }

            if(!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }

        return time;
    }
};