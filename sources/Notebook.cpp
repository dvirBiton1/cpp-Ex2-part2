#include "Notebook.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
#include <map>
#include <locale>
#include <cctype>

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
        const int minChar = 32;
        const int maxChar = 125;
        const int maxLen = 99;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[(unsigned int)i] < minChar || s[(unsigned int)i] >maxChar )
            {
                throw runtime_error("unvalid symbol");
            }
            
        }
        
        if (page < 0 || row < 0 || col < 0)
        {
            throw runtime_error("negtive");
        }
        if (col > maxLen)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        if (col + len > maxLen && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < len; i++)
            {
                if (s[(unsigned int)i] == '~' || nb[page][row][col + i] == '~')
                {
                    throw runtime_error("you can't write twice in the same place");
                }
                if (minChar <= nb[page][row][col + i] && nb[page][row][col + i] <= maxChar)
                {
                    if (nb[page][row][col + i] == '_')
                    {
                        nb[page][row][col + i] = s[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("you can't write twice in the same place");
                    }
                }
                else
                {
                    nb[page][row][col + i] = s[(unsigned int)i];
                }

                // cout<< page << row << i << ":" <<nb[page][row][i];
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (s[(unsigned int)i] == '~' || nb[page][row + i][col] == '~')
                {
                    throw runtime_error("you can't write twice in the same place");
                }
                if (minChar <= nb[page][row + i][col] && nb[page][row + i][col] <= maxChar)
                {
                    if (nb[page][row + i][col] == '_')
                    {
                        nb[page][row + i][col] = s[(unsigned int)i];
                    }
                    else
                    {
                        throw runtime_error("you can't write twice in the same place");
                    }
                }
                else
                {
                    nb[page][row + i][col] = s[(unsigned int)i];
                }

                // cout<< page << i << row << ":"<< nb[page][i][row];
            }
        }
        // for (int i = 0; i < len; i++)
        // {
        //     cout<<"witre:\n"<< nb[page][row][col+i]<< endl;
        // }
    }
    string Notebook::read(int page, int row, int col, Direction dir, int numOfChars)
    {
        const int minChar = 32;
        const int maxChar = 125;
        const int maxLen = 99;
        if (page < 0 || row < 0 || col < 0 || numOfChars < 0)
        {
            throw runtime_error("negtive");
        }
        if (col + numOfChars > maxLen + 1 && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't read more then 100 charcters");
        }
        if (col > maxLen)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        string outPut;
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < numOfChars; i++)
            {
                if (minChar <= nb[page][row][col + i] && nb[page][row][col + i] <= maxChar + 1)
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
                if (minChar <= nb[page][row + i][col] && nb[page][row + i][col] <= maxChar + 1 )
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
        const int minChar = 32;
        const int maxChar = 125;
        const int maxLen = 99;
        if (page < 0 || row < 0 || col < 0 || numOfChars < 0)
        {
            throw runtime_error("negtive");
        }
        if (col + numOfChars > maxLen + 1 && dir == Direction::Horizontal)
        {
            throw runtime_error("you can't erase more then 100 charcters");
        }
        if (col > maxLen)
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
        if (page < 0)
        {
            throw runtime_error("negtive");
        }
        cout << nb[page][0][0] << "\nshow func\n";
    }
}
