/*Pair sum in a BST

Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. 
If any node does not have left or right child, take -1 in its place. 
Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7*/
#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}
#include<stack>
int count(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root==NULL){
        return;
    }
    int totalcount = count(root);
    int c=0;
    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revinorder;
    BinaryTreeNode<int> *curr = root;
    while(curr!=NULL){
        inorder.push(curr);
        curr = curr->left;
    }
    curr = root;
    while(curr!=NULL){
        revinorder.push(curr);
        curr=curr->right;
    }
    while(c < totalcount-1){
        BinaryTreeNode<int> *inordertop = inorder.top();
        BinaryTreeNode<int> *revinordertop = revinorder.top();
        if(inordertop->data + revinordertop->data==s){
            cout<<inordertop->data<<" "<<revinordertop->data<<endl;
            BinaryTreeNode<int> *top = inordertop;
            inorder.pop();
            c++;
            if(top->right!=NULL){
                top = top ->right;
                while(top!=NULL){
                    inorder.push(top);
                    top = top->left;
                }
            }
            top = revinordertop;
            revinorder.pop();
            c++;
            if(top->left!=NULL){
                top = top ->left;
                while(top!=NULL){
                    revinorder.push(top);
                    top = top->right;
        }
    }
}  else if(inordertop->data+revinordertop->data >s){
            BinaryTreeNode<int> *top = revinordertop;
            revinorder.pop();
            c++;
            if(top->left!=NULL){
                top = top->left;
                while(top!=NULL){
                    revinorder.push(top);
                    top = top ->right;
                }
            }
        }
        else {
            BinaryTreeNode<int> *top = inordertop;
            inorder.pop();
            c++;
            if(top->right!=NULL){
                top = top->right;
                while(top!=NULL){
                    inorder.push(top);
                    top = top ->left;
                }
            }
        }
    }
}
int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}