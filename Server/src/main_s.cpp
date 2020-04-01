// Yaniv Dan Code - Server chat app - c++

// Include's
#include <iostream>
#include "argh.h"
#include <errno.h>
#include "server.h"

using namespace std;


// Server side - local
int main(int argc, char *argv[])
{
    //Get Port Number AND Max client connections
    
    
    argh::parser cmdl(argv);
    string server_port, max_clients;
    int a;
    cmdl(1) >> server_port; // streaming into a string
    cmdl(2) >>max_clients;
    if(server_port != "" && max_clients != "")
    {
        // Cheacking user input server port
        if(atoi(server_port.c_str()) > 1000 && atoi(server_port.c_str()) < 10000)
        {

        }
        // Cheacking user input server port
        if(atoi(max_clients.c_str()) > 0 && atoi(max_clients.c_str()) < 50)
        {

        }

    }
    
    

    
    
    
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