#ifndef TABLE_H_
#define TABLE_H_
#include <vector>
#include <string>
#include "response.h"


class Print {
    public:
        Print();
        Print(std::vector<std::string> headers, 
              std::vector<std::vector<std::string> > rows);
        void printTable();
        void addResponse(Response response);
    private:
        void calcWidth();

        std::vector<std::string> headers_;
        std::vector<std::vector<std::string> > rows_;
        std::vector<unsigned int> width_;
        int totalWidth_;
};



#endif
