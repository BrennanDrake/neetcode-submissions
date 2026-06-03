class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count1++;
            }else{
                if(count1 > count2){
                    count2 = count1;
                }
                count1 = 0;
            }
        }
        if(count1 > count2){
            count2 = count1;
        }
        
        return count2;
    }
};