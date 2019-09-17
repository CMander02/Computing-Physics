///////////////////////////////////////////////////////////////////////
//    随机抽样库                                                      //
//    此库的目标为完成计算物理中所有的随机数相关的内容，包括生成随机数、    //
//    各种抽样算法以及日后可能出现的算法。                               //
//    作者：Jerry_Shen                                                //
//    日期：2019/9/17                                                 //
///////////////////////////////////////////////////////////////////////

#ifndef RANDOMDB //DB is short for my online nickname devine_bird
#define RANDOMDB
namespace randomdb //防止日后调库的命名冲突
{
	double RandomSchrage();
	double RandomFibonacci();
	void SetSeed(int seed);
}


#endif // !RANDOMDB

