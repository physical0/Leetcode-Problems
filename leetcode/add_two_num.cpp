struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // Second attempt, seen solution
    ListNode *current = new ListNode();
    ListNode *head = current;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0)
    {
        int sum = carry;

        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->val = sum % 10;

        if (l1 != nullptr || l2 != nullptr || carry > 0)
        {
            current->next = new ListNode();
            current = current->next;
        }
    }
    return head;
}