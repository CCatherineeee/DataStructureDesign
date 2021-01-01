#include<iostream>
#include"DEFINE.h"
#include"ALGraph.h"
using namespace std;

Status ManageTopo(ALGraph& G);

int main()
{
	ALGraph G;
	G.InitALGraphInfo();
	ManageTopo(G);
	return 0;
}
