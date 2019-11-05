#include<iostream>
#include"Particle.h"
#include<fstream>
#include<algorithm>
#include"Rod.h"
using namespace std;

#define N 50000000

const unsigned dim =12;

Particle<dim> a[N];

bool at_zero_point(Particle<dim> &a)
{
	return a.get_position() == Particle<dim>().get_position();
}

int main()
{

	ofstream out("C:\\Users\\10069\\Desktop\\dim=12.txt");
	out << '{';
	for (int i = 0; true; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[j].move(ON_GRID);
		}
		if (i % 2 != 0)
		{
			auto temp = count_if(begin(a), end(a), at_zero_point);
			cout << temp << endl;
			out << temp << ',';
			if (temp<20)
			{
				break;
			}
		}
	}
	out.close();
	system("pause");
}