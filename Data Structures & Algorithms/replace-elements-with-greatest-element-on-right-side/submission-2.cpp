class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if(arr.size() != 1){
            for(int i = 0; i < arr.size()-1; i++){
                arr[i] = arr[i+1];
                for(int j = i+1; j<arr.size(); j++){
                    if(arr[j] > arr[i]){
                        arr[i] = arr[j];
                    }
                }
            }
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};