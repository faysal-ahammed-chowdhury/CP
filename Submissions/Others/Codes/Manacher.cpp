#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; // change here
int pi[N + N];

void manacher(string s) {
  int n = s.size();
  string temp = "#";
  for (auto u : s) {
    temp.push_back(u);
    temp.push_back('#');
  }
  // cout << temp << '\n';
  int nn = temp.length();
  int l = 0, r = -1;
  for (int i = 0; i < nn; i++) {
    int k = 0;
    if (i <= r) {
      k = min(pi[l + r - i], r - i);
    }
    while (i + k + 1 < nn and i - k - 1 >= 0 and temp[i + k + 1] == temp[i - 1 - k]) {
      k++;
    }
    pi[i] = k;
    if (i + k > r) {
      r = i + k;
      l = i - k;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  manacher(s);

  cout << s << '\n';
  for (int i = 0; i <= n + n; i++) {
    cout << pi[i] << ' ';
  }
  cout << '\n';

  return 0;
}