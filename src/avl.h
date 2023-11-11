#ifndef AVL_H
#define AVL_H

#include <stdint.h>
#include <string>

struct AVLNode {
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class AVLTree {
public:
    AVLNode* insert(AVLNode* root, int key);
    AVLNode* remove(AVLNode* root, int key);
    AVLNode* search(AVLNode* root, int key);

private:
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insertNode(AVLNode* root, int key);
    AVLNode* removeNode(AVLNode* root, int key);
    AVLNode* minValueNode(AVLNode* node);
};






#endif // AVL_H