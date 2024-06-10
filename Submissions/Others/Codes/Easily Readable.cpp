#include <bits/stdc++.h>
using namespace std;

const int N = 52;
const char base_char = 'A';
struct TrieNode {
  int cnt;
  int end_cnt;
  TrieNode * nxt[N];
  TrieNode() {
    cnt = 0;
    end_cnt = false;
    for (int i = 0; i < N; i++) nxt[i] = NULL;
  }
} *root;

int get(char c) {
  int idx = c - base_char;
  if (c > 'Z') idx -= 6;
  return idx;
}

void insert(const string &s) {
  TrieNode *cur = root;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int idx = get(s[i]);
    if (cur -> nxt[idx] == NULL) cur -> nxt[idx] = new TrieNode();
    cur = cur -> nxt[idx];
    cur -> cnt++;
  }
  cur -> end_cnt++;
}
int query(const string &s) {
  int n = (int)s.size();
  TrieNode *cur = root;
  for (int i = 0; i < n; i++) {
    int idx = get(s[i]);
    if (cur -> nxt[idx] == NULL) return 0;
    cur = cur -> nxt[idx];
  }
  return cur -> end_cnt;
}
void del(TrieNode *cur) {
  for (int i = 0; i < N; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
  delete(cur);
}

string get(string &s) {
  int n = s.size();
  if (n <= 3) return s;
  string str = "";
  for (int i = 1; i + 1 < n; i++) {
    str += s[i];
  }
  sort(str.begin(), str.end());
  return s[0] + str + s[n - 1];
}

int cs;
void solve() {
  root = new TrieNode(); // init new trie
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    s = get(s);
    insert(s);
  }
  int m; cin >> m;
  cin.ignore();
  cout << "Case " << ++cs << ":\n";
  while (m--) {
    string s; getline(cin, s);
    stringstream ss(s);
    int ans = 1;
    while (ss >> s) {
      s = get(s);
      ans *= query(s);
    }
    cout << ans << '\n';
  }
  del(root); // clear trie
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}