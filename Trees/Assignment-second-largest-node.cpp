/*Second Largest Element In Tree

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form.
 The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node.
  The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};



TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
#include<stack>
#include<queue>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root->children.size()==0){
        return NULL;
    }
    queue<TreeNode<int>*> queue;
    TreeNode<int> *f1 = root, *s1 = NULL;
    int data =0;
    queue.push(root);
    while(queue.empty()!=1){
        TreeNode<int> *frontnode = queue.front();
        queue.pop();
        for(int i =0;i<frontnode->children.size();i++){
            queue.push(frontnode->children[i]);
        }
        if(frontnode->data > data){
            if(frontnode->data > f1->data){
                s1 = f1;
                data = f1->data;
                f1 = frontnode;
            }
            else if(frontnode->data < f1->data){
                s1 = frontnode;
                data = s1->data;
            }
        }
    }
    return s1;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}