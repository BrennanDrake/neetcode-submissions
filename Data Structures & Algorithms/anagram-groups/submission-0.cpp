/* 
Go char by char in word adding to hashmap of char to quant
If first word, add to first unorderedmap in unorderedmap (matrix in matrix)
When to the end of the word, check equality with first entry in each inner matrix.
If equal, add to that inner matrix, if not continue. If next is null, add to outer matrix.
Repeat

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    unordered_map<string, vector<string>> output_map;
    vector<vector<string>> output;

    for(string anagram : strs){
        string sorted = anagram;
        std::sort(sorted.begin(),sorted.end());
        
        output_map[sorted].push_back(anagram);
    }
    for(auto& [key,group]:output_map){
        output.push_back(group);
    }
    return output;
    }
};
