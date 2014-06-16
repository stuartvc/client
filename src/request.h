#ifndef REQUEST_H_
#define REQUEST_H_
#include <string>
#include <map>
#include <iostream>
#include <stdio.h>
#include "user.h"

using namespace std;

enum Command {
    getCom = 0,
    setCom = 1,
    delCom = 2,
    noCom = 3
};

class Request {
    public:
        Request();
        Request(string command, 
                 string name, 
                 string location, 
                 int age, 
                 string password);

        inline string getCommand() {
            return command_;
        }

        inline string getName() {
            return name_;
        }

        inline string getLocation() {
            return location_;
        }

        inline int getAge() {
            return age_;
        }

        inline string getPassword() {
            return password_;
        }

        inline void addQuery(map<string, string> query) {
            query_ = query;
            return;
        }

        inline void setCommand(std::string command) {
            command_ = command;
        }

        string getQuery(string key);

        void setData();

        void push(User &User);

        void set(User &User);

    private:
        string command_;
        string name_;
        string location_;
        int age_;
        std::string password_;
        map<string, string> query_;
};


#endif
