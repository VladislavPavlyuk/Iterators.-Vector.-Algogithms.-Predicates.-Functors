/*
����������� ���������� �++.���������.������.���������.���������.��������.
1. ��� ������, �������� ����� �����.
	���������� ������� �� ������� ��� ������������� �����.

2. ���� ��� ������� ��������� ����������� : �[M] � B[N].
    ���������� ������� ������ ������, � ������� ����� ������� �������� ������ ���� ��������.

3. ���� ��� ������� ���������  ����������� : �[M] � B[N].
    ���������� ������� ������ ������, � ������� ����� ������� ����� �������� ������ ���� ��������.

4. ���� ��� ������� ��������� ����������� : �[M] � B[N].
    ���������� ������� ������ ������, � ������� ����� ������� �������� ������� A, ������� ��� � ������� B.

24-1. ���� ��� ������� ��������� ����������� : �[M] � B[N].
���������� ������� ������ ������, � ������� ����� ������� �������� �������� A � B, ������� �� �������� ������ ��� ���.
*/

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;



bool existElement(int q, vector<int> u)		// �������� �� ������� �������� � �������
{
	vector<int>::iterator pb;
	for (pb = u.begin(); pb != u.end(); pb++)
	{
		if (q == *pb) return true;
	}

	return false;
}

// 24-1 ������ ������, � ������� ����� ������� �������� �������� A � B, ������� �� �������� ������ ��� ���.
vector<int> uniteAllDifferentElementsOfTwoVectors(vector<int> x, vector<int> y)
{
	vector<int> z;
	int exist = 0;
	vector<int>::iterator ix,iy;

	for (ix = x.begin(); ix != x.end(); ix++)
	{
		for (iy = y.begin(); iy != y.end(); iy++)
		{
			if ((!existElement(*ix, y)) && (!existElement(*ix, z)))
				z.push_back(*ix);

			if ((!existElement(*iy, x)) && (!existElement(*iy, z)))
				z.push_back(*iy);

		}
	}
	return z;
}

//������ ������, � ������� ����� ������� �������� ������� A, ������� ��� � ������� B.
vector<int> uniteAnotExistInB(vector<int> x, vector<int> y)
{
	vector<int> z;
	vector<int>::iterator ix;
	for (ix = x.begin(); ix != x.end(); ix++)
	{
			if ((!existElement(*ix, y)) && (!existElement(*ix, z)))
				z.push_back(*ix);
	}
	return z;
}

//23-3 ������ ������, � ������� ����� ������� ����� �������� ������ ���� ��������.
vector<int> uniteSameElementsOfTwoVectors(vector<int> x, vector<int> y)
{
	vector<int> z;
	vector<int>::iterator ix,iy;
	for (ix = x.begin(); ix != x.end(); ix++)
	{
		for (iy = y.begin(); iy != y.end(); iy++)
		{
			if ((*ix == *iy) && (!existElement(*ix, z)))
				z.push_back(*ix);
		}
	}
		return z;
}

// 23-2 ������ ������, � ������� ����� ������� �������� ������ ���� ��������.
vector<int> uniteTwoVectors(vector<int> x, vector<int> y)
{
	vector<int> z;

	z.assign(y.begin(), y.end());

	copy(x.begin(), x.end(), back_inserter(z));

	return z;
}

void print(vector<int> x, string s)				// ����� ������� �� �����
{
	cout << endl;
	//�����  ��������
	ostream_iterator<int> out(cout, " ");
	cout << s << " : " << endl;
	copy(x.begin(), x.end(), out);
	cout << endl;
}

vector<int> deleteNegative(vector<int> x)		//23-1 �������� ������������� �������� � �������
{

	vector<int>::iterator it;
	it = remove_if(x.begin(), x.end(), [](int val)->bool { bool result = (val < 0); return result; });
	x.erase(it, x.end());
	return x;
}

int rangeRand()
{
	int r = -10 + rand() % 21;
	return r;
}

int main()
{
	srand(time(0));

	vector<int> A(10),B(12),C,D,E,F,G;
	vector<int>::iterator pb;

	generate(A.begin(), A.end(), rangeRand);
	generate(B.begin(), B.end(), rangeRand);

	print(A, "Vector A");
	print(B, "Vector B");

	E = deleteNegative(A);

	print(E,"Deleted all negative");

	C = uniteTwoVectors(A, B);

	print(C, "Two vectors united");

	D = uniteSameElementsOfTwoVectors(A, B);

	print(D, "All the same elements of two vectors united");

	F = uniteAllDifferentElementsOfTwoVectors(A, B);
	print(F, "All the different elements of two vectors");

	G = uniteAnotExistInB(A, B);
	print(G, "Elements of A vector that are not exist in B vector");

	return 0;
}
