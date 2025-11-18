#include "com/owl.hh"

#include <netinet/in.h>
#include <sys/socket.h>

#include <unistd.h>
#include <iostream>

#define PORT 8080

namespace com
{

    owl::owl()
    {
        int server_fd, new_socket;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[1024] = {0};

        // Create socket
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == 0)
        {
            // fmt::println("Socket creation error");
        }

        // Attach socket to the port
        setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Bind
        if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        {
            // fmt::println("Bind failed");
        }

        // Listen
        if (listen(server_fd, 3) < 0)
        {
            // fmt::println("Listen failed");
        }

        // Accept a connection
        new_socket =
            accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0)
        {
            // fmt::println("Accept failed");
        }

        // Read data
        read(new_socket, buffer, 1024);
        std::cout << "Message from client: " << buffer << std::endl;

        // Close socket
        close(new_socket);
        close(server_fd);
    }

    owl::~owl()
    {
    }

} // namespace com