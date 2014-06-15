#ifndef RESPONSE_H_
#define RESPONSE_H_
#include <string>
#include <map>
#include "user.h"

using namespace std;

class Response {
    public:
        Response();
        Response(string name, 
                 string location, 
                 int age, 
                 string password);

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

        void set(User &User);

        inline void addQuery(map<string, string> query) {
            query_ = query;
            return;
        }

        string getQuery(string key);

    private:
        string name_;
        string location_;
        int age_;
        string password_;
        map<string, string> query_;
};

#endif
