#include <iostream>
#include <string>

using namespace std;

struct  Student
{
	string code;
	string name;
	double grade;
};

struct Node
{
	Student value;
	Node* next;
};

void init(Node*& head)
{
	head = nullptr;
}

Node* createNode(Student x)
{
	Node* p = new Node;
	p->value = x;
	p->next = nullptr;

	return p;
}

bool isEmpty(Node* head)
{
	return head == nullptr;
}

void addHead(Node*& head, Student x)
{
	Node* p = createNode(x);
	p->next = head;
	head = p;
}

void addTail(Node*& head, Student x)
{
	Node* p = createNode(x);
	if (isEmpty(head) == true)
		head = p;
	else
	{
		Node* tail = head;
		while (tail->next != nullptr)
			tail = tail->next;
		tail->next = p;
	}
}

void outputStud(Student s)
{
	cout << "Code = " << s.code << endl;
	cout << "Name = " << s.name << endl;
	cout << "Grade = " << s.grade << endl;
	cout << "========";
}

void output(Node* head)
{
	Node* p = head;
	while (p != nullptr)
	{
		//cout << p->value << "\t";
		outputStud(p->value);
		p = p->next;
	}

	cout << endl;
}

Node* find(Node* head, string x)
{
	Node* p = head;
	while (p != nullptr && p->value.code != x)
		p = p->next;

	return p;
	/*while (p != nullptr)
	{
	if (p->value == x)
	return p;

	p = p->next;
	}

	return nullptr;*/
}

//Node* findMax(Node *head)
//{
//	Node *max = createNode(INT_MIN);
//	Node *p = head;
//	while (p != nullptr)
//	{
//		if (p->value > max->value)
//			max = p;
//
//		p = p->next;
//	}
//
//	return max;
//}

//bool isIncrease(Node *head)
//{
//	if (isEmpty(head) == true || head->next == nullptr)
//		return true;
//
//	Node *pre = head;
//	Node *p = pre->next;
//
//	while (p != nullptr)
//	{
//		if (pre->value > p->value)
//			return false;
//
//		pre = p;
//		p = pre->next;
//	}
//
//	return true;
//}

void deleteHead(Node*& head)
{
	if (!isEmpty(head))
	{
		Node* p = head;
		head = p->next;
		delete p;
	}
}

void clear(Node*& head)
{
	while (!isEmpty(head))
		deleteHead(head);
}

void addAfter(Node* head, string code, Student x)
{
	if (!isEmpty(head))
	{
		Node* p = find(head, code);
		if (p != nullptr)
		{
			Node* r = createNode(x);
			r->next = p->next;
			p->next = r;
		}
	}
}

void addBefore(Node*& head, string code, Student x)
{
	if (!isEmpty(head))
	{
		Node* p = head;
		Node* prev = nullptr;
		while (p != nullptr && p->value.code != code)
		{
			prev = p;
			p = p->next;
		}

		if (p != nullptr)
		{
			Node* r = createNode(x);
			if (prev == nullptr)
				head = r;
			else
				prev->next = r;
			r->next = p;
		}

	}
}

void addIndex(Node*& head, int idx, Student x)
{
	if (!isEmpty(head))
	{
		Node* p = head;
		Node* prev = nullptr;
		int count = 0;
		while (p != nullptr && count < idx)
		{
			prev = p;
			p = p->next;
			count++;
		}

		if (p != nullptr)
		{
			Node* r = createNode(x);
			if (prev == nullptr)
				head = r;
			else
				prev->next = r;
			r->next = p;
		}

	}
}

//void addInc(Node *&head, int x)
//{
//	Node *r = createNode(x);
//	if (isEmpty(head))
//		head = r;
//	else
//	{
//		Node *p = head;
//		Node *prev = nullptr;
//
//		while (p != nullptr && p->value < x)
//		{
//			prev = p;
//			p = p->next;
//
//		}
//
//		if (p != nullptr)
//		{
//
//			if (prev == nullptr)
//				head = r;
//			else
//				prev->next = r;
//			r->next = p;
//		}
//		else
//			prev->next = r;
//
//	}
//}

Student createStud(string code, string name, double grade)
{
	Student s;
	s.code = code;
	s.name = name;
	s.grade = grade;
	return s;
}

int main()
{
	Node* head;
	init(head);

	/*addHead(head, 10);
	addHead(head, 15);
	addHead(head, 30);
	addTail(head, 100);
	addHead(head, 5);
	addHead(head, 60);*/
	addTail(head, createStud("123", "NVA", 8.8));
	addTail(head, createStud("456", "NVA", 8.8));
	addTail(head, createStud("789", "NVA", 8.8));
	addTail(head, createStud("467", "NVA", 8.8));

	output(head);

	cout << "== chen == \n";
	addBefore(head, "123", createStud("999", "TTB", 9.9));
	output(head);

	cout << "== chen2 == \n";
	addIndex(head, 3, createStud("888", "TVE", 8.8));
	output(head);

	//addInc(head, 100);
	//output(head);

	/*deleteHead(head);
	output(head);
	deleteHead(head);
	output(head);*/

	clear(head);
	//output(head);

	/*Node *r = find(head, 999);
	if (r == nullptr)
	cout << "KHONG\n";
	else
	cout << "CO\n";

	Node *m = findMax(head);
	cout << "Max = " << m->value << endl;

	if (isIncrease(head) == true)
	cout << "TANG\n";
	else
	cout << "KHONG TANG\n";*/

	system("pause");

	return 0;
}