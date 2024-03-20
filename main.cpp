#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class BinarySearchTree {
private:
  int tree[201];

  void checkAdjust(int index) {
    int parent = getParentIndex(index);
    if (index == 1 || tree[parent] > tree[index]) {
      return;
    } else {
      int temp = tree[parent];
      tree[parent] = tree[index];
      tree[index] = temp;
      checkAdjust(parent);
    }
  }

  int getParentIndex(int i) {
    if (i % 2 == 0) {
      return i / 2;
    } else {
      return (i - 1) / 2;
    }
  }

  int getLastIndex() {
    int i = 1;
    while (true) {
      if (tree[i] == -1) {
        return i;
      }
      i++;
    }
    cout << "ERROR: Tree is full" << endl;
    return -1;
  }

  int searchIndex(int value) {
    for (int i = 1; i <= 100; i++) {
      if (tree[i] == value) {
        return i;
      }
    }
    return -1;
  }

  void shiftDown(int index) {
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int largest = index;

    if (leftChild <= 100 && tree[leftChild] > tree[largest]) {
      largest = leftChild;
    }

    if (rightChild <= 100 && tree[rightChild] > tree[largest]) {
      largest = rightChild;
    }

    if (largest != index) {
      swap(tree[index], tree[largest]);
      shiftDown(largest);
    }
  }

public:
  BinarySearchTree() {
    clear();
  }

  void insert(int value) {
    int index = getLastIndex();
    if (index == 100) {
      return;
    }
    tree[index] = value;
    checkAdjust(index);
  }

  void printIndented(int index, int depth = 0) {
    if (index <= 100 && tree[index] != -1) {
      printIndented(2 * index + 1, depth + 1);
      for (int i = 0; i < depth; ++i) {
        cout << "\t";
      }
      cout << tree[index] << endl;
      printIndented(2 * index, depth + 1);
    }
  }

  void printTree() {
    cout << "Binary Search Tree:" << endl;
    printIndented(1);
  }

   void addFromFile() {
    int numCount;
    cout << "Enter the number of numbers you want to add from file: ";
    cin >> numCount;
    ifstream file("nums.txt");
    int num;
    for (int i = 0; i < numCount && file >> num; ++i) {
      insert(num);
    }
    file.close();
  }

  void clear() {
    for (int i = 0; i < 201; i++) {
      tree[i] = -1;
    }
    tree[0] = -2;
  }

  void searchNumber() {
    int value;
    cout << "Enter number to search: ";
    cin >> value;
    int index = searchIndex(value);
    if (index != -1) {
      cout << "Number " << value << " is found in the tree." << endl;
    } else {
      cout << "Number " << value << " is not found in the tree." << endl;
    }
  }

  void deleteNumber() {
    int value;
    cout << "Enter number to delete: ";
    cin >> value;
    int index = searchIndex(value);
    if (index != -1) {
      tree[index] = -1;
      shiftDown(index);
      cout << "Number " << value << " has been deleted from the tree." << endl;
    } else {
      cout << "Number " << value << " is not found in the tree." << endl;
    }
  }

  void addNumbersManually() {
    int numCount;
    cout << "Enter the number of numbers you want to add manually: ";
    cin >> numCount;
    cout << "Enter " << numCount << " numbers separated by spaces: ";
    for (int i = 0; i < numCount; ++i) {
      int num;
      cin >> num;
      insert(num);
    }
  }
};

int main() {
  BinarySearchTree tree;
  int running = 1;
  char choice[3];

  while (running) {
    cout << "Select an option:" << endl;
    cout << "A: Add numbers manually" << endl;
    cout << "AF: Add numbers from file" << endl;
    cout << "P: Print tree" << endl;
    cout << "D: Delete number" << endl;
    cout << "S: Search for number" << endl;
    cout << "Q: Quit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (strcmp(choice, "A") == 0) {
      tree.addNumbersManually();
    } else if (strcmp(choice, "AF") == 0) {
      tree.addFromFile();
    } else if (strcmp(choice, "P") == 0) {
      tree.printTree();
    } else if (strcmp(choice, "D") == 0) {
      tree.deleteNumber();
    } else if (strcmp(choice, "S") == 0) {
      tree.searchNumber();
    } else if (strcmp(choice, "Q") == 0) {
      running = 0;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
