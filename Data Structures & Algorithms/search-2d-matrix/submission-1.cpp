class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total = rows*cols;

        int l = 0;
        int r = total-1;

        while(l <= r){
            int m = ((r-l)/2)+l;
            int row = m/cols;
            int col = m%cols;
            int midValue = matrix[row][col];

            if(midValue == target){
                return true;
            }else if(target > midValue){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return false;
    }
};
