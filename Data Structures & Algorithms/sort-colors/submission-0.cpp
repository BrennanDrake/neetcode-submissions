class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> counts;
        for(int num:nums){
            counts[num]++;
        };
        int output_ind = 0;

        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<counts[i]; j++){
                nums[output_ind] = i;
                output_ind++;
            }
        }
    }
};