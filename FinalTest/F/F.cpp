#include <iostream>

struct Node {
    int data; // данные, которые хранятся в узле
    Node* left, *right, *right_sibling; // указатели на потомков и правого соседа
    int level; // уровень дерева, на котором находится узел (у корня - 0, у его потомков - 1, и т.д.)
};

void build_siblings(Node* root);
{
    left->right_sibling = right;
    left->right->right_sibling = 
}

int main()
{
    std::cout << "Hello World!\n";
}


