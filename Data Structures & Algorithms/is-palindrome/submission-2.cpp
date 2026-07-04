class Solution {
public:
    bool isPalindrome(string s) {        
        int f = 0;
        int b = s.size()-1;
        while(f < b){
            if(!isalnum(s[f])){
                f++;
                continue;
            }
            if(!isalnum(s[b])){
                b--;
                continue;
            }
            if(tolower(s[f]) != tolower(s[b])){
                return false;
            }
            f++;
            b--;
        }
        return true;
    }
};
