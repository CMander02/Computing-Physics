#include"RandomJS.h"
#include"Vector.h"
#include<fstream>
#include<iostream>

using namespace randomjs;


double density(Vector<2>& position)
{
	double sigmax = 1;
	double sigmay = 4;
	return exp(-(position[0] * position[0] / 2 / sigmax + position[1] * position[1] / 2 / sigmay));
}

int main()
{
	std::ofstream out("C:\\Users\\10069\\Desktop\\result.txt");

	Vector<2> result;
	Vector<2> temp_result;
	out << 1 << ' ';
	result.print(out);
	for (int i = 1; i < 100000; )
	{
		temp_result = result + RandomVectorOnBall<2>();
		double r = density(temp_result) / density(result);
		if (r > 1|| RandomFibonacci() < r)
		{
			i++;
			result = temp_result;
			out << i << ' ';
			result.print(out);
		}
	}

	system("pause");
}