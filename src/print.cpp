#include "print.h"
#include <iostream>
#include <iomanip>

Print::Print() {
    headers_.push_back("success");
    headers_.push_back("name");
    headers_.push_back("location");
    headers_.push_back("age");
    headers_.push_back("message");
}

Print::Print(std::vector<std::string> headers, 
             std::vector<std::vector<std::string> > rows) {
    headers_ = headers;
    rows_ = rows;
}

void Print::printTable() {

    //calculate width
    calcWidth();
    std::cout << std::endl;
    for (std::vector<std::string>::iterator it = headers_.begin();
            it != headers_.end();
            ++it) {
        std::cout << std::setw(width_[it - headers_.begin()]) << *it << "|";
    }
    std::cout << std::endl;
    std::cout << std::setw(totalWidth_) << setfill('-') << "-" << setfill(' ') << endl;

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
    std::cout << std::endl;
}

void Print::addResponse(Response response) {
    vector<std::string> row;
    row.push_back(response.getSuccess());
    row.push_back(response.getName());
    row.push_back(response.getLocation());
    row.push_back(to_string(response.getAge()));
    row.push_back(response.getMessage());
    rows_.push_back(row);
}

void Print::calcWidth() {
    totalWidth_ = 0;
    for (std::vector<std::string>::iterator it = headers_.begin();
            it != headers_.end();
            ++it) {
        width_.push_back(it->length());
    }
    for (std::vector<std::vector<std::string> >::iterator it = rows_.begin();
            it != rows_.end();
            ++it) {
        for (std::vector<std::string>::iterator iter = it->begin();
                iter != it->end();
                ++iter) {
            if (width_[iter - it->begin()] < iter->length())
                width_[iter - it->begin()] = iter->length();
        }
    }
    for (std::vector<unsigned int>::iterator it = width_.begin(); it != width_.end(); ++it) {
            ++totalWidth_ += *it;
    }
}
