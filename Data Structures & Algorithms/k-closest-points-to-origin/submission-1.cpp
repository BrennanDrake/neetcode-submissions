class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int L = 0;
        int R = points.size()-1;
        int pivot = points.size();
        
        while(pivot != k){
            pivot = partition(points,L,R);
            if(pivot < k){
                L = pivot + 1;
            }else{
                R = pivot - 1;
            }
        }
        
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }


private:
    int compute_dist(vector<int> dists){
        int dist = 0;
        for(int unit_dist:dists){
            dist = unit_dist*unit_dist + dist;
        }
        return dist;
    }

    int partition(vector<vector<int>>& points, int l, int r){
        int pivotInd = r;
        int pivotDist = compute_dist(points[pivotInd]);
        int i = l;
        for( int j = l; j < r; j++){
            if(compute_dist(points[j]) <= pivotDist){
                swap(points[i],points[j]);
                i++;
            }
        }
        swap(points[i], points[r]);
        return i;
    }
};






        // priority_queue<pair<int, pair<int,int>>> maxHeap;
        // for (auto& point: points){
        //     int dist = point[0]*point[0] + point[1]*point[1];
        //     maxHeap.push({dist,{point[0],point[1]}});
        //     if (maxHeap.size() > k){
        //         maxHeap.pop();
        //     }
        // }
    
        // vector<vector<int>> output;
        // while(!maxHeap.empty()){
        //     output.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
        //     maxHeap.pop();
        // }
        // return output;
