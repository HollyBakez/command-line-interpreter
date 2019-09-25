// my_shell.cpp : Simple Command Line Interpreter
// Copyright(c) Holland Ho 9/14/19

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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


/* the thread will handle the execution of the command*/
DWORD WINAPI ExecuteCommand(LPVOID command){
  /* insert code here */
}

/* compares "command" to the list of supported commands */
string GetCommand(string command){
  if (command == "dir"){
    return system("dir");
  }

  return 0;
}

int main(){
    DWORD thread_id;
    HANDLE thread_handle;
/* delim to check for command arguments amount */
    char delim[] = " ";
    cout<< "-----Welcome to MyShell----- \n";
    cout<< "Please enter a command \n";
    string user_command;
    getline(cin, user_command);
/* token should be the strings prior to whitespaces indicating seperate arguments */
    char *token = strtok(user_command, delim);
    while(token){
      cout << token << endl;
      token = strtok(NULL, delim);
    }

    
 /* take user command and convert it to an array */
  

    //while(1){
      /* insert code here */

    //}

    return 0;
}
