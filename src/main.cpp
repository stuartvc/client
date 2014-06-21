#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include <boost/algorithm/string/predicate.hpp>
#include "user.h"
#include "socket.h"
#include "response.h"
#include "request.h"
#include "print.h"

typedef std::shared_ptr<User> UserPtr;
void setUser(std::vector<std::shared_ptr<User> > &userVec);
void getUser(std::vector<std::shared_ptr<User> > &userVec);
void deleteUser(std::vector<std::shared_ptr<User> > &userVec);
void modifyUser(std::vector<std::shared_ptr<User> > &userVec);


int main() {
    std::vector<std::shared_ptr<User> > userVec;
    std::string command;

    std::cout << "options: [get|set|mod|del]" << endl;
    std::cout << "what to do?: ";
    std::cin >> command;
    if (boost::iequals(command, "set")) {
        setUser(userVec);

    } else if (boost::iequals(command, "get")) {
        getUser(userVec);
    } else if (boost::iequals(command, "del")) {
        deleteUser(userVec);
    } else if (boost::iequals(command, "mod")) {
        modifyUser(userVec);
    } else {
        cout << "error" << endl;
        exit(1);
    }
    Print print;

    for (std::vector<UserPtr>::iterator it = userVec.begin(); it != userVec.end(); ++it) {
        Socket socket;
        Request request;
        Response response;
        request.set((**it));
        request.setCommand(command);
        socket.writeRequest(request);
        socket.readResponse(response);
        print.addResponse(response);
    }
    print.printTable();

    return 0;
}

void setUser(std::vector<std::shared_ptr<User> > &userVec) {
    int numToAdd = 0;
    std::string input;
    int inputInt;
    std::cout << "how many users to add?: ";
    std::cin >> numToAdd;

    while (--numToAdd >= 0) {
        UserPtr user (new User);
        std::cout << "Enter name: ";
        std::cin >> input;
        user->setName(input);
        std::cout << "Enter Location: ";
        std::cin >> input;
        user->setLocation(input);
        std::cout << "Enter Age: ";
        std::cin >> inputInt;
        user->setAge(inputInt);
        std::cout << "Enter Password: ";
        std::cin >> input;
        user->setPassword(input);

        userVec.push_back(user);
    }
}

void getUser(std::vector<std::shared_ptr<User> > &userVec) {
    int numToAdd = 0;
    std::string input;
    std::cout << "how many users to get?: ";
    std::cin >> numToAdd;

    while (--numToAdd >= 0) {
        UserPtr user (new User);
        std::cout << "Enter name: ";
        std::cin >> input;
        user->setName(input);

        userVec.push_back(user);
    }
}

void deleteUser(std::vector<std::shared_ptr<User> > &userVec) {
    int numToAdd = 0;
    std::string input;
    std::cout << "how many users to delete?: ";
    std::cin >> numToAdd;

    while (--numToAdd >= 0) {
        UserPtr user (new User);
        std::cout << "Enter name: ";
        std::cin >> input;
        user->setName(input);
        std::cout << "Enter Password: ";
        std::cin >> input;
        user->setPassword(input);

        userVec.push_back(user);
    }

}

void modifyUser(std::vector<std::shared_ptr<User> > &userVec) {
    int numToAdd = 0;
    std::string input;
    int inputInt;
    std::cout << "how many users to modify?: ";
    std::cin >> numToAdd;

    while (--numToAdd >= 0) {
        UserPtr user (new User);
        std::cout << "Enter name: ";
        std::cin >> input;
        user->setName(input);
        std::cout << "Enter Location: ";
        std::cin >> input;
        user->setLocation(input);
        std::cout << "Enter Age: ";
        std::cin >> inputInt;
        user->setAge(inputInt);
        std::cout << "Enter Password: ";
        std::cin >> input;
        user->setPassword(input);

        userVec.push_back(user);
    }

}

