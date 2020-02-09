/**
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?

code by:ZhengYi
    for arriving the aim(do in one pass),the code look like a ugly girl. 
 * /

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* pre = head;
    struct ListNode* tail = head;
    int ture = 1;
    if(tail->next==NULL){             //只有一个结点时，example:[data],1
        head = NULL;
        return head;
    }
    while(tail->next!= NULL){
        if(ture==1){                  //for 循环开关
            for(int i = 0;i < n; i++){//移动tail，使pre和tail之间距离为n-1
                tail = tail->next;
                if(tail == NULL){     //删除的是头结点
                    head = pre->next;
                    return head;
                }
            }
            ture = 0;                 //for 循环关闭
        }
        if(tail->next!=NULL){         //pre和tail同时移动
            pre = pre->next;
            tail = tail->next; 
        }
    }
    pre->next = pre->next->next;      //删除其他结点
    return head;
}