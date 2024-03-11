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

void writeTask(vector<toDoElement> &tasks){
    ofstream myTasks;
    myTasks.open(fileLocation, std::ios::app);
    string task;
    getline(cin, task);
    toDoElement toDo;
    toDo.setTask(task);
    tasks.push_back(toDo);
    myTasks << toDo.getTask() << endl;
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
    cin >> numberOfTask;
    while(getline(myTasks, fileOutput)){
        if(tasks.at(numberOfTask).getTask() == fileOutput){ // <--- Anders machen
            cout << "success";
            system("pause");
        }
    }
    myTasks.close();
}

void readTxt(ifstream &myTasks){
    string fileOutput;
    toDoElement temp;
    myTasks.open(fileLocation);
    while(getline(myTasks, fileOutput)){
        cout << fileOutput << endl;
    }
    myTasks.close();
}

void printToDo(vector<toDoElement> &tasks){
    for(toDoElement i : tasks){
        cout << i.getTask() << endl;
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
        cout << "Was wollen Sie tun?\n \nwrite: Aufgabe hinzufügen \nread: Zeige alle Aufgaben \ndone: Setze n. Aufgabe auf gemacht \nend: Beenden \n";
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

