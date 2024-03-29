#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, m, i, j, first, second;

    while (cin >> n)
    {
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
    }
    return 0;
}
