#include <iostream>
#include <fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void printarray(char A[500], int x) {
	for (int i = 0; true; i++)
	{
		cout << A[i];
		if (A[i] == '.')
			break;
	}
}
int k1 = 0;
int k2 = 0;
int k3 = 0;
int k4 = 0;
int k5 = 0;
int k6 = 0;
int k7 = 0;
int k8 = 0;
int l1 = 0, l2 = 0, l3 = 0, l4 = 0, o1 = 0, o2 = 0, o3 = 0, o4 = 0;
int hvrow = 0, hvcolmn = 0;
int r[15] = {};
int c[15] = {};

void fwd(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0;
	while (b[k1] != ',' && b[k1] != '.')
	{
		size++;	
		k1++;
	}
	z = k1 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			y = j;
			count = 0;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				j++;
			}
			if (count == size)
			{
				r[i]++;
				l1++;
				int w = y;
				while (w < j)
				{
					c[w]++;
					clr[i][w]++;
					w++;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				j = y;
				z = k1 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k1] != '.' && b[k1] == ',') k1++;
}

void rvrs(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0;
	while (b[k2] != ',' && b[k2] != '.')
	{
		size++;
		k2++;
	}
	z = k2 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 14; j >= 0; j--)
		{
			y = j;
			count = 0;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				j--;
			}
			if (count == size)
			{
				r[i]++;
				l2++;
				int w = y;
				while (w > j)
				{
					c[w]++;
					clr[i][w]++;
					w--;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				j = y;
				z = k2 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k2] != '.' && b[k2] == ',') k2++;
}

void dwn(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0;
	while (b[k4] != ',' && b[k4] != '.')
	{
		size++;
		k4++;
	}
	z = k4 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			count = 0;
			y = i;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i++;
			}
			if (count == size)
			{
				c[j]++;
				l3++;
				int w = y;
				while (w < i)
				{
					r[w]++;
					clr[w][j]++;
					w++;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = y;
				z = k4 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k4] != '.' && b[k4] == ',') k4++;
}

void up(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0;
	while (b[k3] != ',' && b[k3] != '.')
	{
		size++;
		k3++;
	}
	z = k3 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			y = i;
			count = 0;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i--;
			}
			if (count == size)
			{
				c[j]++;
				l4++;
				int w = y;
				while (w > i)
				{
					r[w]++;
					clr[w][j]++;
					w--;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = y;
				z = k3 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k3] != '.' && b[k3] == ',') k3++;
}

void trace1(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0, x = 0;
	while (b[k5] != ',' && b[k5] != '.')
	{
		size++;
		k5++;
	}
	z = k5 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			count = 0;
			x = i;
			y = j;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i++;
				j++;
			}
			if (count == size)
			{
				o1++;
				int w = x;
				int w1 = y;
				while (w < i)
				{
					r[w]++;
					c[w1]++;
					clr[w][w1]++;
					w++;
					w1++;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = x;
				j = y;
				
				z = k5 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k5] != '.' && b[k5] == ',') k5++;
}

void trace3(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0, x = 0;
	while (b[k7] != ',' && b[k7] != '.')
	{
		size++;
		k7++;
	}
	z = k7 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 14; j >= 0; j--)
		{
			count = 0;
			x = i;
			y = j;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i++;
				j--;
			}
			if (count == size)
			{
				o3++;
				int w = x;
				int w1 = y;
				while (w < i && w1 > j)
				{
					r[w]++;
					c[w1]++;
					clr[w][w1]++;
					w++;
					w1--;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = x;
				j = y;
				z = k7 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k7] != '.' && b[k7] == ',') k7++;
}


void trace2(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0, x = 0;
	while (b[k6] != ',' && b[k6] != '.')
	{
		size++;
		k6++;
	}
	z = k6 - size;
	for (int i = 14; i >= 0; i--)
	{
		for (int j = 14; j >= 0; j--)
		{
			count = 0;
			x = i;
			y = j;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i--;
				j--;
			}
			if (count == size)
			{
				o2++;
				int w = x;
				int w1 = y;
				while (w > i)
				{
					r[w]++;
					c[w1]++;
					clr[w][w1]++;
					w--;
					w1--;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = x;
				j = y;
				
				z = k6 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k6] != '.' && b[k6] == ',') k6++;
}


void trace4(char A[15][15], char b[500], int clr[15][15])
{
	bool brk = false;
	int  z = 0, size = 0, count = 0;
	int y = 0, x = 0;
	while (b[k8] != ',' && b[k8] != '.')
	{
		size++;
		k8++;
	}
	z = k8 - size;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			count = 0;
			x = i;
			y = j;
			while (A[i][j] == b[z])
			{
				count++;
				z++;
				i--;
				j++;
			}
			if (count == size)
			{
				o4++;
				int w = x;
				int w1 = y;
				while (w > i && w1 < j)
				{
					c[w1]++;
					r[w]++;
					clr[w][w1]++;
					w--;
					w1++;
				}
				brk = true;
				break;
			}
			if (A[i][j] != b[z])
			{
				i = x;
				j = y;
				
				z = k8 - size;
			}
		}
		if (brk == true)
		{
			break;
		}
	}
	if (b[k8] != '.' && b[k8] == ',') k8++;
}


