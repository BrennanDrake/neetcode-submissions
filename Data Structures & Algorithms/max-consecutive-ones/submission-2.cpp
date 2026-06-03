class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        for(int i : nums){
            if(i == 1){
                count1++;
                if(count1 > count2){
                    count2 = count1;
                }
            }else{
                count1 = 0;
            }
        }
        
        return count2;
    }
};