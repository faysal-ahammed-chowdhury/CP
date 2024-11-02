#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    k--;
    int score = arr[k];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] >= score)
            count++;
    }

    cout << count << endl;

    return 0;
}
