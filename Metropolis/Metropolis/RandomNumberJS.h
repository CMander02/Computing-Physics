#ifndef RANDOMNUMBERJS //DB is short for my name Jerry Shen
#define RANDOMNUMBERJS
namespace randomjs //防止日后调库的命名冲突
{
	double RandomSchrage();
	double RandomFibonacci();
	double CosRandom();//先进行随机数，然后进行Cos变换的结果，这样一种实现的方式较求Cos来说更加快速
	double RandomGauss(double mu = 0, double sigma = 1);
	double RandomExp();
	double RandomLorentz();
	double RandomCos();
	void SetSeed(int seed);
}


#endif // !RANDOMJS


