#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int cnt = 0;
void solve() {
  string s; cin >> s;
  int b; cin >> b;
  if(s[0] == '-') {
    s.erase(s.begin());
  }
  b = abs(b);
  long long a = 0;
  for(auto i: s) {
    int digit = i - '0';
    a = a * 10 + digit;
    a %= b;
  }
  cout << "Case " << ++cnt << ": ";
  if(a == 0) {
    cout << "divisible\n";
  }
  else {
    cout << "not divisible\n";
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}