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
        
        bool isTaskDone(){
            return done;
        }

        string getTask(){
            return task;
        }

        void setTask(string pTask){
            task = pTask;
        }

        void setDone(bool pDone){
            done = pDone;
        }

};

void clsScr();
void readTxt(ifstream &myTasks);
void printToDo(vector<toDoElement> &tasks);



void writeTask(vector<toDoElement> &tasks){
    ofstream myTasks;
    myTasks.open(fileLocation, std::ios::app);
    string task;
    getline(cin, task);
    toDoElement toDo;
    toDo.setTask(task);
    tasks.push_back(toDo);
    myTasks << tasks.back().getTask() << endl;
    myTasks.close();
    
}

void pushTasksInList(ifstream &myTasks, vector<toDoElement> &tasks){
    string fileOutput;
    myTasks.open(fileLocation);
    while(getline(myTasks, fileOutput)){
        toDoElement temp;
        temp.setTask(fileOutput);
        tasks.push_back(temp);
    }
    myTasks.close();
}

void setTaskDone(ifstream &myTasks, vector<toDoElement> &tasks){
    string fileOutput;
    int numberOfTask;
    int cursor;
    bool checkDone = false;
    while(checkDone == false){
        cin >> numberOfTask;
        if(cin.fail()){
            cin.clear(); // -> cleared nicht alles T-T
            cin.ignore(); // deswegen der schmog hier
            clsScr();
            
            cout << "Wähle welche Aufgabe fertig ist: \n\n";
            
            printToDo(tasks);
            continue;
        }
        checkDone = true;
    }
    myTasks.open(fileLocation);
    while(getline(myTasks, fileOutput)){        
        if(tasks.at(numberOfTask-1).getTask() == fileOutput){
            tasks.erase(tasks.begin() + numberOfTask -1);
            break;
        }
    }
    myTasks.close();
}

void readTxt(ifstream &myTasks){
    string fileOutput;
    toDoElement temp;
    int counter = 1;
    myTasks.open(fileLocation);
    while(getline(myTasks, fileOutput)){
        cout << counter << ". " << fileOutput << endl;
        counter++;
    }
    myTasks.close();
}

void printToDo(vector<toDoElement> &tasks){
    int counter = 1;
    for(toDoElement i : tasks){
        cout << counter << ". " << i.getTask() << endl;
        counter++;
    }
}

void saveAndExit(vector<toDoElement> &tasks){
    ofstream inFile;
    inFile.open(fileLocation);
    inFile << "";
    inFile.close();

    inFile.open(fileLocation, std::ios::app);
    for(toDoElement i : tasks){
        inFile << i.getTask() << endl;
    }
    
}

void clsScr(){
    system("cls");
}


int main()
{
    string cmd;

    vector<toDoElement> tasks;

    ifstream myTasks;


    pushTasksInList(myTasks, tasks); 
    
    while(true){
        cout << "Was wollen Sie tun?\n \nwrite: Aufgabe hinzufügen \nread: Zeige alle Aufgaben \ndone: Setze n. Aufgabe auf gemacht \nend: Speichern & Beenden \n";
        getline(cin, cmd);

        if(cmd == "end"){
            saveAndExit(tasks);
            return 0;

        }else if(cmd == "write"){
            clsScr();
            cout << "Schreibe deine Aufgabe\n";
            writeTask(tasks);
            system("PAUSE");

        }else if(cmd == "read"){
            clsScr();
            cout << "Ihre Aufgaben: \n\n";
            printToDo(tasks);
            cout << endl;
            system("pause");
            
        }else if(cmd == "done"){
            clsScr();
            cout << "Wähle welche Aufgabe fertig ist: \n\n";
            printToDo(tasks);
            setTaskDone(myTasks, tasks);
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

