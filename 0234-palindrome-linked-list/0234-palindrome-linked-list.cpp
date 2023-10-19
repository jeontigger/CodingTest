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
        string nums = "";
        int cnt = 0;
        ListNode* cntNode = head;
        while(true){
            cnt++;
            if(cntNode->next == nullptr){
                break;
            }
            cntNode = cntNode->next;
        }
        nums.reserve(cnt);


        while(true){
            nums += head->val + '0';
            if(head->next == nullptr){
                break;
            }
            head = head->next;
        }
        
        for(int i = 0; i<nums.length();i++){
            if(nums[i] != nums[nums.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};