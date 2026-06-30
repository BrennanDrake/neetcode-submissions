class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        if(nums.empty()){
            return 0;
        }
        
        int max = 1;
        for(int num:nums){
            nums_set.insert(num);
        }
        for(int num:nums){
            int curr = 1;
            if(nums_set.find(num-1) == nums_set.end()){
                while(nums_set.find(num+1) != nums_set.end()){
                    curr++;
                    num++;
                }
                if(curr > max){
                    max = curr;
                }
            }
            while(nums_set.find(num-1) != nums_set.end()){
                num = num-1;
            }
        }
        return max;
    }
};
