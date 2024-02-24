class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;

        for(auto num : nums) pq.push(num);

        while(pq.size() > this->k){
            cout<<pq.top()<<" ";
            pq.pop(); 
        }

        return pq.top();

    }
private:
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
};