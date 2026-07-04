class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while(i < j && j > i+1 && numbers[i] + numbers[j] != target){
            if(target > numbers[i] + numbers[j]){
                i++;
            }else{
                j--;
            }
        }
        i++;
        j++;
        return {i,j};

    }
};
