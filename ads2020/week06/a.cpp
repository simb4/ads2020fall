#include <iostream>
#include <cassert>
using namespace std;

struct node {
    int key;
    node *left;
    node *right;
    node() { left = right = NULL; }
    node(int key) { 
        left = right = NULL;
        this->key = key;
    }
} *root;


node* insert(node *&v, int x) {
    if (v == NULL) {
        v = new node(x);
        return v;
    }
    if (x <= v->key)
        return insert(v->left, x);
    // v->key < x
    return insert(v->right, x);
}

node* find(node *v, int x) {
    if (v == NULL) return NULL;
    if (v->key == x) return v;
    if (x <= v->key)
        return find(v->left, x);
    return find(v->right, x);
}

void del(node *&v) {
    cout << "At " << v->key << "\n";
    if (v->left == NULL && v->right == NULL) {
        cout << "eliminating \n";
        if (v != NULL)
            free(v);
        v = NULL;
        return;
    }
    // if no left child
    if (v->left == NULL) {
        node *tmp = v;
        v = v->right; // replace me with right son
        free(tmp); // free memory of old v
        return;
    }

    node *rightmost = v->left;
    while (rightmost->right != NULL)
        rightmost = rightmost->right;

    cout << "rightmost " << rightmost->key << "\n";
    
    swap(v->key, rightmost->key);
    del(rightmost);
}

void inorder(node *v) {
    if (v == NULL) return;
    inorder(v->left);
    cout << v->key << ' ';
    inorder(v->right);
}

void print(node *v, int tab = 0) {
    for (int i = 0; i < tab; i++) cout << "  ";
    if (v == NULL) {
        cout << "-\n";
        return;
    }
    cout << v->key << "\n";
    if (!(v->left == NULL && v->right == NULL)) {
        print(v->left, tab + 1);
        print(v->right, tab + 1);
    }
}

// int sqr(int &x) {
//     x = x * x;
//     return x;
// }

int main() {

    // int y = 2;
    // sqr(y);
    // cout << y << "\n"; // 4

    int n, x;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch >> x;
        if (ch == '+') { // insert x
            insert(root, x);
            print(root); cout << "\n";
        } else if (ch == '?') { // find x
            cout << (find(root, x) != NULL ? "YES" : "NO") << "\n";
        } else { // del x
            node *toDel = find(root, x);
            if (toDel == NULL)
                continue;
            del(toDel);
            print(root); cout << "\n";
        }

        cout << "~~~~~~~~\n";

    }


}