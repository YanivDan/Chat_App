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

using namespace std;


class server
{
private:
    // the port the server will use
    int port;

    //A buffer to send and receive messages
    char msg[512];

    // Setup a socket 
    sockaddr_in servAddr;

    // Open socket with internet address
    int serverSd;

public:
    server(int usr_enter_port);
    ~server();
    void setup_and_open_socket();
    int server_start_run();

};

#endif