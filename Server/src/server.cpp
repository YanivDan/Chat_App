#include "../include/server.h"


server::server(int usr_input){
    this->port = usr_input;
    cout<< "Server have a port number" <<endl;
}

server::~server(){
    
    // Close the socket 
    close(serverSd);
}

void server::setup_and_open_socket(){
    
    // Setup a socket
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);

    
    // Open socket with internet address
    this->serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
        cerr << "Error in the the server socket" << endl;
        exit(0);
    }
    
    
    // Bind the socket to local address
    int bindStatus = bind(serverSd, (struct sockaddr*) &servAddr, sizeof(servAddr));
    if(bindStatus < 0)
    {
        cerr << "Error binding socket" << endl;
        exit(0);
    }
    cout<< "Waiting for a client"<< endl;
}


int server::server_start_run(){
    //Listen for up to 5 requests at a time
    listen(serverSd, 5);
    
    //Receive a request from client using accept
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
    
     
    //accept a new socket descriptor to handle the new connection with client
    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if(newSd < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }
    cout << "Connected with client!" << endl;
    
    
    while(true)
    {
        // Receive a message from the client (listen)
        cout << "Waiting for client" << endl;
        
        // Clear the buffer
        memset(&msg, 0, sizeof(msg));
        
        // Get the message from the client
        recv(newSd, (char*)&msg, sizeof(msg), 0);
        
        if(!strcmp(msg, "exit"))
        {
            cout << "Client has quit the session" << endl;
            break;
        }

        // Print's the message
        cout << "Client: " << msg << endl;
        cout << "> ";      
    }
    
    close(newSd);
    cout << "Connection closed!" << endl;

    return -1;
}


