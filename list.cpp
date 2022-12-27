
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

#include "list.h"
#include "hydro.h"

FlowList::FlowList()
: headM(0) // headM is a pointer, so it is initialized to 0.
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}


void FlowList::print() const {
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void FlowList::insert(const List_Item& item)
{
    Node *new_node = new Node;
    new_node->item = item;
    
    if (headM == 0 || item.year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }

    else {
        Node *before = headM;     
        Node *after = headM->next;

        while(after != 0 && item.year > after->item.year) {  
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::remove(const List_Item& item)
{
    if (headM == 0) {
        return;
    }
    if (headM->item.year == item.year) {
        Node *temp = headM;
        headM = headM->next;
        delete temp;
        return;
    }
    Node *before = headM;
    Node *after = headM->next;
    while (after != 0 && after->item.year != item.year) {
        before = after;
        after = after->next;
    }
    if (after != 0) {
        before->next = after->next;
        delete after;
    }
}

void FlowList::destroy()
{
    while (headM != 0) {
        Node *temp = headM;
        headM = headM->next;
        delete temp;
    }
}

void FlowList::copy(const FlowList& source)
{
    if (source.headM == 0) {
        headM = 0;
    }
    else {
        headM = new Node;
        headM->item = source.headM->item;
        Node *newp = headM;
        for (Node *p = source.headM->next; p != 0; p = p->next) {
            newp->next = new Node;
            newp = newp->next;
            newp->item = p->item;
        }
        newp->next = 0;
    }
}

