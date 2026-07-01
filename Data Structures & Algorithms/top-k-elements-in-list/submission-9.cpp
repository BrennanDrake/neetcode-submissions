#include <span>
#include <ranges>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int,int> freq_map;
        int freq;

        int j = nums.size() - 1;

        for(int num:nums){
            freq_map[num]++;
        };
        for(const auto& [num , freq] : freq_map ){
            bucket[freq].push_back(num);
        }
        for(int j = bucket.size()-1; j > 0; j--){
            if(bucket[j].empty() != true){
                for(int l : bucket[j]){
                    output.push_back(l);
                    if(output.size() == k){
                        return output;
                    }
                }
            };
        };
        return output;
    };
};
