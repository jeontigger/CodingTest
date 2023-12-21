/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // BFS 방식
    // string serialize(TreeNode* root) {
    //     list<TreeNode*> q;
    //     q.push_back(root);
    //     string res = "";
    //     while(!q.empty()){
    //         TreeNode* curNode = q.front();
    //         q.pop_front();

    //         if(curNode != nullptr){
    //             res += to_string(curNode->val) + ",";
    //         }else{
    //             res += ",";
    //         }

    //         if(curNode == nullptr){
    //             continue;
    //         }

    //         q.push_back(curNode->left);
    //         q.push_back(curNode->right);
    //     }

    //     return res;
    // }

    string serialize(TreeNode* root) {
        if(root==nullptr){
            return ",";
        }

        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* strToTree(list<string>& _vec){
        if(_vec.empty()){
            return nullptr;
        }
        string str = _vec.front();
        _vec.pop_front();
        if(str == " "|| str == ""){
            return nullptr;
        }
        
        int val = stoi(str);
        TreeNode* pNode = new TreeNode(val);

        pNode->left = strToTree(_vec);
        pNode->right = strToTree(_vec);

        return pNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;

        cout << data << endl;

        istringstream iss2(data);        
        string buffer;                  
    
        list<string> vecData;
    
        while(getline(iss2, buffer, ','))
            vecData.push_back(buffer);
        
        for(string str:vecData){
            cout << str << " ";
        }

        return strToTree(vecData);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));