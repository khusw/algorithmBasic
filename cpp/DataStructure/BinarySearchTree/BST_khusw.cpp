#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BTree {
   private:
    int size;
    Node* root;

   public:
    BTree();
    ~BTree();
    void insert_node(int data);
    void insert_node(int data, Node* node);
    void search_node(int data);
    void search_node(int data, Node* node);
    void delete_node(int data);
    void delete_node(int data, Node* node);
    void destroy_tree();
};

BTree::BTree() {
    this->size = 0;
    this->root = NULL;
}

BTree::~BTree() {
    destroy_tree();
}

void BTree::insert_node(int data) {
    if (!root) {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else {
        insert_node(data, root);
    }
}

void BTree::insert_node(int data, Node* node) {
    if (data < node->data) {
        if (!node->left) {
            node->left = new Node;
            node->left->data = data;
            node->left->left = NULL;
            node->left->right = NULL;
        } else {
            insert_node(data, node->left);
        }
    } else if (data > node->data) {
        if (!node->right) {
            node->right = new Node;
            node->right->data = data;
            node->right->left = NULL;
            node->right->right = NULL;
        } else {
            insert_node(data, node->right);
        }
    }
}

void BTree::search_node(int data) {
    if (!root) {
        cout << "empty tree !" << '\n';
        return;
    } else if (root->data == data) {
        cout << root->data << '\n';
        return;
    } else {
        search_node(data, root);
    }
}

void BTree::search_node(int data, Node* node) {
    if (node->data < data) {
        search_node(data, node->right);
    } else {
        search_node(data, node->left);
    }
}

void BTree::delete_node(int data) {
    if (!root) {
        cout << "empty tree !" << '\n';
    } else if (root && root->data == data) {
    } else {
    }
}

void BTree::destroy_tree() {
}

int main() {
    BTree* btree = new BTree();

    btree->insert_node(3);
    btree->insert_node(5);
    btree->insert_node(1);
    btree->insert_node(8);
    btree->insert_node(99);
    btree->insert_node(45);

    delete btree;
    return 0;
}