#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
        struct ListNode *curr, *tail;
        tail = head;
        bool is_loop = false;

        /* 先处理空链表的情况 */
        if (!head)
                return is_loop;
        
        /* 
         * ok,现在我们开始处理链表不为空的情况。
         * 
         * 判断链表中有没有环，不能通过判断节点的值来确定，考虑下面这种情况：head=[1,1,1,1],pos=1。
         * curr指向当前比较的节点，tail用来寻找环路的尾节点
         */

        /* 如果链表只有一个节点，并且next指向空，则一定不存在环路 */
        if (!tail->next)
                return is_loop;
        
        /* ok，到这里，我们开始处理链表节点数大于等于1的一般情况 */
        while (1) {
                /* 如果链表的尾结点指向了自身，则链表的尾结点就是环路节点。 */
                if (tail->next != tail) {
                        if (tail->next != NULL) {
                                curr = head;
                                while (curr != tail)  {
                                        if (tail->next == curr) {
                                                is_loop = true;
                                                return is_loop;
                                        } else 
                                                curr = curr->next;
                                }

                                tail = tail->next;
                        } else
                                return is_loop;
                } else {
                        is_loop = true;
                        return is_loop;
                }   
	}
}

struct ListNode *create_linklist(void)
{
	struct ListNode *head;
	
	struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next = node1;
	node1->val = 3;
	
	struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node1->next = node2;
	node2->val = 2;
	
	struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node2->next = node3;
	node3->val = 0;
	
	struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node3->next = node4;
	node4->val = -4;
	node4->next = node2;
	
	return head;
}

int main(void) {
	struct ListNode *head;
	bool is_loop;
	
	head = create_linklist(); 
	
	is_loop = hasCycle(head);
	printf("%d\n", is_loop); 
	
	return 0;
}
