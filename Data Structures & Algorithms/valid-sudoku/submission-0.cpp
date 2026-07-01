class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> col[9];
        unordered_set<char> row[9];
        unordered_set<char> boxes[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int val = board[i][j];
                if( val == '.'){
                    continue;
                }
            
                int box = (i/3)*3 + j/3;

                if(col[j].count(val) || row[i].count(val) || boxes[box].count(val)){
                    return false;
                }
                col[j].insert(val);
                row[i].insert(val);
                boxes[box].insert(val);

            }
        }
        return true;
    }
};
