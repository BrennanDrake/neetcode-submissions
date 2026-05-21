class Solution {
public:

    std::unordered_map<char, int> chars_s;
    std::unordered_map<char, int> chars_t;

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        for (char c : s){
            chars_s[c] = chars_s[c]+1;
        }
        for (char c : t){
            chars_t[c] = chars_t[c]+1;
        }
        for (const auto& [key, value] : chars_s) {
            if (chars_s[key] != chars_t[key]){
                return false;
            }
        }
        // for (const auto& [key, value] : chars_t) {
        //     if (chars_s[key] != chars_t[key]){
        //         return false;
        //     }
        // }
        return true;
    }
};