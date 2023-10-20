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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head;

        while(head&&head->next){
            int val1 = head->val;
            int val2 = head->next->val;

            head->val = val2;
            head->next->val = val1;

            head = head->next->next;
        }

        return res;
    }
};