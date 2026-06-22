class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        vector<vector<int>> output;

        dfs(0, sub, output, nums, target);
        return output;
    }

    void dfs(int i, vector<int>& sub, vector<vector<int>>& output, vector<int> nums, int target){        
        if(target == 0){
            output.push_back(sub);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        sub.push_back(nums[i]);
        dfs(i, sub, output, nums, target-nums[i]);
        sub.pop_back();
        dfs(i+1, sub, output, nums, target);

    }

};
