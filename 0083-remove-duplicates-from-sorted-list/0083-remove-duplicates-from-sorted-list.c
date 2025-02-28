struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* temp,*t,*x,*new;
    temp=head;
    int arr[300],brr[300];
    int a=0,b=0,c=0,d=1;
    while(temp!=NULL){
        arr[c]=temp->val;
       
        c++;
        temp=temp->next;
    }
   
    for(int i=0;i<c;i++){
        for(int j=0;j<b;j++){
            if(arr[i]!=brr[j]){
             a++;
            }
        }
        if(a==b){
            brr[b]=arr[i];
            b++;
        }
        a=0;
    }
    
    t=(struct ListNode*)malloc(sizeof(struct ListNode));
    if(b==0){
    t=NULL;
    }
    if(b>0){
    t->val=brr[0];
    t->next=NULL;
    x=t;
    while(b!=d && b>0){
       new=(struct ListNode*)malloc(sizeof(struct ListNode));
       new->val=brr[d];
       new->next=NULL;
       x->next=new;
       x=new;
       d++;
    }
    }
    return t;
}