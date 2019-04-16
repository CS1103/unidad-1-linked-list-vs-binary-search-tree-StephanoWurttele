//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC{

    struct Node {
        Location data;
        Node* right;
        Node* left;

        Node(Location _data);
    };

    class BinarySearchTree {
        Node* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void Destroytree(Node* base);
        void insert(Location data);
        void clear();
        bool is_empty();
        Node* get_root();
        Node* search(std::string position_id);
        void print(Node* root);
    };

    void load_locations(BinarySearchTree &linked_list, std::string file_name);
    void print_node(Node* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
