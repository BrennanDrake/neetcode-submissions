class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Save original color
        int init = image[sr][sc];

        //Prevent edge case
        if(init == color) return image;

        //Initiate dfs (pulling the init color out)
        dfs(image, sr, sc, init, color);
        return image;

    }
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int init, int color){
        int rows = image.size();
        int cols = image[0].size();
        
        if(min(sr , sc) < 0 || sr == rows || sc == cols || image[sr][sc] != init){ 
            return;
        }

        image[sr][sc] = color;
        
        dfs(image, sr + 1, sc, init, color);
        dfs(image, sr - 1, sc, init, color);
        dfs(image, sr, sc + 1, init, color);
        dfs(image, sr, sc - 1, init, color);
    }
};