// isListPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
// Definition for singly-linked list:
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};
//
ListNode<int>* createList(int a[], int n);
bool isListPalindrome(ListNode<int> * l);
std::stack<int> Storage(ListNode<int> * l);

int main()
{
	int a[] = { 1, 2,2,1,3 };
	ListNode<int>* pList = createList(a, sizeof(a) / sizeof(int));
	bool ret = isListPalindrome(pList);
    return 0;
}

ListNode<int>* createList(int a[], int n)
{
	ListNode<int> *head = NULL, *p = NULL;
	for (int i = 0; i<n; i++) {
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

bool isListPalindrome(ListNode<int> * l) {
	std::stack<int> storage = Storage(l);
	int linkedValue = 0;
	int stackValue = 0;
	while (l)
	{
		linkedValue = l->value;
		stackValue = storage.top();
		storage.pop();
		if (linkedValue != stackValue)
		{
			return false;
		}
		l = l->next;
	}
	return true;
}

std::stack<int> Storage(ListNode<int> * l)
{
	std::stack<int> storage;
	while (l)
	{
		storage.push(l->value);
		l = l->next;
	}

	return storage;
}

