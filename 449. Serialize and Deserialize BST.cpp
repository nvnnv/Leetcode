class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<vector<string>> x;
        levelOrderWithN(root, 0, x);
        string s;
        for (auto& v : x)
        {
            for (auto& c : v)
            {
                s += c;
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        if (data[0] == 'N') return nullptr;
        const char x = '|';
        int i = 0;
        string s = substr(i, x, data);
        int d = convertInt(s);
        TreeNode* root = new TreeNode(d);
        queue<TreeNode*> q;
        q.push(root);
        while (i < data.size() && !q.empty())
        {
            auto& node = q.front();
            ++i;
            if (data[i] != 'N')
            {
                s = substr(i, x, data);
                d = convertInt(s);
                TreeNode* left = new TreeNode(d);
                node->left = left;
                q.push(left);
            }
            ++i;
            if (i < data.size() && data[i] != 'N')
            {
                s = substr(i, x, data);
                d = convertInt(s);
                TreeNode* right = new TreeNode(d);
                node->right = right;
                q.push(right);
            }
            q.pop();
        }
        return root;
    }
private:
    void levelOrderWithN(TreeNode* cur, int level, vector<vector<string>>& v)
    {
        
        if (level >= v.size())
        {
            vector<string> c;
            v.push_back(c);
        }
        v[level].push_back((cur == nullptr) ? "N" :convertStr(cur->val) + "|");
        if (cur == nullptr) return;
        levelOrderWithN(cur->left, level + 1, v);
        levelOrderWithN(cur->right, level + 1, v);
    }

    string convertStr(int x)
    {
        ss.clear();
        string s;
        ss << x;
        ss >> s;
        return s;
    }
    int convertInt(string& s)
    {
        ss.clear();
        int x;
        ss << s;
        ss >> x;
        return x;
    }

    string substr(int& i, char c, string& s)
    {
        string x;
        while (s[i] != c)
        {
            x.push_back(s[i]);
            ++i;
        }
        return x;
    }
    stringstream ss;
};
