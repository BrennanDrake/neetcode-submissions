class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output;
        int a = 0;
        int b = 0;

        while(a < word1.size() && b < word2.size()){
            output += word1[a];
            output += word2[b];
            a++; b++;
        }
        if(a == word1.size()){
            //finish out word2
            while(b < word2.size()){
                output += word2[b];
                b++;
            }
        }else if(b == word2.size()){
            //finish out word1
            while(a < word1.size()){
                output += word1[a];
                a++;
            }
        }

        return output;

    }
};