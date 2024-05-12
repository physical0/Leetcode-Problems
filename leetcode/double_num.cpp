#include <iostream>
#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode* doubleIt(ListNode* head) {
    ListNode* reversed = reverseList(head);
    ListNode* current = reversed;
    ListNode* prev = nullptr;
    int carry = 0;

    while (current != nullptr) {
        int sum = current->val * 2 + carry;
        current->val = sum % 10;
        carry = sum / 10;
        prev = current;
        current = current->next;
    }

    if (carry > 0) {
        prev->next = new ListNode(carry);
    }

    return reverseList(reversed);
}
