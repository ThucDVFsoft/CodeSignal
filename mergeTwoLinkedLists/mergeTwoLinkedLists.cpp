// mergeTwoLinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};
ListNode<int>* createList(int a[], int n);
ListNode<int> *mergeTwoLinkedLists(ListNode<int> *head1, ListNode<int> *head2);
void Push(ListNode<int> **des, ListNode<int> **src);
void PushAndMove(ListNode<int> **current, ListNode<int> **des, ListNode<int> **src);

int main()
{
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6 };
	ListNode<int>* head1 = createList(arr1, sizeof(arr1) / sizeof(int));
	ListNode<int>* head2 = createList(arr2, sizeof(arr2) / sizeof(int));

	ListNode<int> *ret = mergeTwoLinkedLists(head1, head2);
	return 0;
}

ListNode<int>* createList(int a[], int n)
{
	ListNode<int> *head = NULL, *p = NULL;
	for (int i = 0; i < n; i++) {
		if (head == NULL) {
			head = p = new ListNode<int>(a[i]);
		}
		else {
			p->next = new ListNode<int>(a[i]);
			p = p->next;
		}
	}
	return head;
}

ListNode<int> *mergeTwoLinkedLists(ListNode<int> *head1, ListNode<int> *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	ListNode<int> dummyNode(0);
	ListNode<int> *currentNode = &dummyNode;
	dummyNode.next = NULL;

	while (head1 != NULL || head2 != NULL)
	{
		if (head1 == NULL)
		{
			while (head2 != NULL)
			{
				PushAndMove(&currentNode, &(currentNode->next), &head2);
			}
			break;
		}
		if (head2 == NULL)
		{
			while (head1 != NULL)
			{
				PushAndMove(&currentNode, &(currentNode->next), &head1);
			}
			break;
		}

		if (head1->value < head2->value)
		{
			PushAndMove(&currentNode, &(currentNode->next), &head1);
			continue;
		}
		else
		{
			PushAndMove(&currentNode, &(currentNode->next), &head2);
			continue;
		}
	}

	return dummyNode.next;
}

void PushAndMove(ListNode<int> **current, ListNode<int> **des, ListNode<int> **src)
{
	Push(des, src);
	*current = (*current)->next;
}

void Push(ListNode<int> **des, ListNode<int> **src)
{
	ListNode<int> *newNode = *src;
	*src = newNode->next;

	newNode->next = *des;
	*des = newNode;
}