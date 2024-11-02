#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 51

int prime_numbers[MAX] = {true};

void sieve()
{
    for (int i = 2; i <= MAX; i++)
    {
        if (prime_numbers[i] == true)
        {
            for (int j = 2; i * j <= MAX; j++)
            {
                prime_numbers[i * j] = false;
            }
        }
    }
}

int binary_search(vector<int> v, int n, int val)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == val)
            return mid;
        else if (v[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        prime_numbers[i] = true;
    }
    prime_numbers[0] = false;
    prime_numbers[1] = false;

    sieve();

    vector<int> prime_numbers_v;

    for (int i = 0; i < MAX; i++)
    {
        if (prime_numbers[i] == 1)
            prime_numbers_v.push_back(i);
    }

    int a, b;
    cin >> a >> b;

    a = binary_search(prime_numbers_v, prime_numbers_v.size(), a);
    b = binary_search(prime_numbers_v, prime_numbers_v.size(), b);
    if (b - a == 1)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
