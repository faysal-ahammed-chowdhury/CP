#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int min_diff(string str, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int count = min_diff(str, n);

    cout << count << endl;
    return 0;
}
