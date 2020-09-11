#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct node {
	int val;
	node *nxt;
	node() { val = 0; }
	node(int x) { val = x; }
};

struct list {
	node* head;

	node* get(int p) {
		node *cur = head;
		for (int i = 0; i < p && cur != NULL; i++)
			cur = cur->nxt;
		return cur;
	}

	void append(int x) { // add to the end
		node *cur = head;

		if (head == NULL) {
			head = new node(x);
			return;
		}
		
		/* go to the next, until there is next */
		while (cur->nxt != NULL)
			cur = cur->nxt;

		cur->nxt = new node(x); // new node(x) returns node*
	}

	void out() { // void out(...; this) in python ~ self
		node *cur = head;
		while(cur != NULL) {
			cout << cur->val << " ";
			cur = cur->nxt;
		}
		cout << "\n";
	}

	void del(int p) {
		node *cur = head;
		if (p == 0) {
			head = head->nxt;
			delete cur;
			return;
		}
		/* go to the next, until there is next */
		cur = get(p-1);

		node *todel = cur->nxt;
		cur->nxt = todel->nxt;
		delete todel;
	}

	void insert(int p, int x) {
		/* it was: a1,a2,...,a[p], a[p+1] */
		/* turn to: a1,a2,...,a[p-1], x, a[p], a[p+1] */
		node* newNode = new node(x);
		if (p == 0) {
			newNode->nxt = head;
			head = newNode;
			return;
		}
		node *cur = get(p-1);
		if (cur == NULL) {
			cerr << "My error: index out of bounds\n";
			return;
		}
		newNode->nxt = cur->nxt;
		cur->nxt = newNode;
	}
};


int a[100];

int main() {
	list* L = new list();

	L->append(10);
	L->append(5);
	L->append(6);
	L->append(2);
	L->append(4);
	L->out();
	L->del(0);
	L->out();
	L->del(2);
	L->out();
	L->insert(0, 1);
	L->out();
	L->insert(2, 3);
	L->out();

	L->insert(10, 3);



	return 0;
}

