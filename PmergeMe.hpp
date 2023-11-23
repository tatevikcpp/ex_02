#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

const int K = 5;

template <typename T>
class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe(const std::vector<int> &obj);
    ~PmergeMe();
    // PmergeMe& operator=(const  PmergeMe& obj);
    // void MergeSort(std::vector<T> &cont, int start, int mid, int end);
    // void MergeInsert(std::vector<T> &cont, int start, int end);
    void print_vec();

private:
    std::vector<T> _vec;
    std::list<T> _list;
};

template <typename T>
PmergeMe<T>::PmergeMe()
{
}

template <typename T>
PmergeMe<T>::PmergeMe(const std::vector<int> &cont) /* : _cont(cont) */
{
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &obj)
{
    this->_cont = obj._cont;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

// template <typename T>
// PmergeMe& PmergeMe<T>::operator=(const  PmergeMe& obj)
// {
//     if (this != &obj)
//     {
//         this->_cont = obj._cont;
//     }
//     return(*this);
// }

template <typename T>
void PmergeMe<T>::print_vec()
{
    // for(std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
    // {
    //     std::cout << *it << " " ;
    // }
    // std::cout << std::endl;
}

template <typename T>
void InsertionSort(T &A, int p, int q)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    for (int i = p; i < q; i++)
    {
        int tmp = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tmp)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
    }
}

template <typename T>
void Merge(T &m_vec, int start, int mid, int end)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int i = start;
    int j = mid + 1;

    std::vector<int> tmp;

    while (i <= mid && j <= end)
    {
        if (m_vec[i] <= m_vec[j])
        {
            tmp.push_back(m_vec[i]);
            ++i;
        }
        else
        {
            tmp.push_back(m_vec[j]);
            ++j;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(m_vec[i]);
        ++i;
    }
    while (j <= end)
    {
        // std::cout << "m_vec[j] = " << m_vec[j] << "\n";
        tmp.push_back(m_vec[j]);
        ++j;
    }

    for (int i = start; i <= end; ++i)
    {
        m_vec[i] = tmp[i - start];
    }
}

template <typename T>
void MergeInsert(T &A, int p, int r)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (r - p > K)
    {
        // int q = (p + r) / 2;
        int q = (r - p) / 2 + p;
        MergeInsert(A, p, q);
        MergeInsert(A, q + 1, r);
        Merge(A, p, q, r);
    }
    else
        InsertionSort(A, p, r);
}