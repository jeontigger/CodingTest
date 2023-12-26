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
    void printList(ListNode* head){
        ListNode* pNode = head;
        while(pNode){
            cout << pNode->val << " ";
            pNode = pNode->next;
        }
        cout << endl;

    }
    int CountingNode(ListNode* head){
        ListNode* pNode = head;
        int res = 0;
        while(pNode){
            res++;
            pNode = pNode->next;
        }
        return res;
    }
    ListNode* Solution1(ListNode* head){
        int nodeCnt = CountingNode(head);
        if(head == nullptr){
            return head;
        }
        for(int i = 0 ; i <nodeCnt ; i++){
            ListNode* pNode = head;
            while(pNode->next){
                int curVal = pNode->val;
                int nextVal = pNode->next->val;

                if(nextVal < curVal){
                    pNode->val = nextVal;
                    pNode->next->val = curVal;
                }
                pNode = pNode->next;
            }
        }

        printList(head);
        return head;
    }

    ListNode* Solution2(ListNode* head){
        int nodeCnt = CountingNode(head);
        if(nodeCnt == 0){
            return head;
        }
        ListNode* pNode = head;
        vector<int> vecSort(nodeCnt);
        for(int i =0; i< vecSort.size();i++){
            vecSort[i] = pNode->val;
            pNode = pNode->next;
        }

        sort(vecSort.begin(), vecSort.end());

        pNode = head;
        for(int i = 0; i<vecSort.size(); i++){
            pNode->val = vecSort[i];
            pNode = pNode->next;
        }

        return head;
    }
    ListNode* sortList(ListNode* head) {
        // 타임아웃
        // head = Solution1(head);
        head = Solution2(head);
        return head;
    }
    
};