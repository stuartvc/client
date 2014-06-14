#include "request.h"
#include <stdlib.h>

Request::Request() {
    command_ = getCom;
    name_ = "";
    location_ = "";
    age_ = 0;
    password_ = "";
}
Request::Request(Command command, 
                 string name, 
                 string location, 
                 int age, 
                 string password) {
    command_ = command;
    name_ = name;
    location_ = location;
    age_ = age;
    password_ = password;
}

string Request::getQuery(string key) {
    string value;
    try {
        value = query_.at(key);
    }
    catch (const exception &ex) {
        value = "error";
    }
    return value;
}

void Request::setData() {
    try {
        string command = query_.at("command");
        if (!command.compare("get")) {
            command_ = getCom;
        }
        else if (!command.compare("set")) {
            command_ = setCom;
        }
        else if (!command.compare("del")) {
            command_ = delCom;
        }
        else {
            command_ = noCom;
        }
    }
    catch (const exception &ex) {
        command_ = noCom;
    }
    try {
        name_ = query_.at("name");
    }
    catch (const exception &ex) {
        name_ = "";
    }
    try {
        location_ = query_.at("location");
    }
    catch (const exception &ex) {
        location_ = "";
    }
    try {
        age_ = atoi(query_.at("age").c_str());
    }
    catch (const exception &ex) {
        age_ = 0;
    }
    try {
        password_ = query_.at("password");
    }
    catch (const exception &ex) {
        password_ = "";
    }
}

void Request::push(User &User) {
    User.setName(name_);
    User.setLocation(location_);
    User.setAge(age_);
    User.setPassword(password_);
}

void Request::set(User &User) {
    command_ = setCom;
    name_ = User.getName();
    location_ = User.getLocation();
    age_ = User.getAge();
    password_ = User.getPassword();
}

