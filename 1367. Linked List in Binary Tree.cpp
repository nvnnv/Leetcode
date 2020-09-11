void recurse1xxx(TreeNode* cur, vector<int>& path, ListNode* head, bool& is)
{
    if (cur->left == nullptr && cur->right == nullptr)
    {
        path.push_back(cur->val);
            for (int i = 0; i < path.size(); ++i)
            {
                bool ff = true;
                int k = i;
                auto x = head;
                while(x)
                {
                    if(k >= path.size())
                    {
                        ff = false;break;
                    }
                    if (x->val != path[k])
                    {
                        ff = false; break;
                    }
                    x = x->next;
                    ++k;
                }
                if (ff == true)
                {
                    is = true; break;
                }
            }
        path.pop_back();
        return;
    }
    path.push_back(cur->val);
    if (cur->left != nullptr && !is)
    {   
         recurse1xxx(cur->left, path, head, is);
    }
    if (cur->right != nullptr && !is)
    {
        recurse1xxx(cur->right, path, head, is);
    }
    path.pop_back();
}
bool isSubPath(ListNode* head, TreeNode* root) {
    vector<int> num;
    bool f = false;
    vector<int> p;
    recurse1xxx(root, p, head, f);
    return f;
}
