#ifndef SOCKET_H_
#define SOCKET_H_
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "request.h"
#include "response.h"

class Socket {
    public:
        Socket();
        ~Socket();
        void writeRequest(Request &request);
        void readResponse(Response &response);

    private:
        void error();
        inline void error(const char *msg) {
            perror(msg);
            exit(1);
        }

        int sockfd_;
        struct sockaddr_in serv_addr_;
        struct hostent *server_;
};


#endif
