#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <utility>
//#include <bits/stdc++.h>
using namespace std;

pair<int, int> aux(vector<int> a, int mid, int x) {
		int m = mid;
		int maior, menor = 0;
		while (a[mid] == x) {
			++mid;
			maior = a[mid];
		}
		while (a[m] == x) {
			--m;
			menor = a[m];
		}
		return make_pair(maior, menor);
}

pair<int, int> find_x(vector<int> a, int left, int right, int x)
{
	
	while (left <= right) {
		int mid = (left + right)/2;
		int midVal = a[mid];

		if (midVal < x)
			left = mid + 1;
		else if (midVal > x)
			right = mid - 1;
		else
			return aux(a,mid,x); // key found
	}
	return make_pair(a[left], a[left-1]);
}

int main()
{
	vector<int> lady_chimps;
	int n, n2;
	string tmp;

	//começa a leitura das chimps

	scanf("%d ", &n);
	lady_chimps.push_back(-1);
	getline(cin, tmp);
	stringstream ss(tmp);
	int ti;

	while (ss >> ti)
	{
		lady_chimps.push_back(ti);
	}

	lady_chimps.push_back(-1);

	// Leitura do Luchu
	scanf("%d ", &n2);
	getline(cin, tmp);
	stringstream ss2(tmp);

	for (int i = 0; i < n2; ++i) {
		pair<int, int> p;
		ss2 >> ti;
		p = find_x(lady_chimps, 1, n , ti);

		if (p.second == -1) {
			printf("X ");
		}
		else {
			printf("%d ", p.second);
		}
		if (p.first == -1) {
			printf("X\n");
		}
		else {
			printf("%d\n", p.first);
		}
	}
	getchar();
}
