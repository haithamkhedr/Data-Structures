#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isRightBST(const vector<Node>&, int ,int);
bool isLeftBST(const vector<Node>& tree, int rootIdx,int maxValue){
    bool ret = true;
    Node root = tree[rootIdx];
    if(root.key >= maxValue){
        return false;
    }
    else if(root.left != -1 && tree[root.left].key >= maxValue){
        return false;
    }
    else if(root.right != -1 && tree[root.right].key >= maxValue){
        return false;
    }
    // the 3 nodes are smaller than ancestor, need to check if they are a BST
    if(root.left != -1)
        ret &= isLeftBST(tree, root.left, root.key);
    if(root.right != -1)
        ret &= isRightBST(tree, root.right, root.key);
    return ret;
}


bool isRightBST(const vector<Node>& tree, int rootIdx, int minValue){
    bool ret = true;
    Node root = tree[rootIdx];
    if(root.key < minValue){
        return false;
    }
    else if(root.left != -1 && tree[root.left].key < minValue){
        return false;
    }
    else if(root.right != -1 && tree[root.right].key < minValue){
        return false;
    }
    // the 3 nodes are smaller than ancestor, need to check if they are a BST
    if(root.left != -1)
        ret &= isLeftBST(tree, root.left, root.key);
    if(root.right != -1)
        ret &= isRightBST(tree, root.right, root.key);
    return ret;
}
bool IsBinarySearchTree(const vector<Node>& tree) {
    // Implement correct algorithm here
    if(tree.size() ==0)
        return true;
    bool ret = true;
    Node root = tree[0];
    if(root.left != -1){
        ret &= isLeftBST(tree, root.left, root.key);
    }
    if(root.right != -1){
        ret &= isRightBST(tree, root.right, root.key);
    }
    return ret;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
