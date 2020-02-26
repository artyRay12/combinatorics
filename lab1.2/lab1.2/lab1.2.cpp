#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <boost/timer.hpp>

using namespace std;
using namespace boost;


void printVector(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
			cout << v[i] << "  ";
		else
			cout << v[i] << "   ";
			

	}
	cout << endl;
}




int main()
{
	int N = 5;
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

	t.restart();
	cout << "p: "; printVector(p);
	cout << "r: "; printVector(r);
	cout << "d: "; printVector(d);
	while (m != 1)
	{
		//copy(p.begin() + 1, p.end() - 1, std::ostream_iterator<size_t>(std::cout, " "));
		system("cls");
		cout << "p: "; printVector(p);
		cout << "r: "; printVector(r);
		cout << "d: "; printVector(d);
		system("pause");
		cout << endl;


		m = N;
		while (p[r[m] + d[m]] > m)
		{
			d[m] = -d[m];
			m = m - 1;









		}

		swap(p[r[m]], p[r[m] + d[m]]);
		swap(r[p[r[m]]], r[m]);
	}

	cout << t.elapsed() << std::endl;

	return 0;
}
