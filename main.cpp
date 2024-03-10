#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
const string fileLocation = "listOfTasks.txt";

class toDoElement{
    public:
        bool done;
        string task;
        
        toDoElement(string task, bool done = false){
            this->task = task;
            this->done = done;
        }

        bool isTaskDone(){
            return done;
        }

        string getTask(){
            return task;
        }

};

void writeTask(vector<toDoElement> &tasks){
    ofstream myTasks;
    myTasks.open(fileLocation, std::ios::app);
    string task;
    getline(cin, task);
    myTasks << task << endl;
    myTasks.close();
    tasks.push_back(task);
}

void pushTasksInList(ifstream &myTasks, vector<toDoElement> &tasks){
    string fileOutput;
    while(getline(myTasks, fileOutput)){
        tasks.push_back(fileOutput);
    }
    myTasks.close();
}

void setTaskDone(ifstream &myTasks, vector<toDoElement> &tasks){
    string fileOutput;
    int numberOfTask;
    cin >> numberOfTask;
    while(getline(myTasks, fileOutput)){
        if(tasks.at(numberOfTask).getTask() == fileOutput){
            //suche zeile und lösche diese
        }
    }
    myTasks.close();
}

void readTxt(ifstream &myTasks){
    int counter = 0;
    string fileOutput;
    myTasks.open(fileLocation);
    while(getline(myTasks, fileOutput)){
        counter++;
        cout << counter << ". " << fileOutput << endl;
    }
    myTasks.close();
}

void printToDo(vector<toDoElement> &tasks){
    for(toDoElement i : tasks){
        cout << i.getTask();
    }
}

void clsScr(){
    system("cls");
}


int main()
{
    string cmd;

    vector<toDoElement> tasks;

    ifstream myTasks(fileLocation);


    pushTasksInList(myTasks, tasks);

    
    while(true){
        cout << "Was wollen Sie tun?\n \nwrite: Aufgabe hinzufügen \nread: Zeige alle Aufgaben\n done: Setze n. Aufgabe auf gemacht \nend: Beenden \n";
        getline(cin, cmd);

        if(cmd == "end"){
            return 0;

        }else if(cmd == "write"){
            clsScr();
            cout << "Schreibe deine Aufgabe\n";
            writeTask(tasks);
            system("PAUSE");

        }else if(cmd == "read"){
            clsScr();
            cout << "Ihre Aufgaben: \n\n";
            readTxt(myTasks);
            cout << endl;
            system("pause");
            
        }else if(cmd == "done"){
            clsScr();
            cout << "Wähle welche Aufgabe fertig ist: \n\n";
            readTxt(myTasks);
            cout << endl;

        }
        clsScr();
        if(cin.fail()){
            cin.clear();
            cout << "Zahl als uchstabe eingegeben! \n";
            system("pause");
        }
    }

    
    return 0;
}

