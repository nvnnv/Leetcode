2 years ago completed
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto *ans = new ListNode(-1);
    auto x = ans, e = ans;
    int temp = 0;
    while (l1)
    {
        if(l2)
        {
            x->val = 0;
            temp = temp + l1->val + l2->val;
            x->val += temp % 10;
            temp /= 10;
            l2 = l2->next;

            auto xx = new ListNode(-1);
            e = x;
            x->next = xx;
            x = xx;
        }
        else
        {
            x->val = 0;
            temp = temp + l1->val;
            x->val = temp % 10;
            temp  /= 10;
            auto xx = new ListNode(-1);
            e = x;
            x->next = xx;
            x = xx;
        }
        l1 = l1->next;
    }
    while(l2)
    {
        x->val = 0;
        temp = temp + l2->val;
        x->val = temp % 10;
        temp  /= 10;
        auto xx = new ListNode(-1);
        e = x;
        x->next = xx;
        x = xx;
        l2 = l2->next;
    }
    if(temp != 0)
    {
        x->val = temp;
    }
    if(e->next == x && x->val == -1)
    {
        delete x;
        e->next = NULL;
    }
    return ans;
    }
};
