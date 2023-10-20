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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* save= res;


        int mod = 0;
        int div = 0;
        while(l1&&l2){
            int val1 = l1->val;
            int val2 = l2->val;

            mod = (val1 + val2 + div) % 10;
            ListNode* newNode = new ListNode(mod);

            div = (val1 + val2 + div) / 10;

            l1 = l1->next;
            l2 = l2->next;

            
            res->next = newNode;
            res = res->next;
        }


        while(l1){
            int val = l1->val;

            mod = (val + div) % 10;
            ListNode* newNode = new ListNode(mod);

            res->next = newNode;
            res = res->next;
            div = (val + div) / 10;
            l1 = l1->next;
        }

        while(l2){
            int val = l2->val;

            mod = (val + div) % 10;
            ListNode* newNode = new ListNode(mod);

            res->next = newNode;
            res = res->next;
            div = (val + div) / 10;
            l2 = l2->next;
        }

        if(div){
            ListNode* newNode = new ListNode(div);
            res->next = newNode;
        }



        return save->next;
    }
};