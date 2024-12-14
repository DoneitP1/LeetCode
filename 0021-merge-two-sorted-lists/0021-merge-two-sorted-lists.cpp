class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;  // Create a dummy node
        ListNode* cur = &dummy;  // Use cur to keep track of the merged list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        cur->next = (list1 != nullptr) ? list1 : list2;

        return dummy.next;        
    }
};