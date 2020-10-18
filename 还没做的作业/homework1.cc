/*
@灰烬 两个问题：
*1. 现有的 accumulate 与 right_fold 的实现类似，为什么要叫它“右折叠”？请修改 right_fold_aux 函数佐证你的观点。
2. 参考 right_fold_aux 的实现，完成 left_fold_aux 的实现。
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