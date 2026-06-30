class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len+1,1);
        vector<int> suffix(len+1,1);
        vector<int> output(len);
        for(int i = 1; i < len+1 ; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i = len-1; i >= 0 ; i--){
            suffix[i] = suffix[i+1] * nums[i];
            output[i] = prefix[i]*suffix[i+1];
        }
        return output;
    }
};
