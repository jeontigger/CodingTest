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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr|| head->next == nullptr){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* res = odd;
        ListNode* evenStart = even;

        head = head->next->next;

        while(head){
            odd->next = head;
            even->next = head->next;

            odd = odd->next;
            even = even->next;
            if(head->next == nullptr)
                break;
            head = head->next->next;
        }

        odd->next = evenStart;

        return res;
    }
};