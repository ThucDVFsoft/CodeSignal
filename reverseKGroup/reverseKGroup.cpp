// reverseKGroup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *Remove(ListNode *head, int k);
ListNode *reverseList(ListNode *&head, int k);
void printList(ListNode* h);
ListNode* createList(int a[], int n);
ListNode *reverseKGroup(ListNode *head, int k);

int main()
{
	int a[] = { 1000, 1000 };
	ListNode* pList = createList(a, sizeof(a) / sizeof(int));

	int k = 1000;

	ListNode *p = Remove(pList, k);
	printList(p);
    return 0;
}

void printList(ListNode* h)
{
	while (h != NULL) {
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

ListNode* createList(int a[], int n)
{
	ListNode *head = NULL, *p = NULL;
	for (int i = 0; i<n; i++) {
		if (head == NULL) {
			head = p = new ListNode(a[i]);
		}
		else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}

ListNode *Remove(ListNode *head, int k)
{
	ListNode *current = head;
	ListNode *prev = NULL;

	while (current != NULL) {
		if (current->val == k)
		{
			if (prev)
			{
				prev->next = current->next;
			}
			else
			{
				head = current->next;
			}
		}
		else
		{
			prev = current;
		}
		current = current->next;
	}
	return head;
}

ListNode *reverseKGroup(ListNode *head, int k) {
	if (k <= 0) return head;
	ListNode fake(0);
	fake.next = head;
	ListNode* p = &fake;

	while (p) {
		p->next = reverseList(p->next, k);
		for (int i = 0; p && i<k; i++) {
			p = p->next;
		}
	}

	return fake.next;
}

ListNode *reverseList(ListNode *&head, int k) {
	ListNode* pEnd = head;
	while (pEnd && k>0) {
		pEnd = pEnd->next;
		k--;
	}
	if (k>0) return head;

	ListNode *pHead = pEnd, *p = head;
	while (p != pEnd) {
		ListNode *q = p->next;
		p->next = pHead;
		pHead = p;
		p = q;
	}
	return pHead;
}
