#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

class BinarySearchTree {
private:
  Node* root;

  Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }

  Node* insert(Node* root, int value) {
    if (root == nullptr) {
      return createNode(value);
    }
    if (value < root->data) {
      root->left = insert(root->left, value);
    } else if (value > root->data) {
      root->right = insert(root->right, value);
    }
      return root;
  }

  bool search(Node* root, int value) {
    if (root == nullptr) {
      return false;
    }
    if (root->data == value) {
      return true;
    } else if (value < root->data) {
      return search(root->left, value);
    } else {
      return search(root->right, value);
    }
  }

  void printTree(Node* root, int depth) {
    if (root == nullptr)
      return;

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; ++i)
      cout << "\t";
    cout << root->data << endl;
	
    printTree(root->left, depth + 1);
  }
  
public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int value) {
    root = insert(root, value);
  }

  bool contains(int value) {
    return search(root, value);
  }

  void printTree() {
    cout << "Binary Search Tree:" << endl;
    printTree(root, 0);
  }
};

int main() {
  BinarySearchTree tree;
  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.printTree();

  int searchValue = 30;
  if (tree.contains(searchValue)) {
    cout << "Searching for " << searchValue << ": Found" << endl;
  } else {
    cout << "Searching for " << searchValue << ": Not Found" << endl;
  }

  searchValue = 60;
  if (tree.contains(searchValue)) {
    cout << "Searching for " << searchValue << ": Found" << endl;
  } else {
    cout << "Searching for " << searchValue << ": Not Found" << endl;
  }
    
  return 0;
}
