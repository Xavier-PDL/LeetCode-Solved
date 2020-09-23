#include <stdio.h>

/*
 *  Input: 1->2->3->4->5->NULL
 *  Output: 5->4->3->2->1->NULL
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* pNode, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%i\n", pNode->val);
        if(pNode->next)
            pNode = pNode->next;
    }
    printf("\n\n");
}

#define pl(n) printf("%d\n", n->val)
ListNode* reverseList(ListNode* head, int length)
{
    if(!head)
        return head;

    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

#define ARR_SIZE(a,t) sizeof(a) / sizeof(t)
int main()
{
    int nums[] = {1,2,3,4,5};
    ListNode* pHead = new ListNode;
    ListNode* pNode = pHead;
    for(int i = 0; i < ARR_SIZE(nums, int); i++)
    {
        pNode->val = nums[i];
        if(i < ARR_SIZE(nums, int) - 1)
        {
            pNode->next = new ListNode;
            pNode = pNode->next;
        }
    }

    pHead = reverseList(pHead, ARR_SIZE(nums, int));
    pNode = pHead;

    printList(pNode, ARR_SIZE(nums, int));

}
