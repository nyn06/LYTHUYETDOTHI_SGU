#include <iostream>
#include <fstream>
using namespace std;

#define MAXN 1000
int a[MAXN][MAXN];
int inDeg[MAXN], outDeg[MAXN];
int n;

void Nhap() {
	ifstream fi("BacVaoBacRa.inp");
	fi >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fi >> a[i][j];
		}
	}
	fi.close();
}

void XuLy() {
	for (int i = 0; i < n; i++) {
		inDeg[i] = 0;
		outDeg[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				outDeg[i]++; // co canh i -> j thi bac ra cua i tang
				inDeg[j]++; // bac vao cua j tang
			}
		}
	}
}
void Xuat() {
	ofstream fo("BacVaoBacRa.out");
	fo << n << "\n";
	for (int i = 0; i < n; i++) {
		fo << inDeg[i] << " " << outDeg[i] << "\n";
	}
	fo.close();
}
int main()
{
	Nhap();
	XuLy();
	Xuat();
	return 0;
}