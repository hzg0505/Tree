#include<iostream>
#include "btree.h"
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

Btree::Btree()
{
    root = nullptr;
}

Btree::Btree(std::vector<int>& vt)
{
    int n = vt.size();
    if(n == 0){
        root = nullptr;
        return;
    }

    // int high = log2(n)+1;
    std::queue<TreeNode*> q;
    root = new TreeNode(vt[0]);
    q.push(root);

    
    for(int i=1; i<n; ++i)
    {
        TreeNode* p = q.front(); 
        q.pop();

        if(vt[i] == -1){  //  zuo
            q.push(nullptr);
        }else{
            p ->left = new TreeNode(vt[i]);
            q.push(p->left);
        }
        
        ++i;

        if(i<n){
            if(vt[i] == -1){  //  zuo
                q.push(nullptr);
            }else{
                p ->right = new TreeNode(vt[i]);
                q.push(p->right);
            }
        }

    }

}


void Btree::preorderTraversal(TreeNode* node)  // root left right
{
    if(node == nullptr) return;
    std::cout << node->val << ",";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void Btree::inorderTraversal(TreeNode* node)  // left root right
{
    if(node == nullptr) return;
    inorderTraversal(node->left);
    std::cout << node->val << ",";
    inorderTraversal(node->right);
}

void Btree::postorderTraversal(TreeNode* node)
{
    if(node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << node->val << ",";
}

void Btree::preorderTraversal2(TreeNode* node)
{
    if(node == nullptr) return;
    // std::cout << node->val << " ";
    std::stack<TreeNode* > st;
    // st.push(node);

    TreeNode* current = node;
    while(!st.empty() || current != nullptr)
    {
        while(current)  // left
        {
            st.push(current);
            std::cout << current->val << ",";
            current = current->left;
        }

        current = st.top();
        // ->right;
        st.pop();
        current = current->right;
    }
}

void Btree::inorderTraversal2(TreeNode* node)
{
    if(node == nullptr) return;
    std::stack<TreeNode*> st;
    TreeNode* current = node;
    while(!st.empty() || current!=nullptr)
    {
        while(current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        std::cout<< current->val << ",";
        current = current->right;
    }
}

void Btree::postorderTraversal2(TreeNode* node)
{
    if(node == nullptr) return;
    std::stack<TreeNode*> st;
    TreeNode* current = node;
    TreeNode* prev = nullptr;
    while(current!=nullptr || !st.empty())
    {
        while(current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        if(current->right==nullptr || current->right==prev)
        {
            std::cout<< current->val << ",";
            prev = current;
            current = nullptr;
        }else{
            st.push(current);
            current = current->right;
        }
    }
}

void Btree::levelOrder(TreeNode* node)
{
    if(node == nullptr) return;
    std::queue<TreeNode*> qu;
    qu.push(node);
    TreeNode* cur = nullptr;
    while(!qu.empty())
    {
        cur = qu.front();
        qu.pop();
        std::cout << cur->val << ",";
        if(cur->left) qu.push(cur->left);
        if(cur->right) qu.push(cur->right);
    }
}


void Btree::printPreorder() {
    std::cout << "[";
    preorderTraversal(root);
    std::cout << "]\n";
    // std::cout << "[";
    // preorderTraversal2(root);
    // std::cout << "]\n";
}

void Btree::printInorder() {
    std::cout << "[";
    inorderTraversal(root);
    std::cout << "]\n";
    // std::cout << "[";
    // inorderTraversal2(root);
    // std::cout << "]\n";
}

void Btree::printPostorder() {
    std::cout << "[";
    postorderTraversal(root);
    std::cout << "]\n";
    // std::cout << "[";
    // postorderTraversal2(root);
    // std::cout << "]\n";
}

void Btree::printLevelorder(){
    std::cout << "[";
    levelOrder(root);
    std::cout << "]\n";
}


void Btree::mirrorTree(TreeNode* node) 
{
    if(node == nullptr) return;

    if(node->left && node->right)
    {
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirrorTree(node->left);
        mirrorTree(node->right);
    }else if(node->left){
        node->right = node->left;
        node->left = nullptr;
        mirrorTree(node->right);
    }else if(node->right){
        node->left = node->right;
        node->right = nullptr;
        mirrorTree(node->right);
    }else{
        return;
    }
    
}

void Btree::mirrorTree()
{
    Btree::mirrorTree(root); 
}


void Btree::insert(int value)
{
    TreeNode* prev = nullptr;
    TreeNode* cur = root;
    while(cur)
    {
        if(value >= cur->val)
        {
            prev = cur;
            cur = cur->right;
        }else{
            prev = cur;
            cur = cur->left;
        }
    }
    if(prev == nullptr)
        prev = new TreeNode(value);
    else{
        if(value>= prev->val)
        {
            prev->right = new TreeNode(value);
        }else{
            prev->left = new TreeNode(value);
        }
    }
    // cur = new TreeNode(value);
    return ;
}


bool Btree::select(int key)
{
    if(root == nullptr) return false;
}