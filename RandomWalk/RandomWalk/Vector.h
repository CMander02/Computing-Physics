#pragma once
#include<initializer_list>
#include<cmath>
#include"RandomJS.h"
#include<iostream>
using namespace randomjs;

using std::initializer_list;
using std::ostream;
using std::cout;

template<unsigned dimension>
class Vector;

template<unsigned dimension>
Vector<dimension> operator*(const Vector<dimension>&r, double lambda);
template<unsigned dimension>
Vector<dimension> operator+(const Vector<dimension>&l, const Vector<dimension>&r);
template<unsigned dimension>
Vector<dimension> operator-(const Vector<dimension>&l, const Vector<dimension>&r);
template<unsigned dimension>
Vector<dimension> operator/(const Vector<dimension>&r, double lambda);
template<unsigned dimension>
bool operator==(const Vector<dimension>&l, const Vector<dimension>&r);


template<unsigned dimension>
class Vector
{
	friend void swap(Vector<dimension>&l, Vector<dimension>&r)//交换并赋值的写法，保证自赋值安全，同时按版本区分拷贝和移动构造函数
	{
		auto p = l.coordinates;
		l.coordinates = r.coordinates;
		r.coordinates = p;
	}

public:

	//拷贝控制
	Vector()
	{
		coordinates = new double[dimension]();
	}
	Vector(initializer_list<double> list)
	{
		coordinates = new double[dimension]();
		for (int i = 0; i < dimension; i++)
		{
			if (i<list.size())
			{
				coordinates[i] = *(list.begin() + i);
			}
			else
			{
				coordinates[i] = 0;
			}
		}
	}

	Vector(const Vector &vec)
	{
		coordinates = new double[dimension];
		for (int i = 0; i < dimension; i++)
		{
			coordinates[i] = vec[i];
		}
	}

	Vector operator= (const Vector& in)
	{
		Vector temp(in);
		swap(*this, in);
		return *this;
	}

	Vector(Vector&& rvec)
	{
		coordinates = rvec.coordinates;
		rvec.coordinates = nullptr;
	}

	Vector operator= (Vector&& in)
	{
		Vector temp(in);
		swap(*this, in);
		return *this;
	}
	
	~Vector()
	{
		delete[] coordinates;
		coordinates = nullptr;
	}
	//拷贝控制结束

	//算符重载
	Vector<dimension>& operator*=(double lambda)
	{
		*this = *this *lambda;
		return *this;
	}
	
	Vector<dimension>& operator+=(const Vector<dimension>&r)
	{
		*this = *this + r;
		return *this;
	}
	
	Vector<dimension>& operator-=(const Vector<dimension>&r)
	{
		*this = *this - r;
		return *this;
	}

	Vector<dimension>& operator/=(double lambda)
	{
		*this = *this / lambda;
		return *this;
	}

	//算符重载结束

	double& operator[](int i)
	{
		return get_cor(i);
	}

	double operator[](int i) const
	{
		return get_cor(i);
	}

	double length() const
	{
		double result = 0;
		for (int i = 0; i < dimension; i++)
		{
			result += coordinates[i] * coordinates[i];
		}
		return sqrt(result);
	}


	void print(ostream &out = cout) const
	{
		for (int i = 0; i < dimension; i++)
		{
			out << coordinates[i] << ' ';
		}
		cout << std::endl;
	}

protected:

	double *coordinates;
	//const版本和非const版本
	double get_cor(int i) const
	{
		try
		{
			if (i > dimension)
			{
				throw std::out_of_range("Try to get a coordinate more than dimension");
			}
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
			return 0;
		}
		return coordinates[i];
	}

	double& get_cor(int i)//非const版本返回引用，以改变值
	{
		try
		{
			if (i > dimension)
			{
				throw std::out_of_range("Try to get a coordinate more than dimension");
			}
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << e.what() << std::endl;
		}
		return coordinates[i];
	}

};



//将二元运算符写在外面以备可能的类型转换
template<unsigned dimension>
double distance(const Vector<dimension>&l, const Vector<dimension>&r)
{
	return (l - r).length();
}

template<unsigned dimension>
Vector<dimension> operator+(const Vector<dimension>&l, const Vector<dimension>&r)
{
	Vector<dimension> result;

	for (int i = 0; i < dimension; i++)
	{
		result[i] = l[i] + r[i];
	}

	return result;
}

template<unsigned dimension>
Vector<dimension> operator-(const Vector<dimension>&r)
{
	Vector<dimension> result;
	for (int i = 0; i < dimension; i++)
	{
		result[i] = -r[i];
	}
	return result;
}

template<unsigned dimension>
Vector<dimension> operator-(const Vector<dimension>&l,const Vector<dimension>&r)
{
	return l + (-r);
}

template<unsigned dimension>
Vector<dimension> operator*(double lambda,const Vector<dimension>&r)
{
	Vector<dimension> result;

	for (int i = 0; i < dimension; i++)
	{
		result[i] = lambda * r[i];
	}

	return result;
}

template<unsigned dimension>
Vector<dimension> operator*(const Vector<dimension>&r,double lambda)
{
	return lambda * r;
}

template<unsigned dimension>
Vector<dimension> operator/(const Vector<dimension>&r, double lambda)
{
	return (1.0 / lambda) * r;
}

template<unsigned dimension>
inline bool operator==(const Vector<dimension>& l, const Vector<dimension>& r)
{
	for (int i = 0; i < dimension; i++)
	{
		if (l[i]!=r[i])
		{
			return false;
		}
	}
	return true;
}

template<unsigned dimension>
Vector<dimension> operator*(const Vector<dimension>&l, const Vector<dimension>&r)
{
	return l + (-r);
}

template<unsigned dimension>
double operator*(const Vector<dimension>&l, const Vector<dimension>&r)
{
	double result = 0;
	for (int i = 0; i < dimension; i++)
	{
		result += l[i] + r[i];
	}
	return result;
}


//extern Vector<3> cross(const Vector<3>&l, const Vector<3>&r)
//{
//	return Vector<3>({ l[1] * r[2] - l[2] * r[1], l[2] * r[3] - l[3] * r[2], l[3] * r[1] - l[1] * r[3] });
//}

template<unsigned dim>
Vector<dim> RandomVectorOnBall(double length = 1)
{
	Vector<dim> temp;
	for (int i = 0; i < dim; i++)
	{
		temp[i] = RandomGauss();
	}
	temp /= temp.length();
	return temp;
}