#include <bits/stdc++.h>

using namespace std;

enum events { CONSUMPTION = 1, LEAK = 2, STATION = 3, MECHANIC = 4, GOAL = 5 };

//Vector<pair<Tipo de evento,pair<posição,valor(se não existir deixe = 0)>>
bool run_simulation(vector<pair<int, pair<int, double>>> &v, double fuel) {
	int n = v.size();
	double currentFuel = fuel;
	double leaks = 0;
	double consumption = 0;
	int currentPosition = 0;
	for (int i = 0; i < n; ++i) {
		currentFuel -= (v[i].second.first - currentPosition) * (leaks + consumption / 100);
		currentPosition = v[i].second.first;
		if (currentFuel > 0) {
			if (v[i].first == CONSUMPTION) consumption = v[i].second.second;
			else if (v[i].first == LEAK) ++leaks;
			else if (v[i].first == STATION) currentFuel = fuel;
			else if (v[i].first == MECHANIC) leaks = 0;
			// else if (v[i].first == GOAL) consumption = v[i].second.second;
		}
	}
	if (currentFuel >= 0) return true;
	else return false;

}

double search(vector<pair<int, pair<int, double>>> &v, double low, double high) {
	if (high - low < 1e-11) {
		return low;
	}
	double mid = (low + high) / 2;
	if (!run_simulation(v, mid)) {
		low = mid;
		return search(v, low, high);
	}
	else {
		high = mid;
		return search(v, low, high);
	}


}

int main()
{
	int d;
	double n = 0;
	string defaults("0 Fuel consumption 0");
	string input, event;
	double nleaks = 0;
	double consumption = 0;
	vector<pair<int, pair<int, double>>> v;
	getline(cin, input);
	while (defaults.compare(input) != 0)
	{
			istringstream iss(input);
			iss >> d >> event;

			if (event == "Goal") {
				v.push_back(make_pair(GOAL, make_pair(d, 0)));
				consumption = search(v, 0, d * (n/100 + nleaks));
				n = 0;
				nleaks = 0;
				v.clear();
				cout << setprecision(3) << fixed <<consumption << endl;
			}
			else if (event == "Mechanic")
				v.push_back(make_pair(MECHANIC, make_pair(d, 0)));
			else if (event == "Gas")
				v.push_back(make_pair(STATION, make_pair(d, 0)));
			else if (event == "Fuel") {
				double f;
				iss >> event;
				iss >> f;
				n = max(n, f);
				v.push_back(make_pair(CONSUMPTION, make_pair(d, f)));			
			}
			else if (event == "Leak") {
				v.push_back(make_pair(LEAK, make_pair(d, 0)));
				nleaks++;
			}
		//}

		getline(cin, input);
	}
	return 0;
}