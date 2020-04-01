#include "client.h"

// Constructor 
Client::Client(string usr_serv_ip, int usr_port)
{
    m_server_ip = usr_serv_ip;
    m_server_port = usr_port;
}
 
// Discructor
Client::~Client()
{
    close(m_clientSide);
}


// client class functions
int Client::Setup_socket()
{
    
    // Setup a socket 
    struct hostent* host = gethostbyname(m_server_ip.c_str()); 
    
    // Init sockaddr_in struct
    bzero((char*)&m_sendSockAddr, sizeof(m_sendSockAddr)); 
    
    m_sendSockAddr.sin_family = AF_INET; 
    m_sendSockAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    m_sendSockAddr.sin_port = htons(m_server_port);
    
    // Create a socket
    m_clientSide = socket(AF_INET, SOCK_STREAM, 0);
    if(m_clientSide == -1)
    {
        cout<<"[*] Error while configuring the Listening socket, error number: "<< errno <<endl;
        return -1;    
    }
    return m_clientSide;
}

int Client::Connect_to_server()
{
    // Attempt connect to the server
    int statu = connect(Setup_socket(), (sockaddr*) &m_sendSockAddr, sizeof(m_sendSockAddr));
    if(statu == -1)
    {
            cout<<"[*] Error connecting to socket! error number: "<< errno <<endl; 
            return -1;
    }
    cout << "[*] Connected to the server!" << endl;
}

int Client::Disconnect_from_server()
{
    int a = close(m_clientSide);
    if (close(a) == -1)
    {
        cout << "[*] Error closing the socket, error number: "<< errno <<endl;
        return -1;
    }
    return 0;
}


int Client::Send_message()
{
    
    cout<<"-> ";
    
    // Get user input
    getline(cin, m_data);
    
    // Check if the send func worked
    if((send(m_clientSide, m_data.c_str(), sizeof(m_data.c_str()), 0)) == -1)
    {
        cout << "[*] Error sending the message, error number: "<< errno <<endl;
        if(Disconnect_from_server() == -1)
        {
            if(send(m_clientSide, to_string(DISCONNECT).c_str(), sizeof(to_string(DISCONNECT).c_str()), 0) == -1)
            {
                cout<<"Falied to disconnect"<<endl;
                exit(0);
            }
        }
    }
    return 0;
}
    
void Client::Check_user_input(string usr_input)
{
    // A variable to double check - make a secure connection
    bool verify_conecction = false;

    // Client Handle user input ->
    // Connect function - send to the server
    if (m_data == "Connect" && verify_conecction == false)
    {
        verify_conecction = true;
        Connect_to_server();
    }
    // Disconnect function 
    else if (m_data == "Disconnect" && verify_conecction == true)
    {
        verify_conecction = false;
        // Disconnect
        if(Disconnect_from_server() == -1)
        {
            if(send(m_clientSide, to_string(DISCONNECT).c_str(), sizeof(to_string(DISCONNECT).c_str()), 0) == -1)
            {
                cout<<"Falied to disconnect"<<endl;
                exit(0);
            }
        }
    }
    else if (m_data == "Disconnect" && verify_conecction == false)
    {
        // the client try to disconnect but is already diconnected
        cout << "[*] You are already disconnected try connect to the server using: 'Connect'"<<endl;;
    }

    // Send function - send to the server
    else if (m_data == "Send" && verify_conecction == true)
    {
        // Send Function
        Send_message();
    }

    // Exit function - send to the server
    else if (m_data == "Exit")
    {
        if(verify_conecction = true)
        {
            Disconnect_from_server();
        }
        // Exit  client -- צריך להשלים ------------------
    }
        
    // User input an unknown command
    else
    {
            cout<< "[*] This command is unknown, Please use: 'Connect', 'Disconnect', 'Send', 'Exit'"<<endl;
    }
}

// Main function to run the client
int Client::start_Run()
{
    // While loop to run as the client start
    while(true)
    {
        cout<< "-> ";
        
        // Get user input command 
        getline(cin, m_data);
        Check_user_input(m_data);
        
        // Get space between loops
        cout<<"\n";
    }
}