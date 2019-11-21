#include<iostream>
#include"Particle.h"
#include"Vector.h"
#include<GL/glut.h>
using namespace std;
#include"Animation.h"
#define dim 2                            
#define NUM 100000

#define MAPSIZE 1024
Particle<dim> p[NUM];



void cleanup() {}

int calc_offset(int x,int y)
{
	int center = (MAPSIZE + 1)*MAPSIZE / 2;
	if (x<-MAPSIZE / 2 || y<-MAPSIZE / 2 || x>MAPSIZE / 2 || y>MAPSIZE / 2)
	{
		cerr << "Out of bound!" << endl;
		return center;
	}
	
	else
	{
		return center + x + y * MAPSIZE;
	}
}
//
//}
//
//void generate_frame(DataBlock *d, int ticks)
//{
//	
//	CPUAnimBitmap *map = d->bitmap;
//	auto ptr = map->get_ptr();
//	for (int i = 0; i < NUM; i++)
//	{
//		int offset = calc_offset(p[i][0], p[i][1]);
//		ptr[offset * 4 + 0] = 0;
//		ptr[offset * 4 + 1] = 0;
//		ptr[offset * 4 + 2] = 0;
//		ptr[offset * 4 + 3] = 0;
//		p[i].move(ON_GRID);
//	}
//	
//	for (int i = 0; i < NUM; i++)
//	{
//		int offset = calc_offset(p[i][0], p[i][1]);
//
//		int center = calc_offset(0, 0);
//
//		ptr[center * 4 + 0] = 255;
//		ptr[center * 4 + 1] = 0;
//		ptr[center * 4 + 2] = 255;
//		ptr[center * 4 + 3] = 1;
//
//
//		ptr[offset * 4 + 0] = 255;
//		ptr[offset * 4 + 1] = 255;
//		ptr[offset * 4 + 2] = 255;
//		ptr[offset * 4 + 3] = 1;
//	}
//	
//}
//
//void run_show()
//{
//	DataBlock data;
//	CPUAnimBitmap bitmap(MAPSIZE, MAPSIZE, &data);
//	data.bitmap = &bitmap;
//
//	bitmap.anim_and_exit((void(*)(void*, int))generate_frame, (void(*)(void*))cleanup);
//}
