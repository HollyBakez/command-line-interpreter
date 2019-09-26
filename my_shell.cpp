#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <cstring> 
#include <vector>
using namespace std;


void* ExecuteRunner(void* arg){
    
    system((char*) arg);
    pthread_exit(0);
}

int main(){
    char delim[] = " ";
    /* thread id */
    pthread_t tid;

    /* create attributes */
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    string user_command; 
    vector<string> com_list;
    com_list.push_back("ls");
    com_list.push_back("ping");
    com_list.push_back("echo");
    com_list.push_back("help");
    com_list.push_back("color");
    com_list.push_back("notepad");
    com_list.push_back("tasklist");
    com_list.push_back("path");
    com_list.push_back("vol");


                             /*
    string com_list[9] = {"ls", "ping", "echo", 
                            "help", "color", "notepad", "tasklist", 
                             "path", "vol"};
                             */
    cout << "---- Welcome to MyShell ---- \n";

    while (1){
        bool com_exist = false;
        cout << "---- To exit, enter 'exit' ---- \n";
        cout << "---- Please enter a command ---- \n";
        getline(cin, user_command);

        if (user_command == "exit" || user_command == "Exit"){
            cout << "Thank you for using me! \n";
            break;
        }
    /* converts user command into char */
        char cstr[user_command.size() + 1];
    /* token should be strings between each whitespace to indicate argument size */
        char* token = strtok(strcpy(cstr, user_command.c_str()), delim);
    
        if (token){
            // check if the command is supported 
            for(int i = 0; i < com_list.size() ; i++){ // change sizeof(com_list)  to 8
                if (token == com_list[i]){
                    com_exist = true;

                    break;
                }

            }
            /* if the command exists, create thread and execute command */
            if(com_exist == true){
            strcpy(cstr, user_command.c_str());
            pthread_create(&tid, &attr, ExecuteRunner, cstr);  
            pthread_join(tid, NULL);
            }
            else{
                cout << "command is not supported \n";
            }
        
        }
     
    }
    return 0 ;
}