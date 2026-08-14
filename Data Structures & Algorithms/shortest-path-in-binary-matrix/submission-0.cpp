class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        deque<pair<int,int>> que;

        if(grid[0][0] == 1){
            return -1;
        }

        que.push_back(pair<int,int> (0,0));
        grid[0][0] = 1;
        int length = 0;
        int size = 1;

        while(size){
            length += 1;
            for(int i = 0; i < size; i++){
                auto [r,c] = que.front();
                if(r == rows-1 && c == cols-1){
                    return length;
                }
                que.pop_front();
                vector<pair<int,int>> neighbors = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
                for(auto [dr,dc] : neighbors){
                    if(min(r + dr, c + dc) < 0 || r + dr == rows || c + dc == cols || grid[r+dr][c+dc] == 1){
                        continue;
                    }
                    grid[r + dr][c + dc] = 1;
                    que.push_back({r + dr, c + dc});
                }
            }
            size = que.size();
        }
        return -1;
    }
};