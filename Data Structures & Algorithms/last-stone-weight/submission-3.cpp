class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        int result = 0;
        int a;
        int b;
        if(stones.size() == 1){
            return stones[0];
        }

        for(int stone:stones){
            heap.push(stone);
        }
        while(heap.size() > 1 ){
            a = heap.top();
            heap.pop();
            b = heap.top();
            heap.pop();
            result = abs(a - b);

            if(result != 0){
                heap.push(result);
            }
        }
        if(heap.empty()){
            heap.push(0);
        }
        return heap.top();
    }
};
