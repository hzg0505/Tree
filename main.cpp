#include <iostream>
#include "src/btree.h"
#include <vector>
// #include "btree.h"

int main(int, char**){
    std::cout << "----- main ------" << std::endl;
    std::vector<int> vt = {5, 3, 8, -1, -1, 6, 4} ;
    Btree tree = Btree(vt) ;

    tree.insert(7);
    tree.insert(10);
    // std::cout << "Levelorder traversal: ";
    // tree.printLevelorder();
    // std::cout << std::endl;
    // tree.mirrorTree(); 

    // std::cout << "Levelorder traversal: ";
    // tree.printLevelorder();
    // std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    tree.printPreorder();
    std::cout << std::endl;


    // std::cout << "Inorder traversal: ";
    // tree.printInorder();
    // std::cout << std::endl;

    // std::cout << "Postorder traversal: ";
    // tree.printPostorder();
    // std::cout << std::endl;

    // std::cout << "Levelorder traversal: ";
    // tree.printLevelorder();
    // std::cout << std::endl;
    return 0;
}