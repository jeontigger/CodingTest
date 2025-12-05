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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* cur;
    int N;
    void Init(ListNode* head){
        N = 0;
        cur = head;
        while(head != nullptr){
            N++;
            head = head->next;
        }
    }

    TreeNode* BST(int left, int right){
        if(left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* lNode = BST(left, mid-1);
        
        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;

        TreeNode* rNode = BST(mid+1, right);
        root->left = lNode;
        root->right = rNode;

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        Init(head);
        return BST(0, N-1);
    }
};