class Solution {
public:
    void fill(TreeNode* root, vector<int>& v){
        if(root->left) fill(root->left, v);
        v.push_back(root->val);
        if(root->right) fill(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        int lt=0, rt, sum;
        if(root) fill(root, v);
        rt = v.size()-1;
        while(lt < rt){
            sum = v[lt]+v[rt];
            if(sum == k) return 1;
            else if(sum < k) ++lt;
            else rt--;
        }
        return 0;
    }
};
