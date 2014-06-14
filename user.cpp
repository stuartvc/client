#include "user.h"


User::User() {
    name_="";
    location_="";
    age_=0;
    password_="";
}
User::User(std::string name,
           std::string location,
           int age,
           std::string password){
    name_ = name;
    location_ = location;
    age_ = age;
    password_ = password;
}
User::~User() {
}

std::string User::getName() {
    return name_;
}
std::string User::getLocation() {
    return location_;
}
int User::getAge() {
    return age_;
}
std::string User::getPassword() {
    return password_;
}
void User::setName(std::string name) {
    name_ = name;
}
void User::setLocation(std::string location) {
    location_ = location;
}
void User::setAge(int age) {
    age_ = age;
}
void User::setPassword(std::string password) {
    password_ = password;
}
