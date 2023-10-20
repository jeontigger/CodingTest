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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* headNode = head;

        int cnt = 1;
        int idx = 0;

        vector<int> values;
        values.reserve(right - left + 1);

        while(head){

            if(left <= cnt && cnt <= right){
                values.push_back(head->val);
                idx++;
            }

            cnt++;
            head = head->next;
        }

        head = headNode;

        reverse(values.begin(), values.end());

        cnt = 1;
        idx = 0;
        while(head){
            if(left<=cnt && cnt <= right){
                head->val = values[idx];
                idx++;
            }

            cnt++;
            head = head->next;
        }

        

        return headNode;
    }
};