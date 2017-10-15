#include <iostream>
#include <vector>
#include "ListNode.h"
ListNode::ListNode()
{
   this->head = nullptr;
   this->tail = nullptr;
   this->length = 0;
}
void ListNode::push(int elem)
{ 
	Node* node = new Node();
   if(head == nullptr){
     head = node;
     tail = node;
     head->data = elem;
     head->next = nullptr;
     tail->prev = nullptr;
     this->length++;
     return;
   }
   Node* currentNode = head;
   while(currentNode->next != nullptr){
     currentNode->next->prev = currentNode;
     currentNode = currentNode->next;
   }
   currentNode->next = node;
   tail = currentNode->next;
   currentNode->next->prev = currentNode;
   currentNode->next->data = elem;
   this->length++;
   return;
 }
void ListNode::pushFront(int elem)
{
    Node* node = new Node();
    if(head == nullptr)
	{
      head = node;
      tail = node;
      head->data = elem;
      head->next = nullptr;
      tail->prev = nullptr;
      this->length++;
      return;
    }
   Node* currentNode = head;
   head = node;
   head->data = elem;
   head->prev = nullptr;
   head->next = currentNode;
   head->next->prev = head;
   this->length++;
   return;
 }
void ListNode::print() {
   try{
     if(head == nullptr) {
       throw "Error";
     }
     Node* currNode = head;
     while(currNode != nullptr){
       std::cout<<currNode->data;
       currNode = currNode->next;
     }
   }
   catch(const char* x){
     std::cout<<x<<": Empty doubly linked list";
     exit(EXIT_FAILURE);
   }
 }
void ListNode::printReverse() {
   try{
     if(tail == nullptr) {
       throw "Error";
     }
     Node* currNode = tail;
     while(currNode != nullptr){
       std::cout<<currNode->data;
       currNode = currNode->prev;
     }
   }
   catch(const char* x){
     std::cout<<x<<": Empty doubly linked list";
     exit(EXIT_FAILURE);
   }
 }
ListNode ListNode::mul(const ListNode& list1,const ListNode& list2) {
	if(!list1.tail || !list2.tail)
	{
		ListNode lt;
		lt.push(0);
		return lt;
	}
	std::vector<ListNode> vector(list2.length);
	int exp = 0;
	Node* node2 = list2.tail;
	int tmp2 = node2->data;
	for(int ix = list2.length- 1; ix >=0  ; --ix)
	{
	int pass = 0;
	int tmp1 = 0;
	
	ListNode list3;
	for(int k = 0;k<exp;k++)
	{
		list3.pushFront(0);
	}
   Node* node1 = list1.tail; 
   tmp1 = node1->data;
   for(int i = list1.length- 1; i >=0  ; --i)
   {
	   if((tmp1*tmp2)+pass < 10)
	   {
		 list3.pushFront((tmp1 * tmp2) + pass);
         pass = 0;
	     if(node1->prev){
            node1 = node1->prev ;
            tmp1 = node1->data;
          }
         else{
            node1->prev = nullptr;
            tmp1 = 0;
          }
	   }
	   else {
         list3.pushFront(((tmp1 * tmp2) + pass )%10);
		 int k =pass=((tmp1 * tmp2) + pass )/10;
         pass = 0;
         pass=k;
          if(node1->prev){
            node1 = node1->prev ;
            tmp1 = node1->data;
           }
          else{
            node1->prev = nullptr;
            tmp1 = 0;
           }
         if(i == 0 && pass > 0){
            list3.pushFront(pass);
         }
       }
     }
   vector[exp] = list3;
   if(node2->prev){
          node2 = node2->prev ;
          tmp2 = node2->data;
          }
         else{
            node2->prev = nullptr;
            tmp2 = 0;
        }
   exp++;
	}
	ListNode lt;
	for(int ix = 0;ix <vector.size();ix++)
	{
		lt = sum(lt,vector[ix]);
	}
   return lt;
   }