void clor(char grid[15][15], int clr[15][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (clr[i][j] == 0)
			{
				cout << "\033[1;0m" << grid[i][j] << " ";
			}
			if (clr[i][j] == 1)
			{
				cout << "\033[1;33m" << grid[i][j] << " ";
			}
			if (clr[i][j] == 2)
			{
				cout << "\033[1;34m" << grid[i][j] << " ";
			}
			if (clr[i][j] >= 3)
			{
				cout << "\033[1;31m" << grid[i][j] << " ";
			}
			cout << "\033[1;0m" ;
		}
		cout << endl;
	}
}
void print(char A[15][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++) 
		{
			cout << A[i][j] << "  ";
		}
		cout << '\n';
	}
}
int main()
{
	ifstream file("teleword.txt");
	char Grid[15][15], arr[500];
	int sword = 99, lword = 0, avgword = 0, sctr = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			file >> Grid[i][j];
		}
	}
	for (int i = 0; i < 500; i++)
	{
		char temp;
		file >> temp;
		if (temp > 96 && temp < 123)
		{
			temp -= 32;
		}

		arr[i] = temp;
	}
	file.close();
	int colr[15][15] = {};
	int x = 0;
	print(Grid);
	cout << endl;
	printarray(arr, x);
	int m = 0;
	for (int i = 0; true; i++)
	{
		if (arr[i] == ',') m++;
		if (arr[i] == '.') { m++;break; }
	}
	char choice;
	cout << endl;
	cout << "Press S to solve at once" << endl;
	cout << "Press T to solve step bt step" << endl;
	cout << "Press X for statistics" << endl;
	cin >> choice;

	if (choice == 'S' || choice == 's')
	{
		for (int i = 0; i < m; i++)
		{
			system("cls");
			fwd(Grid, arr, colr);
			rvrs(Grid, arr, colr);
			up(Grid, arr, colr);
			dwn(Grid, arr, colr);
			trace1(Grid, arr, colr);
			trace2(Grid, arr, colr);
			trace3(Grid, arr, colr);
			trace4(Grid, arr, colr);
		}
		clor(Grid, colr);
		cout << "Teleword : ";
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (colr[i][j] == 0)
				{
					cout << Grid[i][j];
				}
			}
		}
		cout << endl;
	
	}
	else if (choice == 'T' || choice == 't')
	{
		for (int i = 0; i < m; i++)
		{
			
			system("cls");
			fwd(Grid, arr, colr);
			rvrs(Grid, arr, colr);
			up(Grid, arr, colr);
			dwn(Grid, arr, colr);
			trace1(Grid, arr, colr);
			trace2(Grid, arr, colr);
			trace3(Grid, arr, colr);
			trace4(Grid, arr, colr);
			clor(Grid, colr);
			for (int j = 0;arr[j] != '.';j++)
			      cout << arr[j];
			cout << endl;
			system("pause");
		}
		cout << "Teleword : ";
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				if (colr[i][j] == 0)
				{
					cout << Grid[i][j];
				}
			}
		}
		cout << endl;
	}
	else if (choice == 'X' || choice == 'x')
	{
		system("cls");
		auto start = high_resolution_clock::now();
		for (int i = 0; i < m; i++)
		{
			fwd(Grid, arr, colr);
			rvrs(Grid, arr, colr);
			dwn(Grid, arr, colr);
			up(Grid, arr, colr);
			trace1(Grid, arr, colr);
			trace3(Grid, arr, colr);
			trace2(Grid, arr, colr);
			trace4(Grid, arr, colr);
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		bool pti = true;
		clor(Grid, colr);
		cout << "Teleword : ";
		bool v = true;
		for (int i = 0; i < 15; i++)
		{
			v = true;
			for (int j = 0; j < 15; j++)
			{
				if (colr[i][j] == 0)
				{
					cout << Grid[i][j];
					if (v)
					{
						v = false;
						sctr++;
					}
				}
			}
		}
		cout << endl;
		int tmp = 0;
		for (int i = 0; true; i++)
		{
			if (arr[i] != ',' && arr[i] != '.')tmp++;
			else
			{
				if (tmp > lword)lword = tmp;
				if (tmp < sword)sword = tmp;
				avgword = avgword + tmp;
				tmp = 0;
			}

			if (arr[i] == '.')break;

		}

		for (int a = 0; a < 15; a++)
		{
			if (r[a]>hvrow)
			{
				hvrow = a;
			}
			if (c[a]>hvcolmn)
			{
				hvcolmn = a;
			}
		}

		cout << "Time taken : " << duration.count() << " microseconds" << endl;
		cout << "Longest word length : " << lword << endl;
		cout << "Shortest word length : " << sword << endl;
		cout << "Average word length : " << avgword / m << endl;
		cout << "Word distribution : " << "Horizontal " << l1+l2<<"("<<l1<<" "<<l2<<")" << "Vertical " << l3 + l4 << "(" << l3<< " " << l4 << ")" << "Diagonal " << o1 + o2+o3+o4 << "(" << o1+o3 << " " << o2+o4 << ")" << endl;
		cout << "Teleword Scatter : " << sctr << endl;
		cout << "Heaviest row : " <<  hvrow <<endl;
		cout << "Heaviest column : " <<hvcolmn<< endl;
	}
	return 0;
}
