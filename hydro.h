//hydro.h

#ifndef hydro.h
#define hydro.h
#include "list.h"


int main();
//define flowlist class

void displayHeader();

FlowList readData();

void menu(FlowList& listA);

void displayData(FlowList& listA); //call averge

void addData(FlowList& listA);

void removeData(FlowList& listA);

void average(FlowList& listA);

int saveData(FlowList& listA);

void pressEnter();

#endif hydro.h
