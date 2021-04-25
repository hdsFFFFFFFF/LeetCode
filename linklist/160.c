/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        /* 
         * 先处理两个链表不相交的情况
         */
        /* 如果其中一个链表为空，则一定不会相交，直接返回即可 */
        if (!headA)
                return headA;
        
        if (!headB)
                return headB;
        
        /* ok,现在我们拥有两个不为空的链表，接下来开始处理 */
        /* 
         * 注意，相交节点既要值相同，也要物理地址相同。仅仅值相同，不是相交节点
         */
        /* 两条链表可能是完全相交的，即l1=[1,2,3,4],l2=[1,2,3,4]。我们先处理这种情况 */
        if (headA == headB)
                return headA;

        /* ok，到这里，链表是不完全相交的，接下来开始处理 */
        struct ListNode *curr, *tmp;
        curr = headA;
        tmp = headB;

        /* 
         * 当链表A仅有一个节点，如果它是相交节点，它只可能是链表B的尾结点
         * 所以我们可以比较一下B尾结点的地址与A节点的地址是否相同：
         *      相同：则为相交节点，返回节点值
         *      不同：不是相交节点，返回NULL
         */
        if (!curr->next) {
                if (!tmp->next)
                        return NULL;
                        
                while (tmp->next != NULL)
                        tmp = tmp->next;
                if (tmp == curr)
                        return curr;
                else
                        return NULL;
        }

        /* 当B只有一个节点，同上 */
        if (!tmp->next) {
                while (curr->next != NULL)
                        curr = curr->next;

                if (curr == tmp)
                        return curr;
                else
                        return NULL;
        }
        
        /* ok，到这里，两条链表拥有至少两个节点。接下来，我们处理这种常规情况 */
        while (1) {
                if (curr != NULL) {
                        /* B链表可能是A的相交链表 */
                        if (tmp == curr->next)
                                return tmp;
                        
                        while (tmp->next != NULL) {
                                /* A链表可能是B的相交链表 */
                                if (tmp->next == curr)
                                        return tmp->next;
                                
                                tmp = tmp->next;
                        }

                        curr = curr->next;
                        tmp = headB;
                } else
                        return NULL;
        }
}
