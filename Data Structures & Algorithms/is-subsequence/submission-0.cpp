class Solution {
public:
    bool isSubsequence(string s, string t) {
        string tmp = t;
        int a = 0;
        int b = 0;
        while(tmp.size() > s.size()){
            if(s[a] != tmp[b]){
                tmp.erase(tmp.begin() + b);
            }else a++, b++;
        }
        if(s == tmp){
            return true;
        }
        return false;
    }
};