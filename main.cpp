#include "PmergeMe.hpp"

void checkDigit(char **str)
{
    int i = 1; 
    while(str[i])
    {
        int j = 0;
        while(str[i][j])
        {
            if(!isdigit(str[i][j]))
            {
                throw std::invalid_argument("Bad input");
            }            
            j++;
        }
        i++;
    }
}

int main(int c, char **v) 
{
    if (c > 2)
    {
        // std::vector<int>A;
        Container<int> cont;
        for (int i = 1; i < c; i++)
        {
            checkDigit(v);
            int a = atoi(v[i]);
            if(a < 0)
            {
                throw std::invalid_argument("error");
            }
            A.push_back(a);
        }
        std::cout << "cont.size() = " << cont.size() << "\n";
        sort(cont, 0, cont.size() - 1);
    }
    else
    {
        std::cout << "error argument qanak\n";
    }
    return 0;
}