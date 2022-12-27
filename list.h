//list.h
//Creator: Aditya Prasad

#ifndef list.h
#define list.h

struct  ListItem
{
    int year;
    double flow;
    ListItem(int year,double flow);
    ListItem();
};

struct  Node
{
    ListItem item;
    Node* next;
    Node(int year,double flow);
};

class FlowList{
    public:
    Node* head; // head pointer to the list
    FlowList();
    Node* add(ListItem item);
    Node* _delete(int year);
};

#endif