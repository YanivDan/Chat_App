#include "server.h"
#include "timer.h"

#define EPOLL_WAIT_TIME 15000

Server::Server(int usr_input, int max_connections){
    m_port = usr_input;
    m_max_connections = max_connections;
    
    // Clear the clients list
    for(int i=0; i<m_max_connections; i++)
    {
        m_client_list[i] = 0;
    }
    cout<<"Server got a port number" <<endl;
    cout<<"Server got it's max connections option"<<endl;
    cout<<"Server initilaze!"<<endl;
}

Server::~Server(){
    
    // Close the socket 
    close(m_serverSd);
}


// Function to print al the clients
void Server::Print_all_clients()
{
    for(int i =0; i<m_max_connections; i++)
    {
        cout<<m_client_list[i]<<endl;
    }
}


// Checks if the client list is full for mor clients
bool Server::Check_if_client_list_full()
{
    for(int i=0; i<m_max_connections; i++)
    {
        if(m_client_list[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// Funcion that add a new client to client list in the first open space
void Server::Add_a_client(int fd)
{
    for(int i=0; i<m_max_connections; i++)
    {
        if(m_client_list[i] == 0)
        {
            m_client_list[i] = fd;
            break;
        }
    }
}


// Create a socket then apply an acceept function
int Server::Accept_connection()
{
    //Receive a request from client using accept 
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
    
     
    //accept a new socket descriptor to handle the new connection with client
    int newSd = accept(m_serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    
    if(newSd == -1)
    {
        cout << "[*] Error accepting the client, error number: " << errno << "\n";
        return -1;
    }
    cout << GetTimeLocal() << "[*] Someone new connected with ID: " << newSd << "\n";
    
    return newSd;
}

// Function that send a message from the client
void Server::Send_massage(int socket_con_num, string user_input_message)
{   
    if(send(socket_con_num, user_input_message.c_str(), sizeof(user_input_message.c_str()), 0) == -1)
    {
        cout << "[*] Failed sending the message: " << socket_con_num << " error number: " << errno <<endl;
        cout<<"Please try again"<<endl;
    }
}

// Remove client with the socket from the events
void Server::Remove_a_client(int socket_con_num)
{
    for(int i=0; i<m_max_connections; i++)
    {
        if (m_client_list[i] == socket_con_num)
        {
            m_client_list[i] = 0;
            break;
        }
    }
}

int Server::setup_and_open_socket(){
    
    // Setup a socket
    bzero((char*)&m_servAddr, sizeof(m_servAddr));
    m_servAddr.sin_family = AF_INET;
    m_servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_servAddr.sin_port = htons(m_port);

    
    // Open socket with internet address
    m_serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_serverSd < 0)
    {
        cerr << "Error in the the server socket, error number: "<< errno << endl;
        return -1;
    }
    
    
    // Bind the socket to local address
    int bindStatus = bind(m_serverSd, (struct sockaddr*) &m_servAddr, sizeof(m_servAddr));
    if(bindStatus < 0)
    {
        cerr << "Error binding socket, error number: "<< errno << endl;
        return -1;
    }
    cout << "Waiting for a client to connect"<<endl;
    return 0;
}


// Main function that run all the server private functions
int Server::server_start_run(){
    
    // Open the server socket
    if(setup_and_open_socket() == -1)
    {
        cout<<"Could not setup the socket"<<endl;
        return -1;
    }
    
    // Create an epoll
    int epoll_fd = epoll_create(m_max_connections);
    int epo_wait = 0;
    epoll_event ev_server, events[m_max_connections];
    
    // Check the epoll was created
    if(epoll_fd == -1)
    {
        cout << "[*] Failed to Create epoll, error number: " << errno <<endl;
        return -1;
    }
 
    ev_server.events = EPOLLIN;
    ev_server.data.fd = m_serverSd;

    //Listen for up to 'm_max_connections' requests
    if(listen(m_serverSd, m_max_connections) == -1)
    {
        cout << "[*] Failed listen to incoming requests, error number: " << errno <<endl;
        return -1;
    }
    
    // Create the first epoll that will listen and then add the cleints connections
    int epo_cre = epoll_ctl(epoll_fd,  EPOLL_CTL_ADD, m_serverSd, &ev_server);
    if(epo_cre == -1)
    {
        cout<< "Failed to add file descriptor to epoll" <<endl;
    }

    while(true)
    {
        epo_wait = epoll_wait(epoll_fd, events, m_max_connections, EPOLL_WAIT_TIME);

        if (epo_wait == -1)
        {
            cout << "[*] Failed to on epoll_wait function, error number: " << errno <<endl;
            exit(EXIT_FAILURE);
        }
    

        // Run on all the clients who want to connect
        for(int i = 0; i < epo_wait; i++)
            {   
                if(events[i].data.fd == m_serverSd)
                {
                    // Check if thier is a client who want to connect
                    if(Check_if_client_list_full() == false)
                    {
                        // Try to accept the connection
                        int clientsock = Accept_connection();

                        // Add the client to the client list and creat a - 'intrest list'
                        Add_a_client(clientsock);
                        ev_server.events = EPOLLIN;
                        ev_server.data.fd = clientsock;
                        epoll_ctl(epoll_fd, EPOLL_CTL_ADD, clientsock, &ev_server);
                        
                        // Send all the client that a new client has connected
                        for(int client_id = 0; client_id < m_max_connections; client_id++)
                        {
                            if((m_client_list[client_id] != clientsock) && (m_client_list[client_id] != 0))
                            {
                                string has_connected_message = "User:" + to_string(clientsock) + " has connected";
                                Send_massage(m_client_list[client_id], has_connected_message.c_str());
                            }
                        }
                    }
                    else
                    {
                        cout << GetTimeLocal() << "[*] At max cappacity, the connection is not approved"<<endl;
                        cout<<"\n";
                    }
                }
                // The client exist and want to send a message
                else
                {
                    // Clear the buffer
                    memset(&m_msg, 0, sizeof(m_msg));
                    
                    // Read the data
                    int byteread = recv(events[i].data.fd, &m_msg, sizeof(m_msg), 0);
                    
                    // Check if their is any bytes
                    if(byteread > 0 && strcmp(m_msg, "-1") != 0)
                    {
                        // Prints the client message to the server
                        cout << GetTimeLocal() << "[*] Client number: '" << events[i].data.fd << "' Says: "<< m_msg <<endl;
                        
                        // Get Space in printing
                        cout<<""<<endl;

                        for(int j = 0; j < m_max_connections; j++)
                        {
                            if((m_client_list[j] != events[i].data.fd) && (m_client_list[j] != 0))                     
                            {
                                string client_message = "User number:" + to_string(events[i].data.fd) + " " + string(m_msg, BUFF_SIZE);
                                
                                // Send the client message to everyone
                                Send_massage(m_client_list[j], client_message.c_str()); 
                            }
                        }
                    }

                    // Client want to disconnect 
                    else
                    {
                        // Remove client from epoll and client list
                        
                        // Get the client socket
                        int clientsock_disconnect = events[i].data.fd;
                        ev_server.data.fd = events[i].data.fd;
                        
                        // Delete the client from the events
                        epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, &ev_server);
                        
                        // Call function to remove client from client list
                        Remove_a_client(events[i].data.fd);
                        
                        // Prints to the server that the client has been disconnected
                        cout << GetTimeLocal() << "[-] " << events[i].data.fd << " has been disconnected"<<endl;

                        // Send message to everyone that a client has been disconnected
                        for(int everyone = 0; everyone < m_max_connections; everyone++)
                        {
                            if(m_client_list[everyone] != 0)
                            {
                                // Create a disconnect message to everyone
                                string disconnect_message = "User number:" + to_string(clientsock_disconnect) + " Has been disconnected";
                                Send_massage(m_client_list[everyone], disconnect_message.c_str());
                            }
                        }

                    }
                }
            }
    }
}
