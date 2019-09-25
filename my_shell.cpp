// my_shell.cpp : Simple Command Line Interpreter
// Copyright(c) Holland Ho 9/14/19
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstring> 

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
string command_check(string shell_command){
  string foo = "this doesn't work";
  string goo = "this works";

  if (shell_command == "dir"){
    return goo;
  }

  return foo; 
}

DWORD WINAPI MyThreadFunction(LPVOID Param);

int main(){
/* delim to check for command arguments amount */
    char delim[] = " ";
/* user inputs can be compared to the list of support commands */
    string com_list[3] = {"dir","ping","echo"};

    cout<< "-----Welcome to MyShell----- \n";

    while(1){

      cout<< "-----Please enter a command----- \n";
      string user_command;
      getline(cin, user_command);
      if (user_command == "exit"){
        cout << "exiting shell..... Thank you for using me! \n"; 
        break;
    }
/* converts user command to char to be parsed */
      char cstr[user_command.size() + 1];

/* token should be the strings prior to whitespaces indicating seperate arguments */
      char *token = strtok(strcpy(cstr, user_command.c_str()), delim);

      while(token){
      // ex. ping foo 
      // token[0] = ping, token[1] = foo
        //cout << token << endl;

      /* checks dir command */
        if (token == com_list[0]){
          system(token);
        }

      /* checks ping command */
        if (token == com_list[1]){
          cout << token << endl;
          char* first_arg = token;
          token = strtok(NULL, delim);
          // checks to see if there are enough arguments
          if(token == NULL){
            cout<<"invalid arguments, please try again... \n";
            break;
          }
          string combine = first_arg;
          combine.append(" ");
          combine.append(token);
          system(combine.c_str());
        
        }

      /* checks for echo note: assumption that arguments do not contain spaces  ie "hello world"*/
        if (token == com_list[2]){ 
          cout << token << endl;
          char* first_arg = token;
          token = strtok(NULL, delim);
          // if only one argument is given
          if(token == NULL){
            system(first_arg);
            break;
          }
          else{
            string combine = first_arg;
            cout << token << endl;
            combine.append(" ");
            combine.append(token);
            system(combine.c_str());
          }
      
        }

        token = strtok(NULL, delim);
    }
  }
    return 0;
}
