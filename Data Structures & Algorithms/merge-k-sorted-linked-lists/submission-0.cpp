/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/** Approach
Init output linked list (reffed as ll from now on) with nullptr head
Iterate through list of lls checking first value
Find the minimum of the value of each of these and record it
advance that one ll
Repeat and set the next minimum (or equal) as the next node's value
Noting to not point but assign next node to value to avoid crossing references
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(true){
            int min = INT_MAX;
            int min_ind = -1;

            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val < min){
                    min = lists[i]->val;
                    min_ind = i;
                }
            }
            if(min_ind == -1){
                break;
            }

            tail->next = lists[min_ind];
            tail = tail->next;
            lists[min_ind] = lists[min_ind]->next;
        }
        return dummy.next;
    }
};
