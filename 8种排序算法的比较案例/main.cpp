#include<iostream>
#include<ctime>
#include"Sort.h"
using namespace std;



//控制函数
void Manage(int op, double& SortTime,long long& SwapTime, long long*& Data,int n)
{
	long long* Data_copy = new long long[n];
	for (int i = 0; i < n; i++)
		Data_copy[i] = Data[i];
	clock_t start = clock();
	switch (op)
	{
	case 1:
		BubbleSort(SwapTime,Data_copy,n);
		break;
	case 2:
		SelectSort(SwapTime, Data_copy, n);
		break;
	case 3:
		InsertSort(SwapTime, Data_copy, n);
		break;
	case 4:
		ShellSort(SwapTime, Data_copy, n);
		break;
	case 5:
		QuickSort(0,n-1, Data_copy, n, SwapTime);
		break;
	case 6:
		HeapSort(SwapTime, Data_copy, n);
		break;
	case 7:
		MergeSort(Data,Data_copy,0,n-1, SwapTime);
		break;
	case 8:
		RadixSort(SwapTime, Data_copy, n);
		break;
	default:
		break;
	}
	clock_t end = clock();
	SortTime = (double)(end - start) / CLOCKS_PER_SEC;

}
int main()
{
	cout << "**            排序算法比较             **" << endl;
	cout << "========================================" << endl;
	cout << "**            1---冒泡排序             **" << endl;
	cout << "**            2---选择排序             **" << endl;
	cout << "**            3---直接插入排序         **" << endl;
	cout << "**            4---希尔排序             **" << endl;
	cout << "**            5---快速排序             **" << endl;
	cout << "**            6---堆排序               **" << endl;
	cout << "**            7---归并排序             **" << endl;
	cout << "**            8---基数排序             **" << endl;
	cout << "**            9---退出程序             **" << endl;
	cout << "========================================" << endl;

	cout << "请输入要产生的随机数的个数：";
	int n;
	cin >> n;
	while (cin.fail()|| n <= 0)
	{
		cout << "应输入正整数,请重新输入" << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "请输入要产生的随机数的个数：";
		cin >> n;
	}
	long long* Data = new long long[n];
	if (!Data)
	{
		cout << "数据表建立失败" << endl;
		exit(-1);
	}
	CreateData(n, Data);
	string SortName[8] = { "冒泡排序","选择排序","直接插入排序","希尔排序","快速排序","堆排序","归并排序","基数排序" };

	while (1)
	{
		cout << "你的选择是：";
		int op;
		cin >> op;
		while (cin.fail() || (op < 1 || op > 9))
		{
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "应输入 1-9的正整数,请重新输入\n" << endl;
			cout << "你的选择是：";
			cin >> op;
		}
		if (op == 9)
		{
			cout << "程序结束\n" << endl;
			break;
		}
		long long SwapTime = 0;
		double SortTime = 0;
		Manage(op, SortTime, SwapTime, Data, n);
		cout << SortName[op - 1]<<  "所用时间:" << SortTime << "s" << endl;
		//归并排序看比较次数
		if (op == 7)
			cout << SortName[op - 1] << "比较次数：" << SwapTime << endl;
		else
			cout << SortName[op - 1] << "交换次数：" << SwapTime << endl;
		cout << endl;
	}
	return 0;
}