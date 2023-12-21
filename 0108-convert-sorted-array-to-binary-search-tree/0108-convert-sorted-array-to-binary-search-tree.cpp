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
    vector<bool> visited;
    TreeNode* DC(int left, int right, vector<int>& nums){
        // right - left
        // 짝수일 때 0 ~ 5 = 2 = 5 - 0 / 2  -> 0, 5 - 0 / 2 - 1 | 5 - 0 / 2 + 1, 5
        // 홀수일 때 0 ~ 4 = 2 = 4 - 0 / 2  -> 0, 4 - 0 / 2 - 1 | 4 - 0 / 2 + 1, 4
        TreeNode* pNode = nullptr;

        if(right <= left){
            if(!visited[left]){
                pNode = new TreeNode;
                pNode->val = nums[left];
                visited[left] = true;
                cout << left<< " " << right << " " << pNode->val << " " << endl;
            }
            return pNode;
        }
        
        int idx = (left + right) / 2;
        if(!visited[idx]){
            pNode = new TreeNode;
            pNode->val = nums[idx];
            visited[idx] = true;
            cout << left<< " " << right << " " << pNode->val << " " << endl;
            pNode->left = DC(left, idx-1, nums);
            pNode->right = DC(idx + 1, right, nums);
        }
        return pNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        visited.resize(nums.size());
        return DC(0, nums.size()-1, nums);
    }
};