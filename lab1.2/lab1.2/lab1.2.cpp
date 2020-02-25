#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <boost/timer.hpp>

using namespace std;
using namespace boost;


void printVector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "   ";

	}
	cout << endl;
}

const int N = 5;

int main()
{
	int m = N + 1;
	boost::timer t;
	vector<int> p(N + 2), r(N + 1);
	vector<int> d(N + 1);

	for (int i = 1; i < r.size(); i++)
	{
		p[i] = r[i] = i;
		d[i] = -1;
	}
	d[1] = 0;
	p[0] = p[N + 1] = m;

	cout << "p: "; printVector(p);
	cout << "r: "; printVector(r);
	cout << "d: "; printVector(d);
	system("pause");



	t.restart();
	while (m != 1)
	{
		copy(p.begin() + 1, p.end() - 1, std::ostream_iterator<size_t>(std::cout, " "));
		cout << std::endl;
		m = N;

		while (p[r[m] + d[m]] > m)
		{
			d[m] = -d[m];
			m = m - 1;
		}

		std::swap(p[r[m]], p[r[m] + d[m]]);
		std::swap(r[p[r[m]]], r[m]);
	}

	cout << t.elapsed() << std::endl;

	return 0;
}
