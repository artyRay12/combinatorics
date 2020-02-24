
#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <ostream>
#include <algorithm>
#include <iterator>
#include <cstddef>

using namespace std;
using namespace boost;







int main()
{
    vector<size_t> v = { 7, 1, 12, 5, 9, 20, 15 };
    timer t;
    t.restart();

    sort(v.begin(), v.end());

    do
    {
        copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    double duration = t.elapsed();
    cout << duration << endl;

    return 0;
}
