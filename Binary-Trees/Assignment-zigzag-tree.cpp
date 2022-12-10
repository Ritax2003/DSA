/*ZigZag tree

Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space.
 If any node does not have a left or right child, take -1 in its place. 
 Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9*/
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};




BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
   if(root == NULL){
       return;
   }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(s1.size()!=0 || s2.size()!=0){
        while(s1.size()!=0){
        cout<<s1.top()->data<<" ";
        if(s1.top()->left!=NULL){ s2.push(s1.top()->left);}
        if(s1.top()->right!=NULL){s2.push(s1.top()->right);}
            s1.pop();
        }
        cout<<endl;
        while(s2.size()!=0){
            cout<<s2.top()->data<<" ";
            if(s2.top()->right!=NULL){ s1.push(s2.top()->right);}
            if(s2.top()->left!=NULL){ s1.push(s2.top()->left);}
            s2.pop();
        }
        cout<<endl;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}