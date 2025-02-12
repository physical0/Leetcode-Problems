#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Seen solution
ListNode *reversedList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode *doubleIt(ListNode *head)
{
    head = reversedList(head);

    ListNode *current = head;
    int carry = 0;

    while (current != NULL)
    {
        int sum = current->val * 2 + carry;
        current->val = sum % 10;
        carry = sum / 10;
        if (carry > 0 && current->next == NULL)
        {
            current->next = new ListNode(carry);
            break;
        }
        current = current->next;
    }
    return reversedList(head);
}
