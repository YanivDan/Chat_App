#ifndef SERVER_H
#define SERVER_H

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
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/epoll.h> // epoll_create1(), epoll_ctl(), struct epoll_event
#include <errno.h>

#define BUFF_SIZE 10000
#define EPOLL_WAIT -1

using namespace std;
 

class Server
{
public:
    // Constructor & Discructor ->
    Server(int usr_enter_port, int max_connections);
    ~Server();
    
    // Public Functions ->

    // Function that set up a socket and bind it 
    int setup_and_open_socket();
    
    // Start the server and begin connection
    int server_start_run();

private:
    // the port the server will use
    int m_port;

    // Max connections that the server will get
    int m_max_connections;
    
    // Max connections that the server will get
     int m_client_list[100];

    //A buffer to send and receive messages
    char m_msg[BUFF_SIZE];

    // Setup a socket 
    sockaddr_in m_servAddr;

    // Open socket with internet address
    int m_serverSd;

    //private functions
    
    // Try to connect and create a server socket
    int Accept_connection();
    
    // Adds a new client to list
    void Add_a_client(int fd);
    
    // Remove a client from list
    void Remove_a_client(int fd);
    
    // Function to send messges to all the clients that connected to the server
    void Send_massage(int fd, string s);
    
    // Prints all the clients
    void Print_all_clients();
    
    // Function that check if the epoll at full capacity
    bool Check_if_client_list_full();
};

#endif
