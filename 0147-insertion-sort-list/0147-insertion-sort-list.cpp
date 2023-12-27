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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* resNode = new ListNode(-100000);

        while(head){
            ListNode* iterNode = resNode;
            ListNode* targetNode = head;
            head = head->next;
            targetNode->next = nullptr;
            while(iterNode->next){
                if(targetNode->val < iterNode->next->val){
                    break;
                }
                iterNode = iterNode->next;
            }
            targetNode->next = iterNode->next;
            iterNode->next = targetNode;
        }

        return resNode->next;
    }
};