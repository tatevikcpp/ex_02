#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

const int K = 5;

PmergeMe::PmergeMe() : _cont(0)
{

}

PmergeMe::PmergeMe(const Container<int>& cont) : _cont(cont)
{

}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
    this->_cont = obj._cont;
}


PmergeMe::~PmergeMe()
{

}

PmergeMe& PmergeMe::operator=(const  PmergeMe& obj)
{
    if (this != &obj)
    {
        this->_cont = obj._cont;
    }
    return(*this);
}

void PmergeMe::print()
{
    //flag is vec or dec 2 and 1
    if (_cont == vec)
        std::cout << "Vector Before  ";
    else if (_cont == dec)
        std::cout << "Deque Before  ";
    else
        throw std::runtime_error ("Bad container ");
    for(Container<int>::iterator it = this->_cont.begin(); it != this->_cont.end(); ++it)
    {
        std::cout << *it << " " ;
    }
    std::cout << std::endl;
}

void InsertionSort(Container<int>& cont, int start, int end)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (int i = start; i < end; i++)
    {
        int tmp = cont[i + 1];
        int j = i + 1;
        while (j > start && cont[j - 1] > tmp)
        {
            cont[j] = cont[j - 1];
            j--;
        }
        cont[j] = tmp;
    }

    std::cout << "in Insretionsort\n";
    for (int i = start; i <= end; ++i)
    {
        std::cout << cont[i] << " ";
    }
    std::cout << std::endl;
}


void MergeSort(Container<int>& cont, int start, int mid, int end)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int i = start;
    int j = mid + 1;

    Container<int> tmp;
    while (i <= mid && j <= end)
    {
        if (cont[i] <= cont[j])
        {
            tmp.push_back(cont[i]);
            ++i;
        }
        else
        {
            tmp.push_back(cont[j]);
            ++j;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(cont[i]);
        ++i;
    }
    while (j <= end)
    {
        std::cout << "cont[j] = " << cont[j] << "\n";
        tmp.push_back(cont[j]);
        ++j;
    }

    for (int i = start; i <= end; ++i)
    {
        cont[i] = tmp[i - start];
    }


    std::cout << "offff = " << std::endl;
    for (int i = start; i <= end; ++i)
    {
        std::cout << tmp[i] << " ";
    }
}

void MergeInsert(Container<int>& cont, int start, int end)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (end - start > K)
    {
        // int q = (start + r) / 2;
        int mid  = (end - start) / 2 + start;
        sort(cont, start, mid);
        sort(cont, mid + 1, end);
        merge(cont, start, mid, end);
    } 
    else 
        insertionSort(cont, start, end);
}
