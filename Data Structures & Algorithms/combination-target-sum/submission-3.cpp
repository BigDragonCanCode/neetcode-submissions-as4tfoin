class Solution {
public:
    //have i so that we don't have same combination like [3,2] after [2,3]
    void helper(vector<vector<int>>& results, vector<int>& candidates, vector<int>& path, int remaining, int idx) {
        //found a result
        if (remaining == 0) {
            results.push_back(path);
            return;
        }
        for (int i=idx; i<candidates.size(); i++) {
            int c = candidates[i];
            if (c > remaining) continue;

            path.push_back(c);
            helper(results, candidates, path, remaining-c, i); //passing i allow reuse of same number
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> path;
         
        helper(results, nums, path, target, 0);
        return results;
    }
};
