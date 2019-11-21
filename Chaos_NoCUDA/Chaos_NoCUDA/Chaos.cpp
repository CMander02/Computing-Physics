#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

#define precision 1E-10;
#define PI 3.14159265358
#define divide 4192
#define saving 1024

#define lambdamax 4192
#define dlambda (lambdamax / divide)

double arr[divide*saving];

void calc(int times = 1000000)
{
	for (int i =999; i < 1001; i++)
	{
		for (int j = 0; j < saving; j++)
		{
			arr[i*saving + (j + 1) % saving] = i*sin(arr[i*saving + j % saving] * PI);
		}
		cout << i << endl;
	}
}

int main()
{


	for (int i = 0; i < divide*saving; i++)
	{
		arr[i] = 100.0;
	}
	calc();

	double result = 0;
	cout << setprecision(9);
	for (int i = 1000 * saving; i < 1001 * saving; i++)
	{
		cout << arr[i] << endl;
	}

	system("pause");

}