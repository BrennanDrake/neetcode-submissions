class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> sub;

        dfs(nums, sub, output, 0);
        return output; 
    }

private:
    void dfs(vector<int>& nums, vector<int>& sub, vector<vector<int>>& output, int i){
        if(i == nums.size()){
            output.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, sub, output, i+1);

        sub.pop_back();
        dfs(nums, sub, output, i+1);

    }

};
