#include <iostream>
using namespace std;

struct Node {
    string word;
    Node* next;

    Node() {}

    Node(string word) {
        this->word = word;
        this->next = NULL;
    }
};

// your code goes here

Node* get(Node* cur, int k) {
    /* k-th element of linked list */
    if (k == 0) return cur;
    if (cur->next == NULL) return cur;
    return get(cur->next, k - 1);
}

Node* cyclicShift(Node* head, int k) {
    Node* last = get(head, (int)1e9); // 10^9 = inf
    last->next = head;

    Node* newLast = get(head, k-1);
    Node* newHead = newLast->next;
    newLast->next = NULL;

    return newHead;
}

void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->word << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n; cin >> n;
    int k; cin >> k;
    Node* head;
    Node* cur;
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        if (i == 0) {
            head = new Node(word);
            cur = head;
        } else {
            cur->next = new Node(word);
            cur = cur->next;
        }
    }

    head = cyclicShift(head, k);
    print(head);
}