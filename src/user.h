#ifndef USER_H_
#define USER_H_
#include <string>
#include <stdlib.h>

//using namespace std;

class User {
    public:
        User();
        User(std::string name,
             std::string location,
             int age,
             std::string password);
        ~User();

        std::string getName();
        std::string getLocation();
        int getAge();
        std::string getPassword();
        void setName(std::string name);
        void setLocation(std::string location);
        void setAge(int age);
        void setPassword(std::string password);

    private:
        std::string name_;
        std::string location_;
        int age_;
        std::string password_;
};



#endif
