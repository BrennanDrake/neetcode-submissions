class Solution {
public:
    int scoreOfString(string s) {
        if(s.size() == 1){
            return 0;
        }
        int sum = 0;
        for(int i = 1; i < s.size(); i++){
            sum += abs(int(s.at(i)) - int(s.at(i-1)));
        }
        return sum;
    }
};