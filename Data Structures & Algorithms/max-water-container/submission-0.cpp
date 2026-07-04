class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int curr = 0;
        int max = 0;
        while(l < r){
            curr = min(heights[l],heights[r])*(r-l);
            if(curr > max){
                max = curr;
            }
            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return max;
    }
};
