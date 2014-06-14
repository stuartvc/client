#include <iostream>
#include <memory>
#include <vector>
#include <stdlib.h>
#include "user.h"
#include "socket.h"
#include "response.h"
#include "request.h"



int main() {
    typedef std::shared_ptr<User> UserPtr;
    std::vector<std::shared_ptr<User> > userVec;
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
    for (std::vector<UserPtr>::iterator it = userVec.begin(); it != userVec.end(); ++it) {
        Socket socket;
        Request request;
        Response response;
        request.set((**it));
        socket.writeRequest(request);
        socket.readResponse(response);
        std::cout << (*it)->getName() << " " << (*it)->getLocation() << " " << (*it)->getAge() << "\n";
    }

    return 0;
}
