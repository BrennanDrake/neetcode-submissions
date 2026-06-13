class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> flat;
        for(int i = 0; i < matrix.size(); i++){
            for(int num: matrix[i]){
                flat.push_back(num);
            }
        }
        int l = 0;
        int r = flat.size()-1;
        while(l <= r){
            int m = ((r-l)/2)+l;
            if(flat[m] == target){
                return true;
            }else if(target > flat[m]){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return false;
    }
};
