#ifndef CLIENT_H
#define CLIENT_H

// Include's
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

class client
{
private:
    // Private Varialbe ->

    // User input - sever ip and port
    string server_ip;
    int server_port = 0;
    
    // Get user input - Create a message buffer
    string data;
    
    // Create a message buffer and set it to 0
    char msg[512] = {0};

    // Socket int
    int clientSide = 0;
    sockaddr_in sendSockAddr;

    // Private Functions - client use ->
    int Cli_setup_socket();
    int Cli_send_message();
    int Cli_disconnect();
    int CLi_connect();

public:
    // Constructor & Discructor ->
    client(string usr_serv_ip, int usr_port);
    ~client();
    
    // Public functions ->
    
    // Function that starts the client
    int Cli_Start_Run();

};

#endif
