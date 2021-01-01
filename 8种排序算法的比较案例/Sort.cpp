#include<iostream>
#include<ctime>
#include"Sort.h"
using namespace std;


// �������ݱ�
void CreateData(int n, long long*& Data)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		Data[i] = rand();
	//for (int i = 0; i < n; i++)
		//cout << Data[i] << ' ';
	//cout << endl;
}
void show(int n, long long*& Data)
{
	for (int i = 0; i < n; i++)
		cout << Data[i] << " ";
}

//������������
void Swap(long long& i, long long& j)
{
	long long temp = i;
	i = j;
	j = temp;
}

//ð������
void BubbleSort(long long& SwapTime, long long*& Data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (Data[j] > Data[j + 1])
			{
				Swap(Data[j], Data[j + 1]);
				SwapTime++;
			}
		}
	}
}
//ѡ������
void SelectSort(long long& SwapTime, long long*& Data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minpos = i;
		//Ѱ����Сֵ
		for (int j = minpos + 1; j < n; j++)
		{
			if (Data[j] < Data[minpos])
				minpos = j;
		}
		if (minpos != i)
		{
			Swap(Data[i], Data[minpos]);
			SwapTime++;
		}
	}
}
//ֱ�Ӳ�������
void InsertSort(long long& SwapTime, long long*& Data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (Data[i] > Data[i + 1])
		{
			long long tmp = Data[i + 1];
			int j = i;
			while (j >= 0 && Data[j] > tmp)
			{
				Data[j + 1] = Data[j];
				SwapTime++;
				j--;
			}
			Data[j + 1] = tmp;
		}
	}
}
//ϣ������
void ShellSort(long long& SwapTime, long long*& Data, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
			if (Data[i] < Data[i - gap])
			{
				for (int j = i - gap; j >= 0 && Data[j] > Data[j + gap]; j -= gap)
				{
					Swap(Data[j], Data[j + gap]);
					SwapTime++;
				}

			}
	}
}
//��������
int Partition(int low, int high, long long*& Data, int n, long long& SwapTime)
{
	int pivotpos = low;
	long long pivot = Data[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (Data[i] < pivot)
		{
			pivotpos++;
			if (pivotpos != i)
			{
				Swap(Data[pivotpos], Data[i]);
				SwapTime++;
			}
		}
	}
	Data[low] = Data[pivotpos];
	Data[pivotpos] = pivot;
	SwapTime++;
	return pivotpos;
}
void QuickSort(int low, int high, long long*& Data, int n, long long& SwapTime)
{
	if (low < high)
	{
		int pivotpos = Partition(low, high, Data, n, SwapTime);
		QuickSort(pivotpos + 1, high, Data, n, SwapTime);
		QuickSort(low, pivotpos - 1, Data, n, SwapTime);
	}
}
//������
void ShiftDown(int start, int end, long long SwapTime, long long*& Data)
{
	//����ӽڵ�λ��
	int i = start, j = 2 * i + 1;
	long long temp = Data[i];
	//�Ƿ�������
	while (j <= end)
	{
		//ѡȡ�ӽڵ������нϴ��
		if (j < end && Data[j] < Data[j + 1])
			j++;
		//�������
		if (temp >= Data[j])
			break;
		else
		{
			Swap(Data[i], Data[j]);
			SwapTime++;
			i = j;
			j = 2 * i + 1;
		}
	}
}
void HeapSort(long long SwapTime, long long*& Data, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		ShiftDown(i, n - 1, SwapTime, Data);
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(Data[0], Data[i]);
		SwapTime++;
		ShiftDown(0, i - 1, SwapTime, Data);
	}
}

//�鲢����
void Merge(long long*& L1, long long*& L2, int left, int right, int mid, long long& JudgeTime)
{
	for (int i = left; i <= right; i++)
		L2[i] = L1[i];
	int pos1 = left, pos2 = mid + 1, pos = left;
	while (pos1 <= mid && pos2 <= right)
	{
		if (L2[pos1] < L2[pos2])
			L1[pos++] = L2[pos1++];
		else
			L1[pos++] = L2[pos2++];
		JudgeTime++;
	}
	while (pos1 <= mid)
	{
		L1[pos++] = L2[pos1++];
	}
	while (pos2 <= mid)
	{
		L1[pos++] = L2[pos2++];
	}
}

void MergeSort(long long*& L1, long long*& L2, int left, int right, long long& JudgeTime)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort(L1, L2, left, mid, JudgeTime);
	MergeSort(L1, L2, mid + 1, right, JudgeTime);
	Merge(L1, L2, left, right, mid, JudgeTime);
}

//��������
int GetMaxExp(long long*& Data, int n)
{
	int digit = 1;
	int exp = 10;
	for (int i = 0; i < n; i++)
	{
		while (exp <= Data[i])
		{
			exp *= 10;
			digit++;
		}
	}
	return digit;
}

void RadixSort(long long SwapTime, long long*& Data, int n)
{
	int exp = 1;    // ָ�����������鰴��λ��������ʱ��exp=1����ʮλ��������ʱ��exp=10��...
	int MaxExp = GetMaxExp(Data, n);    // ����a�е����ֵ

	// �Ӹ�λ��ʼ��������a��"ָ��"��������
	for (int i = 1; i <= MaxExp; i++)
	{
		long long* tmp = new long long[n + 1];
		int bucket[10] = { 0 };
		for (int j = 0; j < n; j++)
			bucket[(Data[j] / exp) % 10]++;
		for (int j = 1; j < 10; j++)
			bucket[j] += bucket[j - 1];
		for (int j = 0; j < n; j++)
		{
			tmp[bucket[(Data[j] / exp) % 10] - 1] = Data[j];
			bucket[(Data[j] / exp % 10)]--;
		}
		for (int j = 0; j < n; j++)
			Data[j] = tmp[j];
		exp *= 10;
	}
}