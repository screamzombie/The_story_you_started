/*
@�ҽ� �������⣺
*1. ���е� accumulate �� right_fold ��ʵ�����ƣ�ΪʲôҪ���������۵��������޸� right_fold_aux ������֤��Ĺ۵㡣
2. �ο� right_fold_aux ��ʵ�֣���� left_fold_aux ��ʵ�֡�
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <functional>
#include <utility>

template<typename ForwardIt, typename T, typename Pred>
T right_fold_aux(ForwardIt first, ForwardIt last, T init, Pred pred)
{
    if (first == last) return init;
    return pred(*first, ::right_fold_aux(first + 1, last, init, pred));
}

template<typename Container, typename T, typename Pred>
T right_fold(Container& container, T init, Pred pred)
{
    return ::right_fold_aux(std::begin(container), std::end(container), init, pred);
}

template<typename ForwardIt, typename T, typename Pred>
T left_fold_aux(ForwardIt first, ForwardIt last, T init, Pred pred)
{
    // Your code here.
    return {};
}

template<typename Container, typename T, typename Pred>
T left_fold(Container& container, T init, Pred pred)
{
    return ::left_fold_aux(std::begin(container), std::end(container), init, pred);
}

int main()
{
    std::vector<int> ivec {1, 2, 3, 4, 5};
    std::cout << "value of right_fold: "
              << ::right_fold(ivec, 0, std::plus<int>())
              << std::endl;
    std::cout << "value of left_fold: "
              << ::left_fold(ivec, 0, std::plus<int>())
              << std::endl;
}