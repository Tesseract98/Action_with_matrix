#include <iostream>
using namespace std;
// ������� ������ �������
void PrintMatr(int **mas, int m) {
	int i, j;
	for (i = 0; i<m; i++) {
		for (j = 0; j<m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}
// ��������� ������� ��� i-� ������ � j-�� �������
void GetMatr(int **mas, int **p, int i, int j, int m) {
	int ki, kj, di, dj;
	di = 0;
	for (ki = 0; ki<m - 1; ki++) { // �������� ������� ������
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj<m - 1; kj++) { // �������� ������� �������
			if (kj == j) dj = 1;
			p[ki][kj] = mas[ki + di][kj + dj];
		}
	}
}
// ����������� ���������� ������������
double Determinant(int **mas, int m) {
	int i, j, d, k, n;
	int **p;
	p = new int*[m];
	for (i = 0; i<m; i++)
		p[i] = new int[m];
	j = 0; d = 0;
	k = 1; //(-1) � ������� i
	n = m - 1;
	if (m<1) cout << "������������ ��������� ����������!";
	if (m == 1) {
		d = mas[0][0];
		return(d);
	}
	if (m == 2) {
		d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(d);
	}
	if (m>2) {
		for (i = 0; i<m; i++) {
			GetMatr(mas, p, i, 0, m);
			//cout << mas[i][j] << endl;
			//PrintMatr(p, n);
			d = d + k * mas[i][0] * Determinant(p, n);
			k = -k;
		}
	}
	return(d);
}
// �������� �������
int main() {
	setlocale(LC_ALL, "russian");
	int m, i, j;
	double d;
	int **mas;
	cout << "������� ����������� ���������� �������: ";
	cin >> m;
	mas = new int*[m];
	int **chkMass = new int *[m];
	for (i = 0; i<m; i++) {
		mas[i] = new int[m];
		chkMass[i] = new int[m];
		for (j = 0; j<m; j++) {
			cout << "a[" << i+1 << "][" << j+1 << "]= ";
			cin >> mas[i][j];
			chkMass[i][j] = mas[i][j];
		}
	}
	cout << "������� �������� ��� �����������\n";
	int *vary = new int[m];
	for (int i = 0; i < m; i++)
	{
		cout << "x["<< i+1 << "]= ";
		cin >> vary[i];
	}
	//PrintMatr(mas, m);
	d = Determinant(mas, m);
	//cout << "������������ ������� ����� " << d;
	double varDet;
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[j][i] = vary[j];
		}
		varDet = Determinant(mas, m);
		cout << "x{" << i << "}= " <<  varDet/d << endl;
		for (int j = 0; j < m; j++)
		{
			mas[j][i] = chkMass[j][i];
		}
	}
	cin.get(); cin.get();
	return 0;
}