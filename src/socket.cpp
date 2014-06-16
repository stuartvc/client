#include "socket.h"        
#include "parse.h"
//#include "logging.h"
#include <iostream>

Socket::Socket() {
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ < 0) 
        error("ERROR opening socket");
    server_ = gethostbyname("localhost");
    memset((char *) &serv_addr_, 0, sizeof(serv_addr_));
    serv_addr_.sin_family = AF_INET;
    memcpy((char *)&serv_addr_.sin_addr.s_addr,
          (char *)server_->h_addr, 
          server_->h_length);
    serv_addr_.sin_port = htons(50000);
    if (connect(sockfd_,(struct sockaddr *) &serv_addr_,sizeof(serv_addr_)) < 0) 
        error("ERROR connecting");
}

Socket::~Socket() {
    close(sockfd_);
}

void Socket::readResponse(Response &response) {
    char buffer[256];
    memset(buffer, 0, 256);
    int n = read(sockfd_,buffer,255);
    if (n < 0) error("ERROR reading from socket");

    //log.log("Got message: " + std::string(buffer) + " from: " + std::string(addr));
    cout << "read: " << buffer << endl;
    parse(response, buffer);
    //response.setData();
}

void Socket::writeRequest(Request &request) {
    char buffer[256];
    int len;
    memset(buffer, 0, 256);
    sprintf(buffer, "command=%s:name=%s:location=%s:age=%i:password=%s",
            request.getCommand().c_str(),
            request.getName().c_str(),
            request.getLocation().c_str(),
            request.getAge(),
            request.getPassword().c_str());
    len = strlen(buffer);
    //log.log("sent message: " + std::string(buffer));
    cout << "sent: " << buffer << endl;
    int n = write(sockfd_,buffer,len);
    if (n < 0) error("ERROR writing to socket");
}

