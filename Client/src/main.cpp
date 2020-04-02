#include <iostream>
#include "client.h"
#include "argh.h"
 

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>

using namespace std;


// Client side - local

int main(int argc, char *argv[])
{
    // Check if the user input 2 things: IP address, Port number
    argh::parser cmdl(argv);
    string server_port_input, server_ip_input;
    char buffer[11];
    
    // streaming into a string
    cmdl(1) >> server_port_input; 
    cmdl(2) >>server_ip_input;
    
    // Check that user enterd 2 values
    // Get the IP address and Port number
    if(server_port_input != "" && server_ip_input != "")
    {
        // Cheacking user input client port
        if(atoi(server_port_input.c_str()) < 1000 || atoi(server_port_input.c_str()) > 10000)
        {
            cout<<"Invalid port number - enter a number between 1000 - 10,000! Got: "<< server_port_input<<endl;
            return -1;
        }
        // Cheacking user input client ip
        if(inet_pton(AF_INET, server_ip_input.c_str(), &buffer) != 1)
        {
            cout << "Must provide a valid IP address value! Got '" << server_ip_input << "'" <<endl;
            return -1;
        }
    }
    else
    {
        cout<<"Wrong input - please enter a input"<<endl;
        return -1;
    } 

    Client local(server_ip_input, atoi(server_port_input.c_str()));
    local.Start_Run();
    
    
    cout<< "Connection closed" <<endl;
    // End of main
    return 0;
}