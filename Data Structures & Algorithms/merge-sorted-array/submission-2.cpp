class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = 0;
        int n2 = 0;
        int k = 0;
        vector<int> nums1_c = nums1;
        
        while(k < (m+n)){
            //The frontloading change below makes this unnecessary
            
            // if( n1 >= m){
            //     nums1[k] = nums2[n2];
            //     n2++, k++; 
            // }else if( n2 >= n){
            //     nums1[k] = nums1_c[n1];
            //     n1++, k++;
            // }else 

            // By frontloading the 'n1 < m' block, we avoid indexing out of bounds
            if(n1 < m && (n2 >= n || nums1_c[n1] <= nums2[n2])){
                nums1[k] = nums1_c[n1];
                k++, n1++;
            } else {
                nums1[k] = nums2[n2];
                k++, n2++;  
            }
        }
    }
};