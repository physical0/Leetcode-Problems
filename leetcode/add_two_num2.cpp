struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // First Attempt, no solution seen; 2ms runtime O(N)
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *reversel1 = reverseList(l1);
        ListNode *reversel2 = reverseList(l2);

        ListNode *newNode = new ListNode();
        ListNode *head = newNode;
        int carry = 0;

        while (reversel1 != nullptr || reversel2 != nullptr || carry > 0)
        {
            int sum = carry;
            if (reversel1 != nullptr)
            {
                sum += reversel1->val;
                reversel1 = reversel1->next;
            }
            if (reversel2 != nullptr)
            {
                sum += reversel2->val;
                reversel2 = reversel2->next;
            }

            carry = sum / 10;
            newNode->val = sum % 10;
            if (reversel1 != nullptr || reversel2 != nullptr || carry > 0)
            {
                newNode->next = new ListNode();
                newNode = newNode->next;
            }
        }
        return reverseList(head);
    }
};