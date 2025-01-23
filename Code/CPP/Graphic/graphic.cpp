#include <iostream>

// 图的数据结构表示方式
// 邻接矩阵实现
// 定义一个NxN的矩阵,

// 邻接链表实现
//
// 计算入度 计算出度
// 遍历图
// 向图中插入边
// 向图中插入节点
// 有向图
// 无向图

#define MAX_VEX 6
typedef struct
{
	char vexs[MAX_VEX];		   // 顶点表
	int arc[MAX_VEX][MAX_VEX]; // 邻接矩阵
} MGraph;

// 初始化图
void Graph_Init(MGraph *G)
{
	for (int i = 0; i < MAX_VEX; i++)
	{

		for (int j = 0; j < MAX_VEX; j++)
		{

			G->arc[i][j] = 0;
		}
	}
}

// 计算图中一个节点的度
int Graph_D(MGraph *G, int vexIndex)
{
	int d = 0;
	for (int i = 0; i < MAX_VEX; i++)
	{
		if (G->arc[vexIndex][i] != 0)
		{
			d = d + 1;
		}
	}
	return d;
}

int main()
{

	G.arc[0][1] = 1;
	G.arc[0][1] = 1;

	return 0;
}
