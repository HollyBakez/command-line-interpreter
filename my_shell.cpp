// my_shell.cpp : Simple Command Line Interpreter
// Copyright(c) Holland Ho 9/14/19

#include <iostream>
#include <stdio.h>
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
    string user_command;

    while(1){
      /* insert code here */

    }

    return 0;
}