ListNode ListNode::sum(const ListNode& list1,const ListNode& list2) {
  if(!list1.tail && list2.tail){
     return list2;
  }
  if(list1.tail && !list2.tail){
   return list1;
  }
  try{
    if(!list1.tail && !list2.tail){
      throw "Error";
    }
  }
   catch(const char* x){
    std::cout<<x<<": Two List's is empty";
    exit(EXIT_FAILURE);
   }
   int max_length = 0;
   if(list1.length >= list2.length) {
      max_length = list1.length;
   }
   else {
      max_length = list2.length;
   }
   int pass = 0;
   int tmp_data1;
   int tmp_data2;
   ListNode list3;
   Node* node1 = list1.tail;
   Node* node2 = list2.tail;
   tmp_data1 = node1->data;
   tmp_data2 = node2->data;
   for(int i = max_length - 1; i >=0  ; --i){
      if(tmp_data1 + tmp_data2 + pass < 10){
        list3.pushFront(tmp_data1 + tmp_data2 + pass);
         pass = 0;
          if(node1->prev){
            node1 = node1->prev ;
            tmp_data1 = node1->data;
          }
         else{
            node1->prev = nullptr;
            tmp_data1 = 0;
          }
         if(node2->prev){
          node2 = node2->prev ;
          tmp_data2 = node2->data;
          }
         else{
            node2->prev = nullptr;
            tmp_data2 = 0;
        }
      }
       else {
         list3.pushFront(tmp_data1 + tmp_data2 + pass - 10);
         pass = 0;
         pass++;
          if(node1->prev){
            node1 = node1->prev ;
            tmp_data1 = node1->data;
           }
          else{
            node1->prev = nullptr;
            tmp_data1 = 0;
           }
          if(node2->prev){
          node2 = node2->prev ;
          tmp_data2 = node2->data;
          }
          else{
            node2->prev = nullptr;
            tmp_data2 = 0;
          }
         if(i == 0 && pass > 0){
            list3.pushFront(pass);
         }
       }
     }
   return list3;
}

