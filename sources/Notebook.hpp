#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Direction.hpp"
#include <unordered_map>

// const int line = 100;
using namespace std;
// using namespace ariel;
namespace ariel
{
    class Notebook
    {
    private:
        unordered_map< int, unordered_map< int, char[100]>> nb;
        // vector<vector<char[100]>>nb;
    public:
        Notebook(/* args */);
        ~Notebook();
        void write( int page,  int row, int col, Direction dir, string s);
        string read( int page, int row,  int col, Direction dir, int numOfChars);
        void erase( int page,  int row,  int col, Direction dir,  int numOfChars);
        void show( int page);
    };

    // Notebook::Notebook(/* args */)
    // {
    //     return;
    // }

    // Notebook::~Notebook()
    // {
    //     return;
    // }
};