int scoreOfParentheses(string S) {
    stack<int> L;
    stack<int> score;
    stack<int> score_pos_down;
    int ans = 0;
    int len_s = S.size();
    for (int i = 0; i < len_s; )
    {
        if (S[i] == '(')
        {
            L.push(i);
            ++i;
        }
        else
        {
            if (L.empty()) continue;
            int dist = 0;
            while (S[i] == ')' && !L.empty())
            {
                if (i - L.top() == 1)
                {
                    dist += 2;
                    score.push(1);
                    score_pos_down.push(L.top());
                }
                else if (i - L.top() - 1 == dist)
                {
                    auto& temp = score.top();
                    temp *= 2;
                    score_pos_down.pop();
                    score_pos_down.push(L.top());
                }
                else
                {
                    int sum = 0;
                    while (!score.empty() && score_pos_down.top() > L.top())
                    {
                        sum += score.top();
                        score.pop();
                        score_pos_down.pop();
                    }
                    sum *= 2;
                    score.push(sum);
                    score_pos_down.push(L.top());
                }
                ++i;
                L.pop();
            }
        }
    }
    while (!score.empty())
    {
        ans += score.top();
        score.pop();
    }
    return ans;
}
