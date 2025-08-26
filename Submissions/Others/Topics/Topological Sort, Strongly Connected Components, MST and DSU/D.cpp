#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
int n;
string s[N];
vector<int> g[26];
int indeg[26];

int f(char c) {
  return c - 'a';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i < n; i++) {
    int x = s[i].size();
    int y = s[i + 1].size();
    int idx = -1;
    for (int j = 0; j < min(x, y); j++) {
      if (s[i][j] != s[i + 1][j]) {
        idx = j;
        break;
      }
    }

    if (idx != -1) {
      g[f(s[i][idx])].push_back(f(s[i + 1][idx]));
      indeg[f(s[i + 1][idx])]++;
    }
    else if (x > y) {
      cout << "Impossible\n";
      return 0;
    }
  }

  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    ans.push_back(top);
    for (auto v : g[top]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  if (ans.size() == 26) {
    for (auto i : ans) {
      cout << char(i + 'a');
    }
    cout << '\n';
  }
  else {
    cout << "Impossible\n";
  }

  return 0;
}