class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int output = r;

        while(l <= r){
            double m = ((r-l)/2)+l;
            long long totalTime = 0;

            for(double p : piles){
                totalTime += ((p+m-1)/m);
            }
            if(totalTime <= h){
                r = m-1;
                int pot = m;
            }else if(totalTime > h){
                l = m+1;
            }else{
                return m;
            }
        }
        return l;
    }
};
