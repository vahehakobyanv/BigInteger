#ifndef LISTNODE_H
#define LISTNODE_H
class ListNode
{
   struct Node
	{
		int data;
		Node* prev;
		Node* next;
	};
  Node* head;
  Node* tail;
  int length;
public:
  ListNode();
  void push(int);
  void pushFront(int);
  void print();
  void printReverse();
  int size(const ListNode& list);
  ListNode sum(const ListNode& list1,const ListNode& list2);
  ListNode sub(const ListNode& list1,const ListNode& list2);
  ListNode mul(const ListNode& list1,const ListNode& list2);
  ListNode div(const ListNode& list1,const ListNode& list2);
  ListNode res(const ListNode& list1,const ListNode& list2);
  bool isGreat( const ListNode& list1, const ListNode& list2);
  bool isLess(const ListNode& list1,const  ListNode& list2);
  bool isEqual( const ListNode& list1, const ListNode& list2);
};
#endif