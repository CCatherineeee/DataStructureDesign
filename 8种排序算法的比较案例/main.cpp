#include<iostream>
#include<ctime>
#include"Sort.h"
using namespace std;



//���ƺ���
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
	cout << "**            �����㷨�Ƚ�             **" << endl;
	cout << "========================================" << endl;
	cout << "**            1---ð������             **" << endl;
	cout << "**            2---ѡ������             **" << endl;
	cout << "**            3---ֱ�Ӳ�������         **" << endl;
	cout << "**            4---ϣ������             **" << endl;
	cout << "**            5---��������             **" << endl;
	cout << "**            6---������               **" << endl;
	cout << "**            7---�鲢����             **" << endl;
	cout << "**            8---��������             **" << endl;
	cout << "**            9---�˳�����             **" << endl;
	cout << "========================================" << endl;

	cout << "������Ҫ������������ĸ�����";
	int n;
	cin >> n;
	while (cin.fail()|| n <= 0)
	{
		cout << "Ӧ����������,����������" << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "������Ҫ������������ĸ�����";
		cin >> n;
	}
	long long* Data = new long long[n];
	if (!Data)
	{
		cout << "���ݱ���ʧ��" << endl;
		exit(-1);
	}
	CreateData(n, Data);
	string SortName[8] = { "ð������","ѡ������","ֱ�Ӳ�������","ϣ������","��������","������","�鲢����","��������" };

	while (1)
	{
		cout << "���ѡ���ǣ�";
		int op;
		cin >> op;
		while (cin.fail() || (op < 1 || op > 9))
		{
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "Ӧ���� 1-9��������,����������\n" << endl;
			cout << "���ѡ���ǣ�";
			cin >> op;
		}
		if (op == 9)
		{
			cout << "�������\n" << endl;
			break;
		}
		long long SwapTime = 0;
		double SortTime = 0;
		Manage(op, SortTime, SwapTime, Data, n);
		cout << SortName[op - 1]<<  "����ʱ��:" << SortTime << "s" << endl;
		//�鲢���򿴱Ƚϴ���
		if (op == 7)
			cout << SortName[op - 1] << "�Ƚϴ�����" << SwapTime << endl;
		else
			cout << SortName[op - 1] << "����������" << SwapTime << endl;
		cout << endl;
	}
	return 0;
}