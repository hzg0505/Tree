#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include <vector>

// struct node{
//     node* left;
//     node* right;
//     int val;
//     node(int value): val(value), left(nullptr), right(nullptr) {}
// };

// struct int_node{
//     node* node;
//     int data;
// };

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Btree{
private:
    // int_node ;
    TreeNode* root;

    // track
    void preorderTraversal(TreeNode* node);
    void inorderTraversal(TreeNode* node);
    void postorderTraversal(TreeNode* node);
    // 非递归
    void preorderTraversal2(TreeNode* node);
    void inorderTraversal2(TreeNode* node);
    void postorderTraversal2(TreeNode* node);
    // 
    void levelOrder(TreeNode* node);

    // std::vector<int> preorderTraversal(TreeNode* node);
    // std::vector<int> inorderTraversal(TreeNode* node);
    // std::vector<int> postorderTraversal(TreeNode* node);
    void mirrorTree(TreeNode* node)  ;



public:
    Btree();
    Btree(std::vector<int>& vt);

    void printPreorder();
    void printInorder();
    void printPostorder();
    void printLevelorder();

    // void mirrorTree(TreeNode* node)  ;
    void mirrorTree();
    void insert(int value);
    bool select(int key);

};



// template <typename T>
// struct TreeNode {
//     T data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
// };

// template <typename T>
// class BinaryTree {
// public:
//     BinaryTree() : root(nullptr){}

//     void insert(T value) {
//         root = insertRecursive(root, value);
//     }

//     void printPreorder() {
//         PreorderTraversal(root);
//     }

//     void printInorder() {
//         inorderTraversal(root);
//     }

//     void printPostorder() {
//         PostorderTraversal(root);
//     }


// private:
//     TreeNode<T>* root;

//     TreeNode<T>* insertRecursive(TreeNode<T>* node, T value);

//     void preorderTraversal(TreeNode<T>* node);

//     void inorderTraversal(TreeNode<T>* node);

//     void postorderTraversal(TreeNode<T>* node);
// };


// template <typename T>
// TreeNode<T>* BinaryTree<T>::insertRecursive(TreeNode<T>* node, T value) {
//     if (node == nullptr) {
//         return new TreeNode<T>(value);
//     }

//     if (value < node->data) {
//         node->left = insertRecursive(node->left, value);
//     } else if (value >= node->data) {
//         node->right = insertRecursive(node->right, value);
//     }

//     return node;
// }

// template <typename T>
// void BinaryTree<T>::inorderTraversal(TreeNode<T>* node){
//     if(node == nullptr) return;
    
//     inorderTraversal(node->left);
//     std::cout << node->data << " ";
//     inorderTraversal(node->right);
// }

// template <typename T>
// void BinaryTree<T>::preorderTraversal(TreeNode<T>* node){
//     if(node == nullptr) return;
    
//     std::cout << node->data << " ";
//     preorderTraversal(node->left);
//     preorderTraversal(node->right);
// }

// template <typename T>
// void BinaryTree<T>::postorderTraversal(TreeNode<T>* node){
//     if(node == nullptr) return;
    
//     postorderTraversal(node->left);
//     postorderTraversal(node->right);
//     std::cout << node->data << " ";
// }


#endif