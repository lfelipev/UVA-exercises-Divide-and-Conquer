#include <bits/stdc++.h>

using namespace std;

enum events { CONSUMPTION = 1, LEAK = 2, STATION = 3, MECHANIC = 4, GOAL = 5};

//Vector<pair<Tipo de evento,pair<posição,valor(se não existir deixe = 0)>>
bool run_simulation(vector<pair<int, pair<int,int>>> &v, double fuel) {
    int n = v.size();
    int currentFuel = fuel;
    int leaks, consumption, currentPosition = 0;
    for (int i = 0; i < n; ++i) {
        currentFuel -= (v[i].second.first - currentPosition) * (leaks + consumption / 100);
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

float search(vector<pair<int, pair<int,int>>> &v, float low, float high) {
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

int main()
{
    int d;
    float n = 0;
    float p;
    string defaults("0 Fuel consumption 0");
    string input, sub, event;
    int consumption = 0;
    vector<pair<int, pair<int,int>>> v;
    getline(cin, input);
    while (defaults.compare(input) != 0)
    {
        if (input.front() == '0')
        {
            sub = input.substr(19, 2);
            stringstream(sub) >> p;
            n = n + p;
        }
        else
        {
            istringstream iss(input);
            iss >> d >> event;

            if(event == "Goal") {
                v.push_back(make_pair(GOAL, make_pair(d, 0)));
                consumption = search(v, 0, n);
                cout << consumption << endl;
            }
            else if (event == "Mechanic")
                v.push_back(make_pair(MECHANIC, make_pair(d, 0)));
            else if (event == "Gas")
                v.push_back(make_pair(STATION, make_pair(d, 0)));
        }

        getline(cin, input);
    }
    return 0;
}
