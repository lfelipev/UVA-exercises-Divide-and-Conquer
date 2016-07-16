#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool run_simulation(const vector<long long int> &v, long long int energy) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (energy < v[i]) return false;
		if (energy == v[i]) --energy;
	}
	return true;
}

long long int search(const vector<long long int> &v, long long int low, long long int high) {
	if (low >= high) {
		return low;
	}
	long long int mid = (low + high) / 2;
	if (!run_simulation(v, mid)) {
		low = mid+1;
		return search(v, low, high);
	}
	else {
		high = mid;
		return search(v, low, high);
	}


}


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		vector<long long int> distances;
		scanf("%d", &n);
		string s;
		getchar();
		getline(cin,s);
		stringstream ss(s);
		long long int ti;
		long long int tj = 0;
		while (ss >> ti) {
			distances.push_back(ti - tj);
			tj = ti;
		}
		long long int r = search(distances, 0, 10000001);
		printf("Case %d: %lld\n", i+1, r);
	}


	return 0;
}