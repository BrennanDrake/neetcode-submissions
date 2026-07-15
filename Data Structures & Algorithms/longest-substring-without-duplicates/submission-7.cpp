class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char c;
        int l = 0;
        int r = 1;
        int max = 0;
        if(s.empty()) return 0;
        if(s.size() < 2) return 1;
        unordered_set<char> output = {s[0]};


        while(r < s.size()){
            if(output.contains(s[r])){
                while(output.contains(s[r])){
                    output.erase(s[l]);
                    l++;
                }
                output.insert(s[r]);
                r++;
                if(r-l > max){
                    max = r-l;
                }

            }else{
                output.insert(s[r]);
                r++;
                if(r-l > max){
                    max = r-l;
                }
            }
        }
        return max;
    }
};
