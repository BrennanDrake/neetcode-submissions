class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = (nums.size()-1)/2;

        while (r > l){
            if(nums[mid] > nums[r]){
                l = mid + 1;
                mid = (r-l)/2 + l;
            }else if(nums[mid] < nums[r]){
                r = mid;
                mid = (r-l)/2 + l;
            }else{
                return nums[mid];
            }
        }
        
    }
};
