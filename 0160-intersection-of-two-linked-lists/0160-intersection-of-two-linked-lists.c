/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *temp1;
    struct ListNode *temp2;
    int intersectVal=0;
for(temp1=headA;temp1!=NULL;temp1=temp1->next){
    for(temp2=headB;temp2!=NULL;temp2=temp2->next){
         if(temp1==temp2){
             intersectVal=1;
             break;
         }
    }
    if(intersectVal)
        break;
    }
return temp1;
}