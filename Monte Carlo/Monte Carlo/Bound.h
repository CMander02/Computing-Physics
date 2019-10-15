#ifndef BOUND
#define BOUND

struct Bound
{
	Bound(double l, double u) :lower(l), upper(u) {}
	double upper;
	double lower;
};
#endif // !BOUND