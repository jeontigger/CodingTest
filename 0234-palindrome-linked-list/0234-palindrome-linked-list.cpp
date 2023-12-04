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
    bool isPalindrome(ListNode* head) {
        ListNode* reverse = nullptr;
        ListNode* node;
        node = head;

        while(node){
            ListNode* newNode = new ListNode(node->val, reverse);
            reverse = newNode;

            node = node->next;
            
        }

        node = head;
        while(node){
            if(node->val != reverse->val){
                return false;
            }else{
                node = node->next;
                reverse = reverse->next;
            }
        }
        return true;

    }
};