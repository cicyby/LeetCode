//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit. 
//Add the two numbers and return it as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Example:
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
//Code by:ZhengYi
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;
    struct ListNode *t1 = p1;

	while(p1 != NULL || p2 != NULL)
	{
        
		if (p1 != NULL && p2 != NULL)   //位数相等
		{
            p1->val =p1->val + p2->val; //结果存入L1
            if(p1->next!=NULL){         //循环进位，直到保留最后一个
                if(p1->val >= 10){      //如果进位，p1的下一个结点值加1
                    p1->val -= 10;
                    p1->next->val += 1;
                }
            }
            t1 = p1;                //保存p1上个结点位置
			p2 = p2->next;
			p1 = p1->next;
		}
		else if (p2 != NULL)        //L2长度长
		{
            p1 = t1;                //返回p1前结点
			p1->next = p2; 
            p2 = NULL;              //将p2指向NULL
		}else{                      //L1长度长
            p1 = NULL;             
        }
	}

  	//从t1开始做进位处理
	p1=t1;
	while (p1->next != NULL)
	{
		if (p1->val >= 10)
		{
			p1->val -= 10;
			p1->next->val +=1;
		}
        p1=p1->next;
	}
    //最后一个结点进位处理
    if(p1->val >=10){
        p1->val -= 10;
        p1->next =  (struct ListNode*)malloc(sizeof(struct ListNode));
		p1 = p1->next;
		p1->val = 1;
		p1->next = NULL;
    }
   
	return l1;
}