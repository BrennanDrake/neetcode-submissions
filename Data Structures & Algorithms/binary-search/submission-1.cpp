class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m = (r - l)/2;
        while(nums[m] != target && ((r-l)>2)){
            if(target > nums[m]){
                l = m+1;
                m = (r-l)/2 + l;
            }else if(target < nums[m]){
                r = m-1;
                m = (r-l)/2 + l;
            }
        }
        if(nums[l] == target){
            return l;
        }else if(nums[r] == target){
            return r;
        }else if(nums[m] == target){
            return m;
        }else{
            return -1;
        }
        
    }
};
