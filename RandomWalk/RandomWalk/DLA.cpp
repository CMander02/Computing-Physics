#include"Particle.h"
#include"Vector.h"
#include<vector>
#include<utility>
#include<algorithm>
#include<GL/glut.h>
#include"Animation.h"
#include<fstream>
#include<cmath>
#include"RandomJS.h"
using randomjs::RandomSchrage;
#define MAPSIZE 1024

using namespace std;

struct DataBlock
{
	CPUAnimBitmap *bitmap;
};

void cleanup();

int calc_offset(int x, int y);

vector<Particle<2>> vec(1, Particle<2>({ 0,0 }));
vector<Particle<2>>::iterator iter = vec.begin();
Particle<2> now({ 1,1 });
const int particles_per_frame = 50;
ofstream out("C:\\Users\\10069\\Desktop\\fractal.txt");

void generate_frame(DataBlock *d, int ticks)
{
	CPUAnimBitmap *map = d->bitmap;
	int i = 0;

	while (i < particles_per_frame)
	{
		Particle<2> temp = now;
		if (find(vec.begin(), vec.end(), now.move()) != vec.end()&&RandomSchrage()<1.1)//�������𤸽����������ϵ��
		{
			vec.push_back(temp);

			//������Զ��Ĵ���Ҫ������������ܣ�
			iter = max_element(vec.begin(), vec.end(),
				[](Particle<2> &a, Particle<2> &b)->bool {return a.get_position().length() < b.get_position().length(); });//�ҵ���ԭ����Զ�����ӵ�λ��
			now = RandomVectorOnGridBall<2>(iter->get_position().length());

			double circle_size = iter->get_position().length()*iter->get_position().length();

			out << vec.size() << ' ' << circle_size <<' '<< log(vec.size()) / log((double)circle_size) << endl;
			cout << vec.size() << ' ' << circle_size << ' ' << log(vec.size()) / log((double)circle_size) << endl;

			i++;
		}

		if (now.get_position().length() > (iter->get_position().length() + 15))//�����̫Զ�˾�����
		{
			now = RandomVectorOnGridBall<2>(iter->get_position().length());
		}
	}
	auto ptr = map->get_ptr();
	for (int i = 0; i < vec.size(); i++)
	{
		int offset = calc_offset(vec[i].get_position()[0], vec[i].get_position()[1]);
		ptr[offset * 4 + 0] = 255;
		ptr[offset * 4 + 1] = 255;
		ptr[offset * 4 + 2] = 255;
		ptr[offset * 4 + 3] = 1;
	}
}

int main()
{
	DataBlock data;
	CPUAnimBitmap bitmap(MAPSIZE, MAPSIZE, &data);
	data.bitmap = &bitmap;
	bitmap.anim_and_exit((void(*)(void*, int))generate_frame, (void(*)(void*))cleanup);
	system("pause");
}