class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        char templ = ' ';
        while(r > l){
            templ = s[l];
            s[l] = s[r];
            s[r] = templ;
            l++;
            r--;
        }
    }
};