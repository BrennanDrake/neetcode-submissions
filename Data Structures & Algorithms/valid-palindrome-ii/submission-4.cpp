class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        int count = 0;
        
        while(s[l] == s[r]){
            if(r == l || l > r){
                return true;
            }
            l++;
            r--;
        }
        return (check( s, l, r-1) || check( s, l+1, r));
    }

    bool check(string s, int i, int j) {        
        while(s[i] == s[j]){
            if(i >= j){
                return true;
            }
            i++;
            j--;
        }
        return false;
    }
};