class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        int r;
        int i;
        int l;

        for(int i = 0; i < nums.size()-1; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i+1;
            r = nums.size()-1;
            while(l < r){
                int sol = -(nums[i]);

                if((nums[l] + nums[r]) > sol){
                    r--;
                }else if ((nums[l] + nums[r]) < sol){
                    l++;
                }else{
                    vector<int> target = {nums[l],nums[i],nums[r]}; 
                    output.push_back(target);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
            l = 0;
            r = nums.size()-1; 
        }
        return output;


    }
    // vector<int>& sort(vector<int>& nums){
    //     vector<int> counts;
    //     for(int i = 0; i < nums.size(); i++){
    //         counts[i] += 1;
    //     }

    //     int i = 0;
    //     for(int j = 0; j < counts.size(); j++){
    //         for(int k = 0; k < counts[j]; k++){
    //             nums[i] = j;
    //             i += 1;
    //         }
    //     }
    //     return nums;
    // }
};
