// 1182ms
class FindElements {
public:
    TreeNode* tree;
    void recover(TreeNode* cur, TreeNode* curP, int leftOrR)
    {
        if (cur == nullptr) return;
        if (curP) cur->val = curP->val * 2 + leftOrR;
        recover(cur->left, cur, 1);
        recover(cur->right, cur, 2);
    }
    FindElements(TreeNode* root) {
        tree = root;
        root->val = 0;
        recover(root, nullptr, 0);
    }
    bool search(TreeNode* cur, int& t)
    {
        if (cur == nullptr) return false;
        return cur->val == t || search(cur->left, t) || search(cur->right, t);
    }
    bool find(int target) {
        return search(tree, target);
    }
};

// 72ms
class FindElements {
public:
    unordered_set<int> set;
    void recover(TreeNode* cur, TreeNode* curP, int leftOrR, unordered_set<int>& s)
    {
        if (cur == nullptr) return;
        if (curP)
        {
            cur->val = curP->val * 2 + leftOrR;
            s.insert(cur->val);
        }
        recover(cur->left, cur, 1, s);
        recover(cur->right, cur, 2, s);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        recover(root, nullptr, 0, set);
    }
    bool find(int target) {
        return set.count(target);
    }
};
