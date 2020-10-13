bool isValid(string s) {
    int abc = 294;
    stack<int>  st;
    for (auto c : s)
    {
        if (c == 'a') st.push(97);
        if(c=='b')
        { 
            if (!st.empty() && st.top() == 97) st.push(97 + 98);
            else st.push(98);
        }
        if (c == 'c')
        {
            if (!st.empty()&& st.top() + 99 == 294)
            {
                    st.pop(); st.pop();
            }
            else
            {
                st.push(99);
            }
        }
    }
    return st.empty();
}
