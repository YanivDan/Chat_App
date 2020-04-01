#include "../include/client.h"

// Constructor 
client::client(string usr_serv_ip, int usr_port)
{
    m_server_ip = usr_serv_ip;
    m_server_port = usr_port;
}
 
// Discructor
client::~client()
{
    close(m_clientSide);
}


// client class functions
int client::m_setup_socket(){
    // Setup a socket 
    struct hostent* host = gethostbyname(m_server_ip.c_str()); 
    
    // Init sockaddr_in struct
    bzero((char*)&m_sendSockAddr, sizeof(m_sendSockAddr)); 
    
    m_sendSockAddr.sin_family = AF_INET; 
    m_sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    m_sendSockAddr.sin_port = htons(this->m_server_port);
    
    // Create a socket
    m_clientSide = socket(AF_INET, SOCK_STREAM, 0);
    if(m_clientSide == -1){
        cout<<"[*] Error while configuring the Listening socket"<<endl;
        return -1;    
    }
    return this->m_clientSide;
}

int client::m_connect(){
    // Attempt connect to the server
    int statu = connect(m_setup_socket(), (sockaddr*) &m_sendSockAddr, sizeof(m_sendSockAddr));
    if(statu < 0){
            cout<<"[*] Error connecting to socket!"<<endl; 
            return -1;
    }
    cout << "[*] Connected to the server!" << endl;
}

int client::m_disconnect(){
    int a = close(m_clientSide);
    if (close(a) == -1)
    {
        cout << "[*] Error closing the socket"<<endl;
        return -1;
    }
    return 0;
}


int client::m_send_message(){
    
    cout<<"-> ";
    
    // Get user input
    getline(cin, m_data);
    
    // Check if the send func worked
    if((send(m_clientSide, m_data.c_str(), sizeof(m_data.c_str()), 0)) == -1){
        cout << "[*] Error sending the message"<<endl;
        this->m_disconnect();
        return -1;
    }
    return 0;
}
    

int client::start_Run(){
    // A variable to double check and make a secure connection
    bool verify_conecction = false;
    
    // While loop to run as the client start
    while(true)
    {
        cout<< "-> ";
        
        // Get user input command 
        getline(cin, m_data);

        // Client Handle user input ->
        // Connect function - send to the server
        if (m_data == "Connect" && verify_conecction == false){
            verify_conecction = true;
            this->m_connect();
        }

        // Disconnect function 
        else if (m_data == "Disconnect" && verify_conecction == true){
            verify_conecction = false;
            // Disconnect
            this->m_disconnect();
        }
        else if (m_data == "Disconnect" && verify_conecction == false){
            // the client try to disconnect but is already diconnected
            cout << "[*] You are already disconnected try connect to the server using: 'Connect'"<<endl;;
        }

        // Send function - send to the server
        else if (m_data == "Send" && verify_conecction == true){
            // Send Function
            this->m_send_message();
        }

        // Exit function - send to the server
        else if (m_data == "Exit"){
            if(verify_conecction = true){
                this->m_disconnect();
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