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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* current3 = &dummy;
        ListNode* current1 = list1;
        ListNode* current2 = list2;


        while(current1 != nullptr || current2 != nullptr){
            if(current2 == nullptr){
                current3->next = current1;
                current3 = current3->next;
                current1 = current1->next;
            }
            else if(current1 == nullptr){
                current3->next = current2;
                current3 = current3->next;
                current2 = current2->next;
            }
            else if(current1->val <= current2->val){
                current3->next = current1;
                current3 = current3->next;
                current1 = current1->next;
            }else{
                current3->next = current2;
                current3 = current3->next;
                current2 = current2->next;
            }
        }
        return dummy.next;
    }
};
