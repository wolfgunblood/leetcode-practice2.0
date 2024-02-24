class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> m;

        for(int i =0;i<prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> visited;
        unordered_set<int> cycle;
        vector<int> result;

        for(int course=0;course<numCourses;course++){

            if(!dfs(course,m,visited,cycle,result)){
                return {};
            }
        }

        return result;
    }
private:
    bool dfs(int course,unordered_map<int,vector<int>>& m,unordered_set<int>& visited,unordered_set<int>& cycle,vector<int>& result){

        if(cycle.find(course) != cycle.end()){
            return false;
        }
        if(visited.find(course) != visited.end()){
            return true;
        }
        cycle.insert(course);

        for(int i =0;i<m[course].size();i++){
            int numCourse = m[course][i];

            if(!dfs(numCourse,m,visited,cycle,result)){
                return false;
            }
        }

        visited.insert(course);
        cycle.erase(course);
        result.push_back(course);
        return true;
    }
};