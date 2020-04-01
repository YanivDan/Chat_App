#include <iostream>
#include "../include/client.h"
#include "../../Shared/argh.h"


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
    if(argc != 3)
    {
        cerr << "Usage: ip_address port" << endl;
        exit(0); 
    } 
    
    // Get the IP address and Port number 
    string serverIp = argv[1]; 
    int port = atoi(argv[2]); 

    client local(serverIp, port);
    local.Cli_Start_Run();
    
    
    cout<< "Connection closed" <<endl;
    // End of main
    return 0;
}