#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, arr[N];
string t, p;

bool is_subsequence(string s) {
    int j = 0;
    for(int i = 0; i < p.length(); i++) {
        bool found = 0;
        for(; j < s.length(); j++) {
            if(p[i] == s[j]) {
                found = true;
                j++;
                break;
            }
        }
        if(!found) return false;
    }
    return true;
}

bool ok(int mid) {
    set<int> se;
    for(int i = 0; i <= mid; i++) {
        se.insert(arr[i] - 1);
    }
    string s = "";
    for(int i = 0; i < n; i++) {
        if(se.find(i) == se.end()) {
            s += t[i];
        }
    }
    return is_subsequence(s);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> p;
    n = t.length();
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1, ans = - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans + 1 << '\n';
    return 0;
}