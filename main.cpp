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
        std::vector<int> A;
        PmergeMe<int> obj;
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
        // std::cout << "cont.size() = " << cont.size() << "\n";
        // obj.MergeInsert(A, 0, A.size() - 1);
        obj.MergeSort(A, 0, (A.size() - 1) / 2, A.size() - 1);
        // MergeInsert(A, 0, A.size() - 1);
    }
    else
    {
        std::cout << "error argument qanak\n";
    }
    return 0;
}





















// #include <iostream>
// #include <vector>

// bool sot(int n, int max_price, int min_price)
// {
//     return(n == max_price || n == min_price);
// }
// long countInvestablePeriods(std::vector<int> price, int max_price, int min_price) {
// std::vector <int> vec;
// size_t i = 0;

// while (i < price.size())
// {
//     if ((price[i]>= min_price && price[i] <= max_price) /* && (price.at(i + 1)>= min_price && price.at(i+ 1) <= max_price) */)
//     {
//         vec.push_back(price[i]);
//         // std::cout << "veci = "<< vec[i] << "\n"; 
//     }
//     else
//         break;
//     i++;

// }
// // int l = 0;
// // while(l <= vec.size())
// // {
// //     std::cout << "veci = "<< vec.at(l) << "\n";
// //     l++;
// // }

// std::cout << "veci = "<< vec.at(0) << "\n"; 

// if (vec.empty())
//     return (0);
// // i =0;/
// int j;
// int count = 0;
// int k = 0;
// int flag = 0;
// while (k <= vec.size())
// {
//     j = 0;
//     while (j<=vec.size()) {
//         if (sot(vec[j], max_price, min_price))
//             flag++;
//         if (flag >= 2)
//             count++;
//         j++;
//     }
//     k++;
// }
//     return (count);
// }

// int main()
// {
//     std::vector<int> vec = {5, 4, 5, 3, 3, 1, 5, 3};
//     int count = countInvestablePeriods(vec, 5, 3);
//     std::cout << "count = " << count << "\n";
// }