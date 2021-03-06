// rearrangeLastN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>

template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};
ListNode<int>* createList(int a[], int n);
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n);

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	ListNode<int>* head1 = createList(arr1, sizeof(arr1) / sizeof(int));

	ListNode<int> *ret = rearrangeLastN(head1, 3);
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

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
	if (n == 0 || l == NULL || l->next == NULL) return l;

	int count = 0;
	ListNode<int> * current = l;
	ListNode<int> * prev = l;
	while (current != NULL)
	{
		count++;
		prev = current;
		current = current->next;
	}
	ListNode<int>* oldEnd = prev;//Node 5

	if (count == n) return l;
	int lastElement = count - n;
	current = l;
	for (int i = 0; i < lastElement - 1; i++)//Move to Node 2
	{
		current = current->next;
	}
	ListNode<int>* newLast = current; //Node 2

	ListNode<int>* newStart = current->next; //Node 3
	newLast->next = NULL;
	oldEnd->next = l;//Node 5->next = Node1
	return newStart; //Node 3
}