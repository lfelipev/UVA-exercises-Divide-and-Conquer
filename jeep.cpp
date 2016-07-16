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


       /* cout << "passou2" << endl;


        vector<int> books(n);

        for(k = 0; k < n; ++k)
        {
            cin >> books[k];
        }

        cin >> m;

        sort(books.begin(), books.end());
        i = books.front();
        j = books.back();

        for(k = 0; k < n; ++k)
        {
            first = books[k];
            second = m - first;

            if(binary_search(books.begin() + k + 1, books.end(), second))
            {
                if((second - first) < (j - i))
                {
                    i = first;
                    j = second;
                }

            }
        }

        cout << "Peter should buy books whose prices are " << i << " and " << j << "." << endl << endl;
        */
        getline(cin, input);
    }
    return 0;
}
