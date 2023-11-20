#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

const int K = 5;

namespace Container
{

template <typename T>
class Container
{
    public:
        Container();
        Container(const Container& obj);
        Container& operator=(const Container& obj);
        ~Container();
    private:
        std::vector<T> _vec;
        std::deque<T> _dec;
};

// template<typename T, typename Container>
template <typename Container::Container<int>>
class  PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const  PmergeMe& obj);
        PmergeMe(const Container& obj);
        ~PmergeMe();
        PmergeMe& operator=(const  PmergeMe& obj);
        void InsertionSort(Container<int>& cont, int start, int end);
        void MergeSort(Container<int>& cont, int start, int mid, int end);
        void MergeInsert(Container<int>& cont, int start, int end);
        void print();
    private:
        // Container<T> cont;
        Container _cont;
};
}






// void InsertionSort(std::vector<int>& A, int p, int q)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     for (int i = p; i < q; i++)
//     {
//         int tmp = A[i + 1];
//         int j = i + 1;
//         while (j > p && A[j - 1] > tmp)
//         {
//             A[j] = A[j - 1];
//             j--;
//         }
//         A[j] = tmp;
//     }

//     std::cout << "in Insretionsort\n";
//     for (int i = p; i <= q; ++i)
//     {
//         std::cout << A[i] << " ";
//     }
//     std::cout << std::endl;
// }


// void MergeSort(std::vector<int>& m_vec, int start, int mid, int end)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     int i = start;
//     int j = mid + 1;

//     std::vector<int> tmp;
//     while (i <= mid && j <= end)
//     {
//         if (m_vec[i] <= m_vec[j])
//         {
//             tmp.push_back(m_vec[i]);
//             ++i;
//         }
//         else
//         {
//             tmp.push_back(m_vec[j]);
//             ++j;
//         }
//     }
//     while (i <= mid)
//     {
//         tmp.push_back(m_vec[i]);
//         ++i;
//     }
//     while (j <= end)
//     {
//         std::cout << "m_vec[j] = " << m_vec[j] << "\n";
//         tmp.push_back(m_vec[j]);
//         ++j;
//     }

//     for (int i = start; i <= end; ++i)
//     {
//         m_vec[i] = tmp[i - start];
//     }


//     std::cout << "offff = " << std::endl;
//     for (int i = start; i <= end; ++i)
//     {
//         std::cout << tmp[i] << " ";
//     }
// }

// void MergeInsert(std::vector<int>& A, int p, int r)
// {
//     std::cout << __PRETTY_FUNCTION__ << std::endl;
//     if (r - p > K)
//     {
//         // int q = (p + r) / 2;
//         int q  = (r - p) / 2 + p;
//         sort(A, p, q);
//         sort(A, q + 1, r);
//         merge(A, p, q, r);
//     } 
//     else 
//         insertionSort(A, p, r);
// }