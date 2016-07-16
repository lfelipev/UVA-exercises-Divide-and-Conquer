#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, d, i, j, first, second;
    string defaults("0 Fuel consumption 0");
    string input, sub, event;

    getline(cin, input);
    while (defaults.compare(input) != 0)
    {
        if (input.front() == '0')
        {
            sub = input.substr(19, 2);
            stringstream(sub) >> n;
        }
        else
        {
            istringstream iss(input);
            iss >> d >> event;
            cout << "event: " << event << endl;
            cout << "d: " << d << endl;

            //temporário (apenas a solução básica antes de pensar na lógica)
            switch (event)
            {
                case "Goal":
                    break;
                case "Mechanic":
                    break;
                case "Gas":
                    break;
            }
        }

        getline(cin, input);
    }
    return 0;
}
