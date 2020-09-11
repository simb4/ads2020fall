#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct node {
	int val;
	node *nxt, *prev;
	node() { val = 0, nxt = NULL; }
	node(int x) { val = x, nxt = NULL; }
};

struct list {
	node* head = NULL;

	node* get(int p) {
		if (p < 0) {
			cout << "[Error] Index out of bounds (get)\n";
			exit(0);
		}
		node *cur = head;
		for (int i = 0; i < p && cur != NULL; i++)
			cur = cur->nxt;
		return cur;
	}

	node* get_tail() {
		if (head == NULL) {
			cout << "[Error] the list has no tail\n";
			exit(0);
			return NULL;
		}
		node *tail = head;
		while (tail->nxt != NULL)
			tail = tail->nxt;
		return tail;
	}

	void append(int x) { // add to the end
		if (head == NULL) {
			head = new node(x);
			return;
		}
		node *tail = get_tail();
		tail->nxt = new node(x);
	}

	void insert(int p, int x) { // list.get(p).val == x at the end
		if (p < 0) {
			cout << "[Error] negative index (insert)\n";
			exit(0);
		}
		if (p == 0) {
			node *newNode = new node(x);
			newNode->nxt = head;
			head = newNode;
			return;
		}
		node *prev = get(p - 1);
		if (prev == NULL) {
			cout << "[Error] index out of bounds (insert)\n";
			exit(0);
		}
		node *newNode = new node(x);
		newNode->nxt = prev->nxt;
		prev->nxt = newNode;
	}

	void del(int p) {
		if (p < 0 || head == NULL) {
			cout << "[Error] delete error\n";
			exit(0);
		}
		if (p == 0) {
			node *tmp = head;
			head = head->nxt;
			delete tmp;
			return;
		}
		node *cur = get(p-1);
		node *toDel = cur->nxt;
		if (cur == NULL || toDel == NULL) {
			cout << "[Error] index out of bounds (delete)\n";
			exit(0);
		}
		cur->nxt = toDel->nxt;
		delete toDel;
	}

	void out() {
		node *cur = head;
		while (cur != NULL) {
			cout << cur->val << " ";
			cur = cur->nxt;
		}
		cout << "\n";
	}

	void eraseAll(int x) { // aim : O(n) - linear time

	}
};


void reverse(list *L) {	// aim : O(n) = linear time algorithm

}

int main() {

	list* L = new list();
	list* R = L;

	L->append(10);
	L->append(5);
	R->append(6);
	R->append(7);
	L->out();
	L->insert(1, 4);
	L->out();
	L->insert(0, 3);
	L->out();
	L->insert(6, 8);
	L->out();

	L->del(1);
	L->out();
	L->del(0);
	L->out();
	L->del(4);
	L->out();


	
	return 0;
}

