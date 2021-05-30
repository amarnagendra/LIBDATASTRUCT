#ifndef __TREE_H
#define __TREE_H
#include <queue>
#include<iostream>
#include<queue>

template <typename dataType>
class Node {
    private:     
    public:
        Node *left;
        Node *right;
        dataType data;
        Node (dataType d) {
            left = nullptr;
            right = nullptr;
            data = d;
        }
};

template <typename dataType>
class Tree {
    private:
        Node<dataType> *head;
    public:
        typedef dataType (*userinput)();
        typedef bool (*isvalid) (dataType data);
        typedef const char* (*print_data)(dataType data);

        userinput userinputfunc;
        isvalid isvalidfunc;
        print_data print_datafunc;
        
        Tree () {
            head = nullptr;
        }
        Tree (Node<dataType> * node){
            head = node;
        }
        Tree (dataType (*func1)(), bool (*func2) (dataType data), const char* (*func3)(dataType))
        {
            userinputfunc = func1;
            isvalidfunc = func2;
            print_datafunc = func3;
        }
        void buildtree_level_order(void);
};

template <typename dataType>
void Tree<dataType>::buildtree_level_order(void)
{
    std::cout << "Enter value of head node" << std::endl;
    dataType input;
    input = userinputfunc();
    head = new Node<dataType>(input);

    std::queue<Node<dataType>*> queue;
    queue.push(head);

    while (!queue.empty()) {
        Node<dataType> *T = queue.front();
        queue.pop();

        std::cout << "Enter the Left node of " << *print_datafunc(T->data) << std::endl;
        input = userinputfunc();
        if (isvalidfunc(input)) {
            T->left = new Node<dataType>(input);
            queue.push(T->left);
        }
        std::cout << "Enter the Right node of " << *print_datafunc(T->data) << std::endl;
        input = userinputfunc();
        if (isvalidfunc(input)) {
            T->right = new Node<dataType>(input);
            queue.push(T->right);
        }
    }

}
#endif 