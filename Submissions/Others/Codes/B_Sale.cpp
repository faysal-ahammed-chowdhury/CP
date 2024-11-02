/* #include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int min = 1001;
        int min_index;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        if (min > 0)
            break;
        arr[min_index] = 1001;
        sum += (-min);
        min = 1001;
    }

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n, m, val;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        pq.push(-val);
    }

    int ans = 0;
    while (m--)
    {
        val = -pq.top();
        pq.pop();
        if (val > 0)
            break;
        ans += (-val);
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
