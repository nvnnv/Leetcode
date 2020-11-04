Node* link2(Node* head, Node* link)
{
    Node* link_next = nullptr;
    if (link)
    {
        link_next = link->next;
        link->next = head;
        head->prev = link;
    }
    auto x = head;
    Node *end = nullptr;
    while (x)
    {
        if (x->child)
        {
            auto child = x->child;
            x->child = nullptr;
            x = link2(child, x);
        }
        if (x->next == nullptr)
        {
            if (link_next)
            {
                x->next = link_next;
                link_next->prev = x;
                end = x;
            }
            else
                end = x->prev;
            break;
        }
        x = x->next;
    }
    return end;
}
Node* flatten(Node* head) {
    link2(head, nullptr);
    return head;
}
