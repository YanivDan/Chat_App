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

public:
    // Constructor & Discructor ->
    client(string usr_serv_ip, int usr_port);
    ~client();
    
    // Public functions ->
    
    // Function that starts the client
    int start_Run();

    
private:
    // Private Varialbe ->

    // User input - sever ip and port
    string m_server_ip;
    int m_server_port;
    
    // Get user input - Create a message buffer
    string m_data;
    
    // Create a message buffer and set it to 0
    char msg[512] = {0};

    // Socket int
    int m_clientSide;
    sockaddr_in m_sendSockAddr;

    // Private Functions - client use ->
    int m_setup_socket();
    int m_send_message();
    int m_disconnect();
    int m_connect();

};

#endif