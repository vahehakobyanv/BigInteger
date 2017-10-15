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
  ListNode sum(const ListNode& list1,const ListNode& list2);
  ListNode sub(const ListNode& list1,const ListNode& list2);
  ListNode mul(const ListNode& list1,const ListNode& list2);
  bool great( ListNode& list1, ListNode& list2);
  bool less( ListNode& list1, ListNode& list2);
  bool equal( ListNode& list1, ListNode& list2);
};
#endif