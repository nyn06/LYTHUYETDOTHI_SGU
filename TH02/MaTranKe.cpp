#include <iostream>
#include <fstream>
using namespace std;

#define MAXN 1000
int a[MAXN][MAXN];
int deg[MAXN];
int n;

void Nhap() {
	ifstream fi("MaTranKe.inp");
	fi >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			fi >> a[i][j];
		}
	fi.close();
}

void Xuly() {
	for (int i = 0; i < n; i++)
	{
		deg[i] = 0;
		for (int j = 0; j < n; j++) {
			deg[i] += a[i][j];
		}
		// Neu a[i][j] = 1 thi cong them 1 nua
		if (a[i][i] == 1) deg[i]++;
	}
}

void Xuat() {
	ofstream fo("MaTranKe.out");
	fo << n << "\n";
	for (int i = 0; i < n; i++) {
		fo << deg[i] << "\n";
	}
	fo.close();
}
int main()
{
	Nhap();
	Xuly();
	Xuat();
	return 0;
}
