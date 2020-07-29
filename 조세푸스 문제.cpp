#include<iostream>
using namespace std;
#include<set>
#include<iterator>

class Node {
public:

	int elem;
	Node* next;
	Node(int a)
	{
		elem = a;
		next = NULL;
	}
};

class List {
public:
	Node * cur;
	int sz;
	List() { cur = NULL; sz = 0; }

	void insert(int a)
	{
		Node* v = new Node(a);
		if (cur == NULL)
		{
			cur = v;
			v->next = v;
		}
		else
		{
			v->next = cur->next;
			cur->next = v;
		}
		sz++;
	}

	void remove(int a)
	{
		Node* v;
		Node* old = cur->next;
		cur->next = old->next;
		int chk = 0;
		v = old;
		sz--;
		if (sz != 2)
		{
			v = v->next;
			chk++;
		}
		else
		{
			return;
		}
		delete old;
		while (chk != a)
		{
			v = v->next;
			chk++;
		}
		Node* prev;
		while (sz != 2)
		{
			sz--;
			old = v;
			prev = find(old);
			v = v->next;
			if (old == cur)
			{
				cur = v;
			}
			if (old == cur->next)
			{
				cur->next = old->next;
			}
			prev->next = old->next;
			delete old;
			chk = 1;
			while (chk != a)

			{
				v = v->next;
				chk++;
			}


		}
		





	}

	Node* find(Node* a)
	{
		Node* p = cur;
		while (p->next != a)
		{
			p = p->next;
		}
		return p;
	}


	void init()
	{
		while (sz != 0)
		{
			sz--;
			Node* v = cur->next;
			delete v;
			v = cur;
			delete v;
			cur = NULL;
			sz = 0;
		}
	}
};


int main()
{
	int t;
	cin >> t;
	List l;
	set<int>s;
	set<int>::iterator it;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		for (int j = n; j >= 1; j--)
		{
			l.insert(j);
		}
		l.remove(k);
		s.insert(l.cur->elem);
		s.insert(l.cur->next->elem);
		for (it = s.begin(); it != s.end(); it++)
		{
			if (it == s.begin())
				cout << *it << " ";
			else
				cout << *it << endl;
		}

		s.clear();
		l.init();
		
	}
}
