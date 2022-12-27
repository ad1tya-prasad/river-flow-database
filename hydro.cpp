#include <stdlib.h>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>

using namespace std;
ifstream inObj;

#include "list.h"
#include "hydro.h"
//define the main function
int main()
{
    FlowList listA;
    displayHeader();
    listA = readData();
    menu(listA);
    return 0;
}
//define function displayHeader
void displayHeader()
{
    cout << "Program: Flow Studies - Fall 2022" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: B01" << endl;
    cout << "Produced by: Aditya" << endl <<endl;
    cout << " <<< Press Enter To Continue >>>" << endl;
}
//define function readData
int readData(FlowList& listA)
{
    //read input from flow.txt
    inObj.open("flow.txt");
    if (!inObj) {
        cout << "Error opening file flow.txt" << endl;
        return 1;
    }
}
//define function menu
void menu(FlowList& listA)
{
    int choice;
    do {
        cout << "1. Display flow list, and the average" << endl;
        cout << "2. Add Data" << endl;
        cout << "3. Save Data into File" << endl;
        cout << "4. Remove Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1, 2, 3, 4, 5): ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayData(listA);
                break;
            case 2:
                addData(listA);
                break;
            case 3:
                saveData(listA);
                break;
            case 4:
                removeData(listA);
                break;
            case 5:
                cout << "Thank you for using the program!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
}

//define function displayData
void displayData(FlowList& listA)
{
    cout << "Displaying the flow list and the average" << endl;
    listA.print();
    average(listA);
}

//define function addData
void addData(FlowList& listA)
{
    cout << "Adding data to the flow list" << endl;
    int year;
    double flow;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the flow: ";
    cin >> flow;
    List_Item item;
    item.year = year;
    item.flow = flow;
    listA.insert(item);
    cout << "Data added successfully!" << endl;
}

//make a function to save data into a file
int saveData(FlowList& listA)
{
    cout << "Saving data into a file" << endl;
    ofstream outObj;
    outObj.open("flow.txt");
    if (!outObj) {
        cout << "Error opening file flow.txt" << endl;
        return 1;
    }
    outObj << listA; 

    outObj.close();
    cout << "Data saved successfully!" << endl;
}


//define function removeData
void removeData(FlowList& listA)
{
    cout << "Removing data from the flow list" << endl;
    int year;
    cout << "Enter the year to be removed: ";
    cin >> year;
    listA.remove(year);
    cout << "Data removed successfully!" << endl;
}

//define function average
void average(FlowList& listA)
{
    cout << "Calculating the average" << endl;
    double sum = 0;
    double average;
    int count = 0;
    List_Item item;
    for (int i = 0; i < listA.size(); i++) { 
        item = listA.get(i);
        sum += item.flow;
        count++;
    }
    average = sum / count;
    cout << "The average is: " << average << endl;
}

//define function pressEnter
void pressEnter()
{
    cout << " <<< Press Enter To Continue >>>" << endl;
    cin.ignore();
    cin.get();
}

