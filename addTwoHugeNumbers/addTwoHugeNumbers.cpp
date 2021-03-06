// addTwoHugeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	T value;
	ListNode *next;
};

// Definition for singly-linked list:
// template<typename T>
// struct ListNode<int> {
//   ListNode<int>(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode<int> *next;
// };
//

void printList(struct ListNode<int> *node);
ListNode<int>* addTwoHugeNumbers(ListNode<int> * head1, ListNode<int> * head2);
ListNode<int>* createList(std::vector<int> a, int n);
ListNode<int>* createList(int a[], int n);
std::string ToStringPadLeft(int value, unsigned int stringLength);
std::string AddString(std::string s1, std::string s2);
int Add(char c1, char c2, int &carry);
std::string GetString(ListNode<int> * head);
std::vector<std::string> SubStringBaseLength(std::string s, size_t baseLength);
std::vector<int> ToInt(std::string s, size_t baseLength);

int main()
{
	ListNode<int> *result = NULL;

	int arr1[] = { 1 };
	int arr2[] = { 9999, 9999, 9999, 9999, 9999, 9999 };
	ListNode<int>* head1 = createList(arr1, sizeof(arr1) / sizeof(int));
	ListNode<int>* head2 = createList(arr2, sizeof(arr2) / sizeof(int));

	ListNode<int>* ret = addTwoHugeNumbers(head1, head2);

	printList(result);
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


void printList(struct ListNode<int> *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->value);
		node = node->next;
	}
	printf("n");
}

ListNode<int>* addTwoHugeNumbers(ListNode<int> * head1, ListNode<int> * head2) {
	// first list is empty 
	ListNode<int>* result;
	if (head1 == NULL)
	{
		return head2;
	}

	// second list is empty 
	else if (head2 == NULL)
	{
		return head1;
	}

	std::string add1 = GetString(head1);
	std::string add2 = GetString(head2);

	std::string ret = AddString(add1, add2);
	std::vector<int> nums = ToInt(ret, 4);
	result = createList(nums, nums.size());

	return result;
}

ListNode<int>* createList(std::vector<int> a, int n)
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

std::string GetString(ListNode<int> * head)
{
	std::string str = "";
	while (head)
	{
		str += ToStringPadLeft(head->value, 4);
		head = head->next;
	}

	return str;
}

std::string ToStringPadLeft(int value, unsigned int stringLength)
{
	//#include <sstream>
	std::stringstream ss;
	//#include <iomanip>
	ss << std::setw(stringLength) << std::setfill('0') << value;

	return ss.str();
}

std::string ToStringPadLeft(std::string value, unsigned int stringLength)
{
	//#include <sstream>
	std::stringstream ss;
	//#include <iomanip>
	ss << std::setw(stringLength) << std::setfill('0') << value;

	return ss.str();
}

int Add(char c1, char c2, int &carry)
{
	int sum = carry + (c1 - 48) + (c2 - 48);
	if (sum > 9)
	{
		sum -= 10;
		carry = 1;
	}
	else
	{
		carry = 0;
	}
	return sum;
}

std::string AddString(std::string s1, std::string s2)
{
	std::string ret = "";
	size_t len1 = s1.length();
	size_t len2 = s2.length();
	size_t len = len1;
	if (len1 < len2)
	{
		s1 = ToStringPadLeft(s1, len2);
		len = len2;
	}
	else if (len1 > len2)
	{
		s2 = ToStringPadLeft(s2, len1);
		len = len1;
	}
	else {}

	int carry = 0;
	int sum = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		sum = Add(s1[i], s2[i], carry);
		ret = std::to_string(sum) + ret;
	}

	if (carry > 0)
	{
		ret = std::to_string(carry) + ret;
	}
	return ret;
}

std::vector<int> ToInt(std::string s, size_t baseLength)
{
	std::vector<int> ret;
	std::vector<std::string> strings = SubStringBaseLength(s, baseLength);
	size_t len = strings.size();
	int num = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		num = std::stoi(strings[i]);
		ret.push_back(num);
	}
	return ret;
}

std::vector<std::string> SubStringBaseLength(std::string s, size_t baseLength)
{
	std::vector<std::string> ret;
	size_t len = s.length();
	if (len < baseLength)
	{
		ret.push_back(s);
		return ret;
	}
	std::string temp = "";
	int count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		count++;
		temp = s[i] + temp;
		if (count == baseLength)
		{
			ret.push_back(temp);
			temp = "";
			count = 0;
		}
	}
	if (temp.compare("") != 0)
	{
		ret.push_back(temp);
	}
	return ret;
}