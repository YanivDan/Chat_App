// Yaniv Dan Code - Server chat app - c++

// Include's
#include <iostream>

#include "server.h"

using namespace std;


// Server side - local
int main(int argc, char *argv[])
{
    // Need to enter a port number - User input check 
    if(argc != 2)
    {
        cerr << "Please input a port number :)" << endl;
        exit(0);
    }
    server Server_side(atoi(argv[1]));
    Server_side.setup_and_open_socket();
    if (Server_side.server_start_run() == -1) 
        cout<< "The proccess has ended" <<endl;
}