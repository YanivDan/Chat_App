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
    // Need to enter a port number - User input check 
    
    argh::parser cmdl(argv);
    string server_port, max_clients;
    
    // streaming into a string
    cmdl(1) >> server_port; 
    cmdl(2) >>max_clients;
    if(server_port != "" && max_clients != "")
    {
        // Cheacking user input server port
        if(atoi(server_port.c_str()) < 1000 && atoi(server_port.c_str()) > 10000)
        {
            cout<<"Invalid port number - enter a number between 1000 - 10,000"<<endl;
            return -1;
        }
        // Cheacking user input server port
        if(atoi(max_clients.c_str()) < 0 && atoi(max_clients.c_str()) > 50)
        {
            cout<<"Invalid max clients - enter a number between 1 - 50"<<endl;
            return -1;
        }

    }
    else
    {
        cout<<"Wrong input - please enter a input"<<endl;
        return -1;
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