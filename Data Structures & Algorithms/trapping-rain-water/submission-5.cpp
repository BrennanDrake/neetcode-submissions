class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int l_max = height[0];
        int r_max = height[height.size()-1];
        int water = 0;

        while(l < r){
            if(l_max <= r_max){
                l++;
                l_max = max(l_max, height[l]);
                water += (l_max - height[l]);
            }else if(l_max > r_max){
                r--;
                r_max = max(r_max, height[r]);
                water += (r_max - height[r]);
            }

        }
        return water;
        
        
        // int l = 0;
        // int r = 0;
        // int mn = 0;
        // int output = 0;
        // int max = 0;
        // int max_ind = 0;

        // if(height.size() < 3){
        //     return 0;
        // }
        // while(height[l] == 0){
        //     if(l == height.size()-1){
        //         return 0;
        //     }
        //     l++;
        //     r++;
        // }
        // while(r < height.size()){
        //     int sum = 0;
        //     r++;
        //     if((r-l == 1)){
        //         continue;
        //     }
        //     while (r < height.size() && height[r] < height[l]){
        //         r++;
        //         if(r == height.size()-1){
        //             r = max_ind;
        //             break;
        //         }
        //         if(height[r] > max){
        //             max_ind = r;
        //             max = height[r];
        //         }
                
        //     }

        //     // Triggered when pool is found btwn l and r
        //     mn = min(height[l],height[r]);
        //     for(int i = r-1; i > l; i--){
        //         if(height[i] < mn){
        //             sum += mn - height[i];
        //         }else{
        //             sum += 0; 
        //         }
        //     }

        //     output += sum;
        //     l = r;
        // }
        // return output;
    }
};
