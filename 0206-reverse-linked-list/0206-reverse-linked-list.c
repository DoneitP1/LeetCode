/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev,*cur,*aft;
    prev=0;
    cur=aft=head;
    while(aft!=0){
        aft=aft->next;
        cur->next=prev;
        prev=cur;
        cur=aft;
    }
head=prev;
return prev;
}