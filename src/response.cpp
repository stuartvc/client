#include "response.h"

Response::Response() {
    name_ = "";
    location_ = "";
    age_ = 0;
    password_ = "";
}
Response::Response(string name, 
                   string location, 
                   int age, 
                   string password) {
    name_ = name;
    location_ = location;
    age_ = age;
    password_ = password;
}

string Response::getQuery(string key) {
    string value;
    try {
        value = query_.at(key);
    }
    catch (const exception &ex) {
        value = "error";
    }
    return value;
}

void Response::set(User &User) {
    name_ = User.getName();
    location_ = User.getLocation();
    age_ = User.getAge();
    password_ = User.getPassword();
}

void Response::setData() {
    try {
        success_ = query_.at("success");
    }
    catch (const exception &ex) {
        success_ = "";
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
    try {
        message_ = query_.at("message");
    }
    catch (const exception &ex) {
        message_ = "";
    }
}
