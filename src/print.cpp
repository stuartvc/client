#include "print.h"
#include <iostream>
#include <iomanip>

Print::Print() {
}

Print::Print(std::vector<std::string> headers, 
             std::vector<std::vector<std::string> > rows) {
    headers_ = headers;
    rows_ = rows;
}

void Print::printTable() {

    //calculate width
    calcWidth();
    for (std::vector<std::string>::iterator it = headers_.begin();
            it != headers_.end();
            ++it) {
        std::cout << std::setw(width_[it - headers_.begin()]) << *it << "|";
    }
    std::cout << std::endl;
    for (std::vector<std::vector<std::string> >::iterator it = rows_.begin();
            it != rows_.end();
            ++it) {
        for (std::vector<std::string>::iterator iter = it->begin();
                iter != it->end();
                ++iter) {
            std::cout << std::setw(width_[iter - it->begin()]) << *iter << "|";
        }
        std::cout << std::endl;
    }



}
void Print::calcWidth() {
    for (std::vector<std::string>::iterator it = headers_.begin();
            it != headers_.end();
            ++it) {
        width_.push_back(it->length());
        std::cout << it->length() << " ";
    }
    for (std::vector<std::vector<std::string> >::iterator it = rows_.begin();
            it != rows_.end();
            ++it) {
        for (std::vector<std::string>::iterator iter = it->begin();
                iter != it->end();
                ++iter) {
            if (width_[iter - it->begin()] < iter->length())
                width_[iter - it->begin()] = iter->length();
            std::cout << iter->length() << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
