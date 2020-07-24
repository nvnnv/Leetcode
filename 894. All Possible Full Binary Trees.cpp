// this is complicated, 228ms  should be remended
void copyTree(TreeNode* x, TreeNode* y, set<TreeNode*>& flag, bool& b, string& order)
{
    if (x->left == nullptr && x->right == nullptr)
    {
        order += "011";
        if (b)
        {
            return;
        }
        if (!flag.count(x))
        {
            // a new answer
            TreeNode* l1 = new TreeNode(0);
            TreeNode* r1 = new TreeNode(0);
            y->left = l1;
            y->right = r1;
            // update
            flag.insert(x);
            b = true;
            order.pop_back();
            order.pop_back();
            order += "011011";

        }
        return;
    }
    order += "0";
    if (x->left)
    {
        TreeNode* f = new TreeNode(0);
        y->left = f;
        copyTree(x->left, f, flag, b, order);
    }
    if (x->right)
    {
        TreeNode* f = new TreeNode(0);
        y->right = f;
        copyTree(x->right, f, flag, b, order);
    }
}
vector<TreeNode*> allPossibleFBT(int N) {
        if (N % 2 == 0) {
        vector<TreeNode*> a;
        return a;
    }
    vector<vector<TreeNode*>> ans;
    TreeNode* x = new TreeNode(0);
    vector<TreeNode*> a = { x };
    ans.push_back(a);
        if (N == 1) return ans[0];
    TreeNode* x1 = new TreeNode(0);
    TreeNode* x2 = new TreeNode(0);
    TreeNode* x3 = new TreeNode(0);
    x1->left = x2;
    x1->right = x3;
    vector<TreeNode*> b = { x1 };
    ans.push_back(b);
    // begin from 5
    int n = 2;
    set<TreeNode*> flag;
    for (int i = 5; i <= N; i += 2)
    {
        auto& xo = ans.back();
        set<string> distinct;
        vector<TreeNode*> aa;
        for (auto root : xo)
        {
            int times = n;
            while (times--)
            {
                // copy
                TreeNode* f1 = new TreeNode(root->val);
                auto f2 = f1;
                auto f3 = root;
                bool f = false;
                string order = "";
                copyTree(root, f1, flag, f, order);
                // distinct
                if (!distinct.count(order))
                {
                    aa.push_back(f1);
                    distinct.insert(order);
                }
                else {// delete the tree}

                }
            }
            flag.clear();
        }
        ans.push_back(aa);
        ++n;
    }
    return ans[ans.size() - 1];
}

// optimal version 82ms
map<int, vector<TreeNode*>> save;
vector<TreeNode*> allPossibleFBT(int N) {
    if (N % 2 == 0) {
        return {};
    }
    if (N == 1) return { new TreeNode(0) };
    if (save.count(N)) return save[N];
    vector<TreeNode*> vN;
    for (int i = 1; i < N; i += 2)
    {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(N - i - 1);
        for (auto l : left)
        {
            for (auto r : right)
            {
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                vN.push_back(root);
            }
        }
    }
    save[N] = vN;
    return save[N];
}
