#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int n = (int)s.size();
    int count = 0;
    int last = -1;
    for(int i = 0; i < n - 3; i++) {
        string sub = s.substr(i, (4));
        if(sub.find("bear") != string::npos) {
            int prev = i - (last + 1);
            int next = n - (i + 4);
            last = i;
            count++;
            count += prev;
            count += next;
            count += (prev * next);
        }
    }
    cout << count << '\n';
    return 0;
}