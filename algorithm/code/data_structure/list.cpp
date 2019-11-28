#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *next;
	Node(int v = 0, Node* p = nullptr) : data(v), next(p) {};
}Node;


class List
{
private:
	Node *head;
public:
	List();
	~List();
	void append(int value);				// ����β�����Ԫ��
	void insert(int value, int pos);	// �� pos λ�ò�������
	void deleteNode(int pos);			// ɾ��ָ��λ�õĽ��
	int length();						// ��ȡ����ĳ���
	void printList();					// ��ӡ����
};
List::List()
{
	head = new Node(0);
}

List::~List()
{
	;
}


void List::insert(int value, int pos)
{
	if (pos < 0)
	{
		cout << "����ʧ�ܣ������λ��Ӧ�� >= 0" << endl;
		return;
	}
	if (pos >= length())
	{
		append(value);
		return;
	}
	
	Node* p = head;
	int index = 0;	// ��һ����������Ϊ 0
	while (p)
	{
		if (index == pos)
		{
			Node *node = new Node(value);
			node->next = p->next;
			p->next = node;
			break;	
		}
		p = p->next;
		index++;
	}
	printList();
}

void List::append(int value)
{
	Node *node = new Node(value);
	Node *p = this->head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = node;
	printList();
}

void List::deleteNode(int pos)  // pos ����
{
	if (pos < 0 || pos > length() - 1)
	{
		cout << "��ɾ���ݲ���������" << endl;
		return;
	}
	Node *p = head;
	Node *pnext = p->next;
	int cnt = 0;
	while (pnext)
	{
		if (cnt == pos)
		{
			p->next = pnext->next;
			delete[] pnext;
			break;
		}
		p = pnext;
		pnext = pnext->next;
		cnt++;
	}
	printList();
}

int List::length()
{
	int cnt = 0;
	Node* p = head->next;
	while (p)
	{
		cnt++;
		p = p->next;
	}
	cout << "length:" << cnt << endl;
	return cnt;
}

void List::printList()
{
	Node *p = head->next;
	while (p)
	{
		cout << p->data << " -> ";
		p = p->next;
	}	
	cout << "nullptr" << endl;
}

int main()
{
	List mylist;
	mylist.append(7);
	mylist.append(9);
	mylist.length();
	mylist.insert(1, 0);
	mylist.insert(10, 3);
	mylist.insert(5, 2);
	mylist.insert(-1, -3);
	mylist.insert(-99, 99);
	mylist.deleteNode(0);
	mylist.deleteNode(2);
	mylist.deleteNode(4);
	//mylist


	system("pause");
}


