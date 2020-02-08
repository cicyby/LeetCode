//给出两个?非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照?逆序?的方式存储的，并且它们的每个节点只能存储?一位?数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0?开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
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