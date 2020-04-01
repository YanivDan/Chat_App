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
#include <stdio.h>     // for fprintf()
#include <unistd.h>    // for close()
#include <sys/epoll.h> // for epoll_create1(), epoll_ctl(), struct epoll_event

#define BUFF_SIZE 10000
#define EPOLL_WAIT -1

using namespace std;
 

class Server
{
public:
    Server(int usr_enter_port, int max_connections);
    ~Server();
    
    // Public Functions

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
    int Accept_connection();
    void Add_a_client(int fd);
    void Remove_a_client(int fd);
    void Send_massage(int fd, string s);
    void Print_all_clients();
    bool Check_if_client_list_full();
    int Declineconn();

};

#endif
