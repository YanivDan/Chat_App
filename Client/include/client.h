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
#include <errno.h>

#define DISCONNECT -1

using namespace std;

class Client
{

public:
    // Constructor & Discructor ->
    Client(string usr_serv_ip, int usr_port);
    ~Client();
    
    // Public functions ->
    
    // Function that starts the client
    int Start_Run();

    
private:
    // Private Varialbe ->

    // User input - sever ip and port
    string m_server_ip;
    int m_server_port;
    
    // Get user input - Create a message buffer
    string m_data;
    
    // Create a message buffer and set it to 0
    char m_msg[512];

    // Socket int
    int m_clientSide;
    sockaddr_in m_sendSockAddr;
    
    // A variable to double check - make a secure connection
    bool m_verify_conecction = false;

    // Private Functions - client use ->
    
    // Setup the socket
    int Setup_socket();
    
    // Try to connect to the server
    int Connect_to_server();
    
    // Client want to disconnect from the server
    int Disconnect_from_server();
    
    //  Check what the command the client want to do
    void Check_user_input(string usr_input);
    
    // Send the message to the server
    int Send_message();
};

#endif