#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
        struct ListNode *start, *end;
        start = end = head;
        
        if (!head)
        	return head;
        
        /* ok,如果链表不为空，就进行处理 */
        while (end!= NULL) {
        	if (!end->next)
        		break;
        		
         	while (end->next->val == start->val) {
         		end = end->next;
         		
         		if (!end->next)
         			break;
		}
         				
         	start->next = end->next;
         	start = end->next;
         	end = start;
	} 

        return head;     
}

struct ListNode *create_linklist(void)
{
	//struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *head;
	
	struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	head = node1;
	node1->val = 1;
	
	struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node1->next = node2;
	node2->val = 1;
	
	struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node2->next = node3;
	node3->val = 1;
	
	struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node3->next = node4;
	node4->val = 1;
	
	struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
	node4->next = node5;
	node5->next = NULL;
	node5->val = 2;
	
	return head;
}

void print_node(struct ListNode *head)
{
	struct ListNode *curr = head;
	
	while (curr != NULL) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}
}

int main(int argc, char *argv[]) 
{
	struct ListNode *head;
	head = create_linklist();
	
	deleteDuplicates(head);
	
	print_node(head);
	
	return 0;
}
