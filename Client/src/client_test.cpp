// Yaniv Dan Code - Client chat app - c++

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
#include <sys/time.h>
#include <sys/wait.h>

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
    char *serverIp = argv[1]; 
    int port = atoi(argv[2]); 
    
    
    // Create a message buffer 
    char msg[512] = {0}; 
    
    
    // Setup a socket 
    struct hostent* host = gethostbyname(serverIp); 
    sockaddr_in sendSockAddr; 

    bzero((char*)&sendSockAddr, sizeof(sendSockAddr)); 
    
    sendSockAddr.sin_family = AF_INET; 
    sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    sendSockAddr.sin_port = htons(port);
    
    int clientSide = socket(AF_INET, SOCK_STREAM, 0);
    
    
    // Attempt connect to the server
    int statu = connect(clientSide, (sockaddr*) &sendSockAddr, sizeof(sendSockAddr));
    if(statu < 0)
    {
        cout<<"Error connecting to socket!"<<endl; 
        exit(0);
    }
    cout << "Connected to the server!" << endl;
    

    
    while(1)
    {
        cout << ">";
        string data;
        getline(cin, data);

        // Clear the buffer
        memset(&msg, 0, sizeof(msg));
        strcpy(msg, data.c_str());
        if(data == "exit")
        {
            send(clientSide, (char*)&msg, strlen(msg), 0);
            break;
        }
        
        send(clientSide, (char*)&msg, strlen(msg), 0);
        cout << "Waiting server response" << endl;
        
        // Clear the buffer
        memset(&msg, 0, sizeof(msg));
        recv(clientSide, (char*)&msg, sizeof(msg), 0);
        
        if(!strcmp(msg, "exit"))
        {
            cout << "Server has quit the session" << endl;
            break;
        }
        
        // Print's the server msg
        cout << "Server: " << msg << endl;
    }

    close(clientSide);
    
    // cout << "Bytes written: " << bytesWritten << " Bytes read: " << bytesRead << endl;
    
    cout << "Connection closed" << endl;
    return 0;    
}