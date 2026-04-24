class Solution {
    unordered_set<int> visited;
    vector<vector<int>> l;

public:
    bool helper(int currNum) {
        if (visited.count(currNum) != 0) //cycle found
            return false;
        if (l[currNum].size() == 0) //there's no prerequisite
            return true;
        
        visited.insert(currNum);
        //for a course we need to satisfy all the prerequisites
        for (int& i: l[currNum]) {
            if (!helper(i))
                return false;
        }
        visited.erase(currNum);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //initialize adjacency list
        for (int i=0; i<numCourses; i++) {
            l.push_back({});
        }
        //build an adjancency list
        for (vector<int>& p: prerequisites) {
            l[p[0]].push_back(p[1]);
        }


        for (int i=0; i<numCourses; i++) {
            if(!helper(i))
                return false;
            visited.clear();
        }
        return true;
    }
};
