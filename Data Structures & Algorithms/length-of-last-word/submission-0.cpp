class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = 0;
        int i = 0;
        if(s.size() == 1){
            if(s[0] == ' '){
                return 0;
            }else return 1;
        }
        
        while(i < s.size()){
            while(i < s.size() && s[i] != ' '){
                if(i > 0 && s[i-1] == ' '){
                    curr = 0;
                }
                curr++;
                i++;
                if(i == s.size()){
                    return curr;
                }
            }
            i++;
        }
        return curr;
    }
};