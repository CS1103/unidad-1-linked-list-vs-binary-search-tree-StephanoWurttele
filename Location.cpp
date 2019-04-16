//
// Created by ruben on 4/5/19.
//

#include "LinkedList.h"
UTEC::Node2::Node2(Location _data):data(_data),next(nullptr){};


UTEC::LinkedList::LinkedList():head(nullptr),tail(nullptr){};

UTEC::LinkedList::~LinkedList(){
    delete head;
    delete tail;
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node2* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    return head == nullptr;
}

UTEC::Node2 *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node2 *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(const Location& data) {
    Node2* temp = new Node2(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(const Location& data) {
    Node2* temp = new Node2(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

UTEC::Node2* UTEC::LinkedList::search(std::string position){
    int pos;
    std::istringstream(position)>>pos;
    std::istringstream(position)>>pos;
    Node2* temp=head;
    while(pos!=temp->data.getpos()){
        temp=temp->next;
    }
    return (temp);
}

void UTEC::LinkedList::insert(int position, const Location& data) {
    Node2* temp;
    temp=head;
    if (is_empty()){
        add_head(data);
        return;
    }
    if(size()>=position){
        for(int i=0;i<position;i++){
            temp=temp->next;
        }
        Node2* agregado=new Node2(data);
        agregado->next=temp->next;
        temp->next=agregado;
    }
}

void UTEC::load_locations(LinkedList* linked_list, std::string file_name){
    int tempid=0;
    std::string tempcode="";
    std::string tempsc="";
    double templat=0;
    double templong=0;
    std::string templine="";
    std::string tempconst="";
    std::string temps="";
    std::ifstream file(file_name);
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
        linked_list->add_head(tempdata);
        
    }
};
