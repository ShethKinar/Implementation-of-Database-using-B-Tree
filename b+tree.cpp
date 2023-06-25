#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <fstream>
#include <sstream>
#include "b+tree.h"
using namespace std;
int maxChildInt = 4, maxNodeLeaf = 3;

void insertionMethod(BPTree **bPTree, int rollnum)
{
    // DECLARING VARIABLES TO BE INSERTED INTO THE NODE
    string name;
    float spi;

    // TAKING USER INPUT FOR ROLL NUMBER, NAME AND SPI


    cout << "Please Provide Student Name:";
    cin >> name;
    cout << endl;

    cout << "Please Provide Student SPI:";
    cin >> spi;
    cout << endl;

    // USING FILE MANAGEMENT TO PRINT IN THE FILE
    string fileName = "DBFiles/";
    fileName += to_string(rollnum) + ".txt";
    FILE *filePtr = fopen(fileName.c_str(), "w");
    string userTuple = name + " " + to_string(spi) + "\n";
    fprintf(filePtr, userTuple.c_str());
    fclose(filePtr);

    (*bPTree)->insert(rollnum, filePtr);
    fclose(filePtr);
    cout << "Insertion of roll No: " << rollnum << " Successful" << endl;
}

bool search_Method(BPTree *bPTree, int x)
{
    if(bPTree->search(x))
    {
        cout<<"\tThe Entry already exists in the database...Please try another roll number or either the number is root"<<endl;
        cout<<"\tIf it is a root you will be redirected"<<endl;
        return true;
    }
    return false;
}

bool searchMethod(BPTree *bPTree)
{
    int rollNo;
    cout << "What's the RollNo to Search? ";
    cin >> rollNo;
    if(bPTree->search(rollNo))
    {
        cout<<"\tWe have found the key...."<<endl;
        return true;
    }
    return false;
}

void printMethod(BPTree *bPTree)
{
    cout << "\nHere is your File Structure" << endl;
    bPTree->display(bPTree->getRoot());
}

void deleteMethod(BPTree *bPTree)
{
    cout << "Showing you the Tree, Choose a key from here: " << endl;
    bPTree->display(bPTree->getRoot());
    int tmp;
    cout << "Enter a key to delete: " << endl;
    cin >> tmp;
    bPTree->removeKey(tmp);
    // Displaying
    bPTree->display(bPTree->getRoot());
}

int main()
{
    // ENTRY CODE FOR THE DATABASE...
    cout << "---------------------------------------------WELCOME TO THE IMPLEMENTATION OF B+ TREE PROGRAM---------------------------------------------" << endl;
    cout << endl;

    cout << "\t\tROLL NO: 20BCE090" << endl;
    cout << "\t\tROLL NO: 20BCE100" << endl;
    cout << "\t\tROLL NO: 20BCE129" << endl;
    cout << endl;

    cout << "\t\t\tSUBJECT: DATABASE MANAGEMENT SYSTEM" << endl;
    cout << endl;

    BPTree *bPTree = new BPTree(maxChildInt, maxNodeLeaf);
    // DECLARATION OF VARIABLES
    /**
    int roll_no;
    string name;
    float spi;
    **/
    int choice_of_number;
    int search_by_roll_no;
    int roll_no;

    do
    {
        cout << "\t1.\tEnter 1 to insert your data" << endl;
        cout << "\t2.\tEnter 2 to Search a specific data" << endl;
        cout << "\t3.\tEnter 3 to Display your data" << endl;
        cout << "\t4.\tEnter 4 to Delete a specific entry" << endl;
        cout << "\t5.\tEnter 5 to Exit" << endl;

        cout << endl;
        cout << "\tYour CHOICE: ";
        cin >> choice_of_number;
        cout<<endl;
        switch (choice_of_number)
        {
        case 1:
            do
            {
                cout<<"\tEnter Your Roll Number: ";
                cin>>roll_no;
                cout<<endl;
            }while(search_Method(bPTree, roll_no));
            insertionMethod(&bPTree, roll_no);
            break;
        case 2:
            searchMethod(bPTree);
            break;
        case 3:
            printMethod(bPTree);
            break;
        case 4:
            deleteMethod(bPTree);
            break;
        case 5:
            exit(0);
        default:
            printf("\tCHECK YOUR CHOICE ONCE AGAIN, %d IS NOT THE CORRECT CHOICE \n\n", choice_of_number);
            break;
        }
    } while (true);
    return 0;
}