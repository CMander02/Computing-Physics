#ifndef RANDOMNUMBERJS //DB is short for my name Jerry Shen
#define RANDOMNUMBERJS
namespace randomjs //��ֹ�պ�����������ͻ
{
	double RandomSchrage();
	double RandomFibonacci();
	double CosRandom();//�Ƚ����������Ȼ�����Cos�任�Ľ��
	double RandomGauss(double mu = 0, double sigma = 1);
	double RandomExp();
	double RandomLorentz();
	double RandomCos();
	void SetSeed(int seed);
}


#endif // !RANDOMJS


