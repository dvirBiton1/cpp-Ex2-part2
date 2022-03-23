#include "Notebook.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
#include <map>

using namespace std;
namespace ariel
{
    Notebook::Notebook()
    {
    }
    Notebook::~Notebook()
    {
    }
    void Notebook::write(int page, int row, int col, Direction dir, string s)
    {
        int len = s.size();
        if (col + len > 100 && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < len; i++)
            {
                if (isalpha(nb[page][row][col + i]) || isdigit(nb[page][row][col + i]) || nb[page][row][col + i] == '~')
                {
                    throw runtime_error("you can't write twice in the same place");
                }

                nb[page][row][col + i] = s[(unsigned int)i];

                // cout<< page << row << i << ":" <<nb[page][row][i];
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (isalpha(nb[page][row+i][col]) || isdigit(nb[page][row+i][col]) || nb[page][row+i][col] == '~')
                {
                    throw runtime_error("you can't write twice in the same place");
                }
                nb[page][row + i][col] = s[(unsigned int)i];
                // cout<< page << i << row << ":"<< nb[page][i][row];
            }
        }
    }
    string Notebook::read(int page, int row, int col, Direction dir, int numOfChars)
    {
        if (col + numOfChars > 100 && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't read more then 100 charcters");
        }
        // if (page == 0 && row == 0 && col == 0 && dir == Direction::Horizontal && numOfChars == 4)
        // {
        //     return "stam";
        // }
        // if (page == 30 && row == 0 && col == 0 && dir == Direction::Horizontal && numOfChars == 4)
        // {
        //     return "stam";
        // }
        // if (page == 31 && row == 0 && col == 0 && dir == Direction::Vertical && numOfChars == 4)
        // {
        //     return "stam";
        // }
        // if (page == 0 && row == 6 && col == 0 && dir == Direction::Horizontal && numOfChars == 4)
        // {
        //     return "____";
        // }
        // if (page == 0 && row == 6 && col == 0 && dir == Direction::Vertical && numOfChars == 4)
        // {
        //     return "____";
        // }
        // if (page == 0 && row == 1 && col == 0 && dir == Direction::Horizontal && numOfChars == 4)
        // {
        //     return "abcd";
        // }
        // if (page == 0 && row == 2 && col == 0 && dir == Direction::Horizontal && numOfChars == 3)
        // {
        //     return "~~~";
        // }
        // if (page == 0 && row == 2 && col == 0 && dir == Direction::Horizontal && numOfChars == 4)
        // {
        //     return "~~~~";
        // }
        // if (page == 0 && row == 2 && col == 0 && dir == Direction::Horizontal && numOfChars == 5)
        // {
        //     return "~~~~_";
        // }
        // if (page == 0 && row == 0 && col == 0 && dir == Direction::Vertical && numOfChars == 3)
        // {
        //     return "sa~";
        // }
        // if (page == 0 && row == 0 && col == 1 && dir == Direction::Vertical && numOfChars == 4)
        // {
        //     return "tb~_";
        // }
        // if (page == 0 && row == 0 && col == 2 && dir == Direction::Vertical && numOfChars == 2)
        // {
        //     return "ac";
        // }
        string outPut;
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < numOfChars; i++)
            {
                if (isalpha(nb[page][row][col + i]) || isdigit(nb[page][row][col + i]) || nb[page][row][col + i] == '~')
                {
                    outPut += nb[page][row][col + i];
                }
                else
                {
                    outPut += '_';
                }
            }
        }
        else
        {
            for (int i = 0; i < numOfChars; i++)
            {
                if (isalpha(nb[page][row + i][col]) || isdigit(nb[page][row + i][col]) || nb[page][row + i][col] == '~')
                {
                    // cout<< "in if "<< nb[page][row + i][col] << endl;
                    outPut += nb[page][row + i][col];
                }
                else
                {
                    // cout<< "in else" << nb[page][i][col] << endl;
                    outPut += '_';
                }
            }
        }
        return outPut;
    }
    void Notebook::erase(int page, int row, int col, Direction dir, int numOfChars)
    {
        if (col + numOfChars > 100 && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < numOfChars; i++)
            {
                nb[page][row][col + i] = '~';
            }
        }
        else
        {
            for (int i = 0; i < numOfChars; i++)
            {
                nb[page][row + i][col] = '~';
            }
        }
    }
    void Notebook::show(int page)
    {
        // map<int, char[100]> temp;
        // temp = nb[page];
        //  for (auto& x:temp) {
        //     std::cout << x.first << ": " << x.second << std::endl;
        // }
        // for (auto iter = nb[page].begin(); iter != nb[page].end(); ++iter)
        // {
        //     cout <<iter->first << " " << iter->second << " ";
        // }
        cout << "\nshow func\n";
    }
}
