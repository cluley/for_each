#include <iostream>
#include <vector>
#include <random>

#include "mechanism.h"

int main() {
    std::vector<int> v(400, 1729);

    auto print = [](const int& n) { std::cout << n << ' '; };

    std::cout << "before:\t";
    own::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    own::for_each(v.begin(), v.end(), [](int& n) { n += 271; });

    std::cout << "\nafter:\t";
    own::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';

    struct Sum
    {
        void operator()(int n) { sum += n; }
        int sum{ 0 };
    };

    Sum s = own::for_each(v.cbegin(), v.cend(), Sum());
    std::cout << "sum:\t" << s.sum << '\n';

    return 0;
}