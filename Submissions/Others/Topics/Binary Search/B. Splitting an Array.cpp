#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e14;
const int N = 1e5 + 9;
int arr[N];
int n, k;

bool ok(long long max_sum) {
    long long sum = 0;
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_sum) return false;
        if(sum + arr[i] > max_sum) {
            count++;
            sum = 0;
        }
        sum += arr[i];
    }
    if(arr[n] > max_sum) return false;
    if(sum + arr[n] > max_sum) count += 2;
    else count++;
    return count <= k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    long long l = 1, r = MAX, ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}