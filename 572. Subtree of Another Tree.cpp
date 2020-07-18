void ox(TreeNode* cur, TreeNode* aim, bool& f)
{
    if (cur->val == aim->val)
    {
        if (cur->left == nullptr && cur->right == nullptr && aim->left == nullptr && aim->right == nullptr)
        {
            return;
        }
        if (cur->left && aim->left)
        {
            ox(cur->left, aim->left, f);
            if (f == false) return;
        }
        if (cur->left && aim->left == nullptr)
        {
            f = false;
            return;
        }
        if (cur->left == nullptr && aim->left)
        {
            f = false;
            return;
        }
        if (cur->right && aim->right)
        {
            ox(cur->right, aim->right, f);
            if (f == false) return;
        }
        if (cur->right && aim->right == nullptr)
        {
            f = false;
            return;
        }
        if (cur->right == nullptr && aim->right)
        {
            f = false
            return;
        }
    }
    else f = false;
}
void xo(TreeNode* cur, TreeNode* aim, bool& f)
{
    if (cur->val == aim->val)
    {
        bool ff = true;
        ox(cur, aim, ff);
        if (ff)
        {
            f = ff;
            return;
        }
    }
    if (cur->left == nullptr && cur->right == nullptr)
    {
        return;
    }
    if (cur->left)
    {
        xo(cur->left, aim, f);
    }
    if (f) return;
    if (cur->right)
    {
        xo(cur->right, aim, f);
    }
    if (f) return;
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr) return false;
    if (t == nullptr) return true;
    bool f = false;
    xo(s, t, f);
    return f;
}


// another way
bool ox(TreeNode* s, TreeNode* t)
{
    if (s == nullptr && t != nullptr) return false;
    if (s != nullptr && t == nullptr) return false;
    if (s == nullptr && t == nullptr) return true;
    if (s != nullptr && t != nullptr)
    {
        if (s->val == t->val)
        {
            return ox(s->left, t->left) && ox(s->right, t->right);
        }
        return false;
    }
    return true;
}
bool xo(TreeNode* s, TreeNode* t)
{
    if(s==nullptr) return false;
    return ox(s, t) || xo(s->left, t) || xo(s->right, t);
}
bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr) return false;
    if (t == nullptr) return true;
    return xo(s, t);
}
