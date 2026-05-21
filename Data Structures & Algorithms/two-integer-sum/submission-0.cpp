class Solution {
public:
    
    std::unordered_map<int, int> num_ind;
    
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i){
            num_ind[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i){
            int dif = target - nums[i];
            if ( num_ind.count(dif) && num_ind[dif] != i){
                return {i, num_ind[dif]};
            }
        }
    }
};
