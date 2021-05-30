#include"tree.h"
#include<iostream>

int get_input()
{
    int input;
    std::cin >> input;
    return input;
}

const char* print_data(int data)
{
    return std::to_string(data).c_str();
}

bool isdata_valid(int data)
{
    return data>-1 ? true:false;
}

int main() {
    Tree<int> *tree = new Tree<int>(&get_input, &isdata_valid, &print_data);
    tree->buildtree_level_order();
    delete tree;
}