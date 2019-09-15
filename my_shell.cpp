// my_shell.cpp : Simple Command Line Interpreter
// Copyright(c) Holland Ho 9/14/19

#include <iostream>

using namespace std;
/* 
----- pseudo code -----
1. Create infinite loop that calls for a user input or "command"
2. checks the command with a list of supported commands
        - dir 
        - help
        - vol
        - path
        - tasklist
        - notepad
        - echo
        - color
        - ping
3. check command and if needed parse user input
4. execute in child thread via CreateThread() -> executes the command 
5. Parent thread waits for "exit" or "quit" -> terminates shell



*/

int main(){
    //std::cout<< "hello world";
    string user_command; 

    while(1){ 
        cout<<"test \n";
        cout<<"type 'stop' to exit\n";
        getline(cin,user_command);
        if(user_command == "stop"){
            break;
        }
    }

    return 0;
}