
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	auto temp_l1 = l1;
	auto temp_l2 = l2;
	ListNode* temp = NULL;
	auto temp_l1_front = temp;
	auto head = l1;
	while (temp_l1)
	{
		if (temp_l1->val >= temp_l2->val)
		{
			do
			{
				temp = temp_l2;
				if (temp_l1_front)
				{
					temp_l1_front->next = temp_l2;
				}
				else
				{
					head = temp_l2;
				}
				temp_l2 = temp_l2->next;
				temp->next = temp_l1;
				temp_l1_front = temp;
				if (!temp_l2) break;
			} while (temp_l1->val >= temp_l2->val);
		}
		if (!temp_l2) break;
		temp_l1_front = temp_l1;
		temp_l1 = temp_l1->next;
	}
	if (temp_l2)
	{
		temp_l1_front->next = temp_l2;
	}
	return head;
}
