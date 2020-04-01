#include "../include/client.h"

// Constructor 
client::client(string usr_serv_ip, int usr_port)
{
    this->server_ip = usr_serv_ip;
    this->server_port = usr_port;
}

// Discructor
client::~client()
{
    close(this->clientSide);
}


// client class functions
int client::Cli_setup_socket(){
    // Setup a socket 
    struct hostent* host = gethostbyname(this->server_ip.c_str()); 
    
    // Init sockaddr_in struct
    bzero((char*)&this->sendSockAddr, sizeof(this->sendSockAddr)); 
    
    this->sendSockAddr.sin_family = AF_INET; 
    this->sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    this->sendSockAddr.sin_port = htons(this->server_port);
    
    // Create a socket
    this->clientSide = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSide == -1){
        cout<<"[*] Error while configuring the Listening socket"<<endl;
        return -1;    
    }
    return this->clientSide;
}

int client::CLi_connect(){
    // Attempt connect to the server
    int statu = connect(this->Cli_setup_socket(), (sockaddr*) &this->sendSockAddr, sizeof(this->sendSockAddr));
    if(statu < 0){
            cout<<"[*] Error connecting to socket!"<<endl; 
            return -1;
    }
    cout << "[*] Connected to the server!" << endl;
}

int client::Cli_disconnect(){
    if (close(this->clientSide) == -1)
    {
        cout << "[*] Error closing the socket"<<endl;
        return -1;
    }
    return 0;
}


int client::Cli_send_message(){
    
    cout<<"-> ";
    
    // Get user input
    getline(cin, this->data);
    
    // Check if the send func worked
    if((send(this->clientSide, this->data.c_str(), sizeof(this->data.c_str()), 0)) == -1){
        cout << "[*] Error sending the message"<<endl;
        this->Cli_disconnect();
        return -1;
    }
    return 0;
}
    

int client::Cli_Start_Run(){
    // A variable to double check and make a secure connection
    bool verify_conecction = false;
    
    // While loop to run as the client start
    while(true)
    {
        cout<< "-> ";
        
        // Get user input command 
        getline(cin, this->data);

        // Client Handle user input ->
        // Connect function - send to the server
        if (this->data == "Connect" && verify_conecction == false){
            verify_conecction = true;
            this->CLi_connect();
        }

        // Disconnect function 
        else if (this->data == "Disconnect" && verify_conecction == true){
            verify_conecction = false;
            // Disconnect
            this->Cli_disconnect();
        }
        else if (this->data == "Disconnect" && verify_conecction == false){
            // the client try to disconnect but is already diconnected
            cout << "[*] You are already disconnected try connect to the server using: 'Connect'"<<endl;;
        }

        // Send function - send to the server
        else if (this->data == "Send" && verify_conecction == true){
            // Send Function
            this->Cli_send_message();
        }

        // Exit function - send to the server
        else if (this->data == "Exit"){
            if(verify_conecction = true){
                this->Cli_disconnect();
            }
            // Send to the server that the client exit
            //send(clientSide, this->data.c_str(), strlen(this->data.c_str()), 0);
            break;
        }
        
        // User input an unknown command
        else
        {
            cout<< "[*] This command is unknown, Please use: 'Connect', 'Disconnect', 'Send', 'Exit'"<<endl;
        }
        
        // Get space between loops
        cout<<"\n";
    }

}