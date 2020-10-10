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

Node* get(node* cur, int k) {
    while (k > 0 && cur->next != NULL) {
        k--;
        cur = cur->next;
    }
    return cur;
}
node* get_recursive(node* cur, int k) {
    if (k == 0) return cur;
    if (cur->next == NULL) {// if it is tail 
        return cur;
    }
    return get_recursive(cur->next, k - 1);
}

const int LARGE_NUMBER = (int)1e9;

Node* cyclicShift(Node* head, int k) {
    Node *newtail = get(head, k-1);
    Node *newhead = newtail->next;
    newtail->next = NULL;
    
    Node *tail = get(head, LARGE_NUMBER);
    tail->next = head;
    return newhead;
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