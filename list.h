//list.h

#ifndef list.h
#define list.h

typedef int ListItem;

struct List_Item {
    int year;
    double flow;
};

struct Node {
    List_Item item;
    Node *next;
};

class FlowList {
    public:
        FlowList();
        FlowList(const FlowList& source);
        FlowList& operator =(const FlowList& rhs);
        ~FlowList();

        void insert(const List_Item& itemA);
        void remove(const List_Item& itemA);
        void print() const;

    private:
        Node *headM;
        void destroy();
        void copy(const FlowList& source);
};




#endif