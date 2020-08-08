class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        extract(root);
    }

    /** @return the next smallest number */
    int next() {
        int x = data.front();
        data.pop();
        return x;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !data.empty();
    }
    void extract(TreeNode* cur)
    {
        if (cur == nullptr) return;
        extract(cur->left);
        data.push(cur->val);
        extract(cur->right);
    }
private:
    queue<int> data;
};
