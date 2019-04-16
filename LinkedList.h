//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

namespace UTEC {

    struct Node2 {
        Location data;
        Node2* next;
        Node2(Location _data);
    };

    class LinkedList {
        Node2* head;
        Node2* tail;
    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool is_empty();
        Node2* get_head();
        Node2* get_tail();
        void add_head(const Location& data);
        void add_tail(const Location& data);
        void print();
        void insert(int position, const Location& data);
        Node2* search(std::string position_id);
    };
    void load_locations(LinkedList* linked_list, std::string file_name);
}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
