class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //Init row and col size
        int rows = grid.size();
        int cols = grid[0].size();

        //Init queue for holding each level
        deque<pair<int,int>> que;

        //Starting point edge case
        if(grid[0][0] == 1){
            return -1;
        }

        //Init first point
        que.push_back(pair<int,int> (0,0));
        grid[0][0] = 1;
        int length = 0;
        int size = 1;

        //While there are next possible moves
        while(size){
            //Increment Level
            length += 1;

            //Iterate through all next possible moves
            for(int i = 0; i < size; i++){
                auto [r,c] = que.front();
                if(r == rows-1 && c == cols-1){
                    return length;
                }
                //remove current square
                que.pop_front();

                //Init all possible next move deltas
                vector<pair<int,int>> neighbors = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

                //Iterate through all next possible moves, set them to be occupied, and add to queue
                for(auto [dr,dc] : neighbors){
                    if(min(r + dr, c + dc) < 0 || r + dr == rows || c + dc == cols || grid[r+dr][c+dc] == 1){
                        continue;
                    }
                    grid[r + dr][c + dc] = 1;
                    que.push_back({r + dr, c + dc});
                }
            }
            //Set size to num of possible squares in next level
            size = que.size();
        }
        return -1;
    }
};