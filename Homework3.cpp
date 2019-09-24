#include <iostream>

using namespace std;


class Item
{
public:
	int val;
	Item *next, *pre;
	Item()
	{
		val = 0;
		next = 0;
		pre = 0;


	}
	Item(int val)
	{
		this->val = val;
		next = 0;
		pre = 0;
	}

};


class DLinkedList
{

	int size;
	Item *front;
	Item *back;

public:

	DLinkedList();
	DLinkedList(const DLinkedList &list);

	void push_back(Item *a);
	void push_front(Item *a);

	Item * pop_front();
	Item * pop_back();

	void insert(Item *a, int t); // insert the item a after the t-th element (head is the first element)
	void insertlist(const DLinkedList &list, int t); // insert the whole list a after the t-th element.
													 // you should make a copy of list first and then insert the copied version of the list. Do not modify or remove the list from the input
	void display(ostream &out);

	int getSize();
	Item * getfront();
	Item * getback();
	void swap(Item *p, Item *q); //swap two items pointed by p and q, you can assume that p and q are something in the list

	Item * extractmin(Item * start); // return the pointer of the min element after  "start",
									 // here you can assume user will always input a valid pointer start that points to an item in the list
	Item * extractmax(Item * start);  // return the pointer of the max element after "start"


};


class myStack
{
	DLinkedList list;
public:
	myStack();
	int getSize();
	void in(Item *a);
	Item *top();
	void out();
};

class myQueue
{
	DLinkedList list;
public:
	myQueue();
	int getSize();
	void in(Item *a);
	Item *front();
	void out();
};


















int main() 
{
	DLinkedList main;
	DLinkedList two;
	for (int i = 0; i < 11; i++)
	{
		Item *list = new Item(i);
		main.push_back(list);
	}
	for (int i = 32; i < 35; i++)
	{
		Item *list2 = new Item(i);
		two.push_back(list2);
	}
	
	cout << "Linked List:" << endl;
	main.display(cout);

	cout << endl << "Removing items to the front and end of linked list:" << endl;
	main.pop_back();
	main.pop_front();
	main.display(cout);

	cout << endl << "Insert item into the list:" << endl;
	Item i(5), i2(88);
	main.insert(&i, 6);
	main.insert(&i2, 2);
	main.display(cout);

	cout << endl << "Insert new list into the list:" << endl;
	main.insertlist(two, 6);
	main.display(cout);

	cout << endl << "Swap two items in the list:" << endl;
	main.swap(&i, &i2);
	main.display(cout);

	cout << endl << "Find the min and max after item:" << endl;
	DLinkedList minmax;
	Item *min = main.extractmin(&i2);
	Item *max = main.extractmax(&i);
	minmax.push_back(min);
	minmax.push_back(max);
	minmax.display(cout);
	cout << endl;

	myStack stack;

	cout << endl << "Top of stack:" << endl;
	stack.top();

	cout << "Pop item from stack:" << endl;
	stack.out();

	myQueue queue;

	cout << "Front of queue:" << endl;
	queue.front();

	cout << "Pop from queue:" << endl;
	queue.out();


	return 0;
}


















//Task 1
DLinkedList::DLinkedList()
{
	front = back = nullptr;
	size = 0;
}
DLinkedList::DLinkedList(const DLinkedList &list)
{
	size = list.size;
	front = list.front;
	back = list.back;
}

//Task 2
void DLinkedList::push_back(Item *a)
{
	if(front == nullptr)
		front = a; 

	if (back != nullptr)
		back->next = a;

	a->next = nullptr;
	a->pre = back;
	back = a;

	size++;
}
void DLinkedList::push_front(Item *a)
{
	a->next = front;
	a->pre = nullptr;
	front = a;
	size++;
}
Item * DLinkedList::pop_front()
{
	Item *q = front;
	front = front->next;
	front->pre = nullptr;
	size--;
	return q;
}
Item * DLinkedList::pop_back()
{
	Item *q = back;
	back = back->pre;
	back->next = 0;
	size--;
	return q;
}
Item * DLinkedList::getfront()
{
	return front;
}
Item * DLinkedList::getback()
{
	return back;
}
void DLinkedList::display(ostream &out)
{
	Item *w = front;
	for (int i = 0; i < size; i++)
	{
		if (w == nullptr)
		{
			cout << "screw" << endl;
			break;
		}
		cout << w->val << endl;
		w = w->next;
	}
}
void DLinkedList::swap(Item *p, Item *q)
{
	int temp = p->val;
	p->val = q->val;
	q->val = temp;
}


//Task 3
void DLinkedList::insert(Item *a, int t)
{
	Item *p = front;
	for (int i = 1; i < t; i++)
	{
		p = p->next;
	}
	a->next = p->next;
	p->next = a;

	size++;
}
void DLinkedList::insertlist(const DLinkedList &list, int t)
{
	Item *p = front;
	for (int i = 1; i < t; i++)
	{
		p = p->next;
	}
	DLinkedList copy = list;
	Item *copyfront = copy.getfront();
	Item *copyback = copy.getback();

	Item *q = p->next;
	p->next = copyfront;
	copyback->next = q;
	
	size += copy.getSize();

}
int DLinkedList::getSize()
{
	return size;
}

//Task 4
Item * DLinkedList::extractmin(Item * start)
{
	Item *min = start;
	Item *t = start;

	while (t != nullptr)
	{
		if (t->val < min->val)
			min = t;
		t = t->next;
	}

	return min;
}
Item * DLinkedList::extractmax(Item * start)
{
	Item *max = start;
	Item *t = start;

	while (t != nullptr)
	{
		if (t->val > max->val)
			max = t;
		t = t->next;
	}

	return max;
}

//Task 5
myStack::myStack()
{
	cout << "creating new stack..." << endl;
	for (int i = 122; i < 126; i++)
	{
		Item *stack = new Item(i);
		list.push_front(stack);
	}
	list.display(cout);
	cout << endl;
}
int myStack::getSize()
{
	return list.getSize();
}
void myStack::in(Item *a)
{
	list.push_front(a);
}
Item * myStack::top()
{
	Item *top = list.getfront();
	cout << top->val << endl << endl;
	return top;
	
}
void myStack::out()
{
	Item *pop = list.pop_front();
	list.display(cout);

}

myQueue::myQueue()
{
	cout << endl;
	cout << "creating new queue..." << endl;
	for (int i = 89; i < 94; i++)
	{
		Item *queue = new Item(i);
		list.push_back(queue);
	}
	list.display(cout);
	cout << endl;
}
int myQueue::getSize()
{
	return list.getSize();
}
void myQueue::in(Item *a)
{
	list.push_back(a);
}
Item *myQueue::front()
{
	Item *front = list.getfront();
	cout << front->val << endl << endl;
	return front;
}
void myQueue::out()
{
	Item *pop = list.pop_front();
	list.display(cout);
	cout << endl;
}