ListNode ListNode::sub(const ListNode& list1,const ListNode& list2) {
   int max_length = 0;
   ListNode sub1;
   ListNode sub2;
   bool isPosit;
   if(list1.length > list2.length) {
       max_length = list1.length;
       sub1 = list1;
       sub2 = list2;
       isPosit = true;
    }
    else if(list1.length < list2.length) {
       max_length = list2.length;
       sub1 = list2;
       sub2 = list1;
       isPosit = false;
    }
    else {
      max_length = list1.length;
      Node* node1_head = list1.head;
      Node* node2_head = list2.head;
      for(int i = 0; i < max_length; ++i){
        if(node1_head->data == node2_head->data){
          node1_head = node1_head->next;
          node2_head = node2_head->next;
        }
        else if(node1_head->data > node2_head->data){
         sub1 = list1;
         sub2 = list2;
         isPosit = true;
         break;
        }
        else if(node1_head->data < node2_head->data){
         sub1 = list2;
         sub2 = list1;
         isPosit = false;
         break;
        }
      }
    }
    ListNode list4;
    if(!sub1.head){
        list4.pushFront(0);
        return list4;
    }
    Node* node1 = sub1.tail;
    Node* node2 = sub2.tail;
    int tmp_data1;
    int tmp_data2;
    for(int i = max_length-1; i >= 0; --i){
      tmp_data1 = node1->data;
      tmp_data2 = node2->data;
      if(tmp_data1 >= tmp_data2){
         if(i == 0 && isPosit == false)
           list4.pushFront((tmp_data1 - tmp_data2)*(-1));
         else
           list4.pushFront(tmp_data1 - tmp_data2);
        if(node2->prev){
           node2 = node2->prev ;
           node1 = node1->prev;
        }
        else{
           node2->prev = nullptr;
           node2->data = 0;
           if(node1->prev)
           node1 = node1->prev;

        }
      }
      else{
        Node* currentNode = node1;
        while(currentNode->prev){
          currentNode = currentNode->prev;
          if(currentNode->data > 0){
            currentNode->data--;
            break;
          }
        }
        while(currentNode->next != node1){
          currentNode = currentNode->next;
          currentNode->data += 9;
        }
         if(i == 0 && isPosit == false)
           list4.pushFront((tmp_data1 + 10 - tmp_data2)*(-1));
         else
           list4.pushFront(tmp_data1 + 10 - tmp_data2);
         if(node2->prev){
           node2 = node2->prev ;
           node1 = node1->prev;
        }
        else{
           node2->prev = nullptr;
           if(node1->prev)
           node1 = node1->prev;
           node2->data = 0;
        }
      }
    }
    if(list4.head->data == 0){
      Node* tmp_node;
      while(list4.head->data == 0 && list4.head != list4.tail){
        tmp_node = list4.head;
        list4.head = list4.head->next;
        tmp_node->next = nullptr;
        delete tmp_node;
      }
      if(isPosit == false){
        list4.head->data = -1* list4.head->data;
      }
    }
    return list4;
 }
 bool ListNode::great( const ListNode& list1,const ListNode& list2)
 {
	 if(list1.length > list2.length)
	 {
		 return true;
	 }
	 else if(list1.length < list2.length)
	 {
		 return false;
	 }
	 Node* lt1 = list1.head;
	 Node* lt2 = list2.head;
	 while(lt1 != nullptr)
	{
		if(lt1->data > lt2->data)
		{
			return true;
		}
		if(lt1->data < lt2->data)
		{
			return false;
		}
		lt1 = lt1->next;
		lt2 = lt2->next;
	}
	 return false;
 }
  bool ListNode::less(const ListNode& list1,const ListNode& list2)
 {
	 if(list1.length > list2.length)
	 {
		 return false;
	 }
	 else if(list1.length < list2.length)
	 {
		 return true;
	 }
	 
	 Node* lt1 = list1.head;
	 Node* lt2 = list2.head;
	 while(lt1 != nullptr)
	{
		if(lt1->data > lt2->data)
		{
			return false;
		}
		if(lt1->data < lt2->data)
		{
			return true;
		}
		lt1 = lt1->next;
		lt2 = lt2->next;
	}
	 return false;
 }
   bool ListNode::equal( const ListNode& list1, const ListNode& list2)
 {
	 if(list1.length != list2.length)
	 {
		 return false;
	 }
	 Node* lt1 = list1.head;
	 Node* lt2 = list2.head;
	 while(lt1 != nullptr)
	{
		if(lt1->data != lt2->data)
		{
			return false;
		}
		lt1 = lt1->next;
		lt2 = lt2->next;
	}
	 return true;
 }
   ListNode ListNode::div(const ListNode& list1,const ListNode& list2)
{
	if(less(list1,list2) == true)
	{
		ListNode lt3;
		lt3.pushFront(0);
		return lt3;
	}
	else if(equal(list1,list2) == true) 
	{
		ListNode lt3;
		lt3.pushFront(1);
		return lt3;
	}
	else if(list2.length == 1 && list2.head->data ==1)
	 {
		 return list1;
	 }
	ListNode div1 = list1;
	ListNode div2 = list2;
	std::vector<int> vec;
	ListNode lt;
	while(div1.head != nullptr)
	{
		lt.push(div1.head->data);
		lt.print();

		if(less(lt,div2) == true)
		{
			vec.push_back(0);
		}
		else
		{
			bool tr =true;
			for(int i = 1;i <9;++i)
			{
				ListNode l1,l2;
				l1.push(i);
				l2.push(i+1);
				if((great(lt,mul(l1,div2)) == true || equal(lt,mul(l1,div2))==true) && less(lt,mul(l2,div2))==true && tr)
				{
					vec.push_back(i);
					ListNode mul1 = mul(l1,div2);
					ListNode lt1;
					lt1 = sub(lt,mul1);
					lt = lt1;
					lt.print();
					tr = false;
				}
			}
		}
		label:
		div1.head = div1.head->next;
	}
		bool havefirst = false;
		ListNode lt3;
		for(int i = 0;i<vec.size();i++)
		{
			if(vec[i] == 0 && havefirst)
			{
			lt3.pushFront(vec[i]);
			}
			if(vec[i] != 0)
			{
				lt3.pushFront(vec[i]);
				havefirst = true;
			}
		}
		return lt3;
}