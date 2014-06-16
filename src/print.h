#ifndef TABLE_H_
#define TABLE_H_
#include <vector>
#include <string>


class Print {
    public:
        Print();
        Print(std::vector<std::string> headers, 
              std::vector<std::vector<std::string> > rows);
        void printTable();
    private:
        void calcWidth();

        std::vector<std::string> headers_;
        std::vector<std::vector<std::string> > rows_;
        std::vector<unsigned int> width_;
};



#endif
