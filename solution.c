#include <stdio.h>
#include<iostream>
#include<cstdlib>
#define ABS(a) (a>0?a:(-1*a));
using namespace std;
struct stack
{
public:
	int n;
	int* astr=NULL;
	int top1 = -1;
	int top2 ;
};
stack* stacd = new stack;
void pushin2(int val)
{
	int n = stacd->n;
	int y = stacd->top2;
	if (y <=stacd->top1)
		cout << "OVERFLOW";
	else
	{
		stacd->top2 -= 1;
		y = stacd->top2;
		stacd->astr[y] = val;
		
	}
}
void pushin1(int val)
{
	int y = stacd->top1;
	if (y >=stacd->top2 )
		cout << "OVERFLOW";
	else
	{
		stacd->top1 += 1;
		y = stacd->top1;
		stacd->astr[y] = val;
	}
}
void popin1()
{
	int n = stacd->n;
	int y = stacd->top1;
	if (y < 0)
		cout << "UNDERFLOW";
	else
	{
		stacd->astr[y] = 0;
		stacd->top1 -= 1;
	}
}
void popin2()
{
	int n = stacd->n;
	int y = stacd->top2;
	if (y > n - 1)
		cout << "UNDERFLOW";
	else
	{
		stacd->astr[y] = 0;
		stacd->top2 += 1;
	}
}
int modeh(int* modefor, int k)
{
	int max = 0; int mode = 0; int c;
	int j;
	for (int i = 0; i < k-1; )
	{
		j = i + 1;
		c = 1;
		while (modefor[i] == modefor[j])
		{
			j++;
			c++;
		}
		
		if (c > max)
		{
			max = c;
			mode = modefor[i];
		}
		i = j;
	}
	return mode;
}
int sortl(int* a,int n)
{
		int i, j, min, temp;
		for (i = 0; i < n - 1; i++) {
			min = i;
			for (j = i + 1; j < n; j++)
				if (a[j] < a[min])
					min = j;
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
return 0;
}

int main()
{
	int n, m; int i, j;
	cin >> n;
	stacd->n = n;
	int c = 0;
	cin >> m;
	int** arr = (int**)malloc(sizeof(int) * m);
	stacd->n = n;
	stacd->top2 = n ;
	stacd->astr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		(stacd->astr[i]) = 0;
	for (int y = 0; y < m; y++)
		arr[y] = (int*)malloc(sizeof(int) * 3);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
		if (arr[i][0] == 1)
		{
			c++;
			if (arr[i][1] == 1)
			{
				pushin1(arr[i][2]);
			}
			else
				pushin2(arr[i][2]);
		}
		else
		{
			if (arr[i][1] == 1)
				popin1();
			else
				popin2();

		}
	}
	int* actualarray = (int*)malloc(sizeof(int) * c);
	int k = 0; int sum = 0;
	for (i = 0; i < m; i++)
	{
		if (arr[i][0] == 1)
		{
			actualarray[k] = arr[i][2];
			sum = sum + actualarray[k];
			k++;
		}
	}
	sortl(actualarray, k);
	float mean, median, deviation, dev = 0;
	mean = (float)sum / k;
	//median
	if ((k% 2) != 0)
		median = actualarray[(k ) / 2];
	else
		median =( actualarray[k / 2] + actualarray[k / 2-1])/2;
	//deviation
	float y;
	for (i = 0; i < k; i++)
	{
		y = mean - actualarray[i];
		dev = dev + (y > 0?y:-1*y);
	}
	deviation = (float)dev / k;
	int modex;
	modex = modeh(actualarray, k);
	cout <<"  "<< median <<"    " << modex << "    ";
	cout << "\n";
	//stack1
	for (i = 0; i <= stacd->top1; i++)
		cout << stacd->astr[i] << "  ";
	//stack2
	cout << endl;
	for (i = n-1; i >= stacd->top2; i--)
		cout << stacd->astr[i] << "   ";

}
