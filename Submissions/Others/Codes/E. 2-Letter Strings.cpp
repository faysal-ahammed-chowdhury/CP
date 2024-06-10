#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    map<char, int> mp1, mp2;
    map<string, int> mp3;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      string s; cin >> s;
      ans += mp1[s[0]];
      ans += mp2[s[1]];
      ans -= (mp3[s] * 2);
      mp1[s[0]]++, mp2[s[1]]++, mp3[s]++;
    }
    cout << ans << '\n';
  }

  return 0;
}