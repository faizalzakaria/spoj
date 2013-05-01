/**
   @author Faizal Zakaria
*/

#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node *left, *right;
    int aux, key, cnt, size;
};

const int MAX_INF = 1000000000;

typedef node * Treap;

void printT(Treap &root, int cnt);

inline void renewNode(Treap &root) {
    root->size = root->left->size + root->right->size + root->cnt;
}

inline void rotateLeft(Treap &root) {
    Treap t = root->left;
    root->left = t->right;
    t->right = root;
    renewNode(root);
    root = t;
    renewNode(t);
}

inline void rotateRight(Treap &root) {
    Treap t = root->right;
    root->right = t->left;
    t->left = root;
    renewNode(root);
    root = t;
    renewNode(t);
}

Treap nilTreap;

// memory management

const int MAX_QUERY = 200005;
node mem[MAX_QUERY];
vector<Treap> memStack;
int nodeCnt = 0;

inline Treap getNode() {
    Treap node;
    if (memStack.size()) {
        node = memStack.back();
        memStack.pop_back();
    } else {
        if (nodeCnt > MAX_QUERY) return nilTreap;
        node = &mem[nodeCnt++];
    }
    return node;
}

inline void insertT(Treap &root, int key) {
    if (root == nilTreap) {
        root = getNode();
        root->left = nilTreap;
        root->right = nilTreap;
        root->aux = rand() % MAX_INF;
        root->cnt = 1;
        root->size = 1;
        root->key = key;
        return;
    }

    if (root->key == key) return;
    else if (key < root->key) {
        insertT(root->left, key);
        if (root->left->aux < root->aux)
            rotateLeft(root);
    } else {
        insertT(root->right, key);
        if (root->right->aux < root->aux)
            rotateRight(root);
    }
    renewNode(root);
}

inline void deleteT(Treap &root, int key) {
    if (root == nilTreap) return;

    if (root->key == key) {
        if ((root->left == nilTreap) && (root->right == nilTreap)) {
            memStack.push_back(root);
            root = nilTreap;
            return;
        } else {
            if (root->left->aux < root->right->aux) {
                rotateLeft(root);
                deleteT(root->right, key);
            } else {
                rotateRight(root);
                deleteT(root->left, key);
            }
        }
    } else if (key < root->key) {
        deleteT(root->left, key);
    } else {
        deleteT(root->right, key);
    }
    renewNode(root);
}

#define INVALID_VALUE (MAX_INF + 1)
Treap t;

inline int getCountSmallerX(Treap &root, int x) {
    if (root == nilTreap) return 0;
    if (x < root->key) return getCountSmallerX(root->left, x);
    else if (x == root->key) return root->left->size + getCountSmallerX(root->right, x);
    else return root->left->size + root->cnt + getCountSmallerX(root->right, x);
}

inline int getKthSmaller(Treap &root, int k) {
    if (root == nilTreap) return INVALID_VALUE;
    if (k == root->left->size + root->cnt) return root->key;
    if (k > root->size) {
        return INVALID_VALUE;
    }
    else {
        if (k <= root->left->size) {
            return getKthSmaller(root->left, k);
        } else {
            return getKthSmaller(root->right, k - root->left->size - root->cnt);
        }
    }
}

void printT(Treap &root, int cnt) {
    if (root == nilTreap) {
        //printf("#(%d) ", cnt);
        return;
    }
    printf("%d-%d-%d(%d) ", root->key, root->size, root->cnt, cnt);
    printT(root->left, cnt+1);
    printT(root->right, cnt+1);
}

void printInorder(Treap &root, int cnt) {
    if (root == nilTreap) {
        //printf("#(%d) ", cnt);
        return;
    }
    printInorder(root->left, cnt+1);
    printf("%d(%d) ", root->key, cnt);
    printInorder(root->right, cnt+1);
}

inline void initTree() {
    nilTreap = new node();
    nilTreap->left = nilTreap;
    nilTreap->right = nilTreap;
    nilTreap->aux = MAX_INF;
    nilTreap->size = 0;
    nilTreap->cnt = 0;
    // TODO
    nilTreap->key = INVALID_VALUE;
}

int main() {
    int Q = 0;
    initTree();
    t = nilTreap;
    scanf("%d", &Q);
    while (Q--) {
        char op[32];
        int p1;
        scanf("%s %d", op, &p1);
        if (!strcmp(op, "I")) {
            insertT(t, p1);
#ifdef DEBUG
            printT(t, 1);
            cout << endl;
#endif
        } else if (!strcmp(op, "D")) {
            deleteT(t, p1);
#ifdef DEBUG
            printT(t, 1);
            cout << endl;
#endif
        } else if (!strcmp(op, "K")) {
            int ans = getKthSmaller(t, p1);
            if (ans == INVALID_VALUE) {
                printf("invalid\n");
            } else {
                printf("%d\n", ans);
            }
        } else if (!strcmp(op, "C")) {
            int ans = getCountSmallerX(t, p1);
            if (ans == INVALID_VALUE) {
                printf("invalid\n");
            } else {
                printf("%d\n", ans);
            }
        }
    }
}

