class Solution {
public:
    

    string encode(vector<string>& strs) {
        string output;

        for(string word : strs){
            output += to_string(word.size()) + "@" + word;
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        
        while(i < s.size()){
            int j = i;
            
            // Walk to '@'
            while (s[j] != '@'){
                j++;
            }

            string word = s.substr(i,j-i);
            int len = stoi(word);

            output.push_back(s.substr(j+1, len));

            i = j+1+len;

        }
        return output;
    }
};
