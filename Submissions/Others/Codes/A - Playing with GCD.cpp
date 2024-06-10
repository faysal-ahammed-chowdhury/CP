#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e4 + 9;

int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

void solve() {
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n == 1) {
    cout << "YES\n";
    return;
  }
  
  vector<int> v;
  v.push_back(a[0]);
  for(int i = 1; i < n; i++) {
    v.push_back(lcm(a[i], a[i - 1]));
  }
  v.push_back(a[n - 1]);


  for(int i = 0; i < n; i++) {
    if(__gcd(v[i], v[i + 1]) != a[i]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}