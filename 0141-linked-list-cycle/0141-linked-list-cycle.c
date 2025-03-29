/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
bool hasCycle(struct ListNode *head) {
    node *slow = head;
    node *fast = head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            return true;
            break;
        }
    }
   return false;
}