#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the path from root to a given node
bool findpath(TreeNode* root, int target, int path[], int& pathLen ){
    if(root == nullptr){
        return false;
    }
    path[pathLen++] = root->data;
    if(root->data ==target){
        return true;
    }
    if(findpath(root->left, target, path, pathLen)||findpath(root->right, target, path, pathLen)){
        return true;
    }
    pathLen--;
    return false;
}

// Function to print the path between two nodes
void pathtwonodes(TreeNode* root, int node1, int node2){
    const int MAX_SIZE = 1000;
    int path1[MAX_SIZE], path2[MAX_SIZE];
    int pathLen1 = 0, pathLen2 = 0;

    // Find paths from root to both nodes
    if (!findpath(root, node1, path1, pathLen1) || !findpath(root, node2, path2, pathLen2)) {
        cout << "Path between nodes doesn't exist!" << endl;
        return;
    }

    // Find the last common node in both paths
    int i = 0;
    while (i < pathLen1 && i < pathLen2 && path1[i] == path2[i])
        i++;

    // Print the path from node1 to the last common node
    for (int j = pathLen1 - 1; j >= i; j--)
        cout << path1[j] << " ";
    
    // Print the path from the last common node to node2
    for (int j = i-1; j < pathLen2; j++)
        cout << path2[j] << " ";
    
    cout << endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Find and print path between nodes 4 and 5
    cout << "Path between nodes 4 and 5: ";
    pathtwonodes(root, 4, 5);

    // Find and print path between nodes 2 and 7
    cout << "Path between nodes 2 and 7: ";
    pathtwonodes(root, 2, 7);

    // Find and print path between nodes 4 and 7
    cout << "Path between nodes 4 and 7: ";
    pathtwonodes(root, 4, 7);

    return 0;
}