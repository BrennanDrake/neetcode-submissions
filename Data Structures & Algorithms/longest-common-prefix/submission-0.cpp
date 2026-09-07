class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output;
        
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(string str:strs){
                if(str[i] != c){
                    return output;
                }
            }
            output += c;
        }
        return output;
    }
};