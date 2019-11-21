#include <iostream>
#include<fstream>
#include<string>
#include<queue>
#include"Data.h"
#include<stack>
using namespace std;

int main() {
    //create containers for stack and queue
    stack<Data> stackData;
    queue<Data> queueData;
    priority_queue<Data> priorityQueue;

    ifstream inFile;
    ofstream outFileStack;
    ofstream outFileQueue;
    ofstream outFileSortedLinkedList;

    inFile.open("../WNBAStats.csv");
    outFileStack.open("Stack.txt");
    outFileQueue.open("Queue.txt");
    outFileSortedLinkedList.open("SortedLinkedList.txt");

    if (!inFile.is_open()) {//enters loop if csv file isn't accessible
        cout << "File is not open.";
        return 1;//error
    }

    string AST;//assists
    string STL;//steals
    string PTS;//points
    string MIN;//minutes played

    //getting the chosen 4 data members
    getline(inFile, AST, ',');
    getline(inFile, STL, ',');
    getline(inFile, PTS, ',');
    getline(inFile, MIN);

    //converting the data members to doubles

    cout << "Reading ../WNBAStats.csv…" << endl;
    //reads csv file while file is found
    while (!inFile.eof()) {
        //getting the chosen 4 data members
        getline(inFile, AST, ',');
        getline(inFile, STL, ',');
        getline(inFile, PTS, ',');
        getline(inFile, MIN);

        //converting the data members to doubles
        double ASTnum = stod(AST);
        double STLnum = stod(STL);
        double PTSnum = stod(PTS);
        double MINnum = stod(MIN);

        Data WNBAStats = Data(ASTnum, STLnum, PTSnum, MINnum);
        stackData.push(WNBAStats);
        queueData.push(WNBAStats);
        priorityQueue.push(WNBAStats);

    }

     //printing into all output files
    while(!priorityQueue.empty()){
        outFileSortedLinkedList<<priorityQueue.top();
        priorityQueue.pop();
    }
    while(!stackData.empty()){
        outFileStack<<stackData.top();
        stackData.pop();
    }
    while(!queueData.empty()){
        outFileQueue<<queueData.front();
        queueData.pop();
    }

    //closing files
    inFile.close();
    outFileStack.close();
    outFileQueue.close();
    outFileSortedLinkedList.close();
    return 0;
}