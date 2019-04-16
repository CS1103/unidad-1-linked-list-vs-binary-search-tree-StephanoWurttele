//
// Created by ruben on 4/5/19.
//

#include "BinarySearchTree.h"


UTEC::Node::Node(Location _data):data(_data),right(nullptr),left(nullptr){};

UTEC::BinarySearchTree::BinarySearchTree():root(nullptr){}
UTEC::BinarySearchTree::~BinarySearchTree(){
    Destroytree(root);
    std::cout<<"0bject deleted";
};

void UTEC::BinarySearchTree::Destroytree(UTEC::Node* base) {
    if (root==nullptr){
        return;
    }
    UTEC::BinarySearchTree::Destroytree(base->left);
    UTEC::BinarySearchTree::Destroytree(base->right);
    delete base;
    return;
}



void UTEC::BinarySearchTree::insert(Location data) {
    Node *temp=root;
    if (root == nullptr) {
        root = new Node(data);
    } else {
        while(true) {
            if (data.getpos() >= temp->data.getpos()) {
                if (temp->right == nullptr) {
                    Node *tempr = new Node(data);
                    temp->right = tempr;
                    break;
                } else {
                    temp = temp->right;
                }
            }
            else {
                if (temp->left == nullptr) {
                    Node *tempr = new Node(data);
                    temp->left = tempr;;
                    break;
                } else {
                    temp = temp->left;
                }
            }
    }
    }
}

void UTEC::BinarySearchTree::clear(){
    
}

bool UTEC::BinarySearchTree::is_empty(){
    return (root==nullptr);
}

UTEC::Node* UTEC::BinarySearchTree::get_root(){
    return (root);
}

UTEC::Node* UTEC::BinarySearchTree::search(std::string position_id){
    Node* temp=root;
    int position;
    std::istringstream(position_id)>>position;
    while(true){
        if (position==temp->data.getpos()){
            return temp;
        }
        if(position>temp->data.getpos()){
            temp=temp->right;
        }
        else if (position<temp->data.getpos())
        {
            temp=temp->left;
        }
        
    }

}
void UTEC::BinarySearchTree::print(Node* root){
    if (root==nullptr){
        return;
    }
    UTEC::BinarySearchTree::print(root->left);
    std::cout<<root->data.getpos()<<"\n";
    UTEC::BinarySearchTree::print(root->right);
};

void UTEC::load_locations(BinarySearchTree &linked_list, std::string file_name){
    int tempid=0;
    std::string tempcode="";
    std::string tempsc="";
    double templat=0;
    double templong=0;
    int as=0;
    std::string templine="";
    std::string tempconst="";
    std::string temps="";
    std::ifstream file(file_name);
    //Location temp1;
    getline(file,temps,',');
    std::istringstream(temps)>>tempid;
    temps="";
    getline(file,tempcode,',');
    getline(file,tempsc,',');
    getline(file,temps,',');
    std::istringstream(temps)>>templat;
    getline(file,temps,',');
    std::istringstream(temps)>>templong;
    getline(file,templine,',');
    getline(file,tempconst,'\n');
    while(true){
        if (file.eof()){
            break;
        }
        getline(file,temps,',');
        std::istringstream(temps)>>tempid;
        temps="";
        getline(file,tempcode,',');
        getline(file,tempsc,',');
        getline(file,temps,',');
        std::istringstream(temps)>>templat;
        getline(file,temps,',');
        std::istringstream(temps)>>templong;
        getline(file,templine,',');
        getline(file,tempconst,'\n');
        Location tempdata(tempid,tempcode,tempsc,templat,templong,templine,tempconst);
        linked_list.insert(tempdata);
        }

}

