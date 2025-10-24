#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<int>> cards, vector<vector<int>> moves, int query) {
  vector<int> ans;
 
  int x, y;

  for (vector<int> v: cards) {
    if (v[0] == query) {
      x = v[1]; y = v[2];
    }
  }

  for (vector<int> v: moves) {
    if (v[1] == x && v[2] == y) {
      x = v[3]; y = v[4];
      continue;
    }
    if (v[2] == y && v[1] < x) x--;
    if (v[4] == y && v[3] <= x) x++;
  }

  ans.push_back(x);
  ans.push_back(y);

  return ans;
}

int main () {
  int n;
  cin >> n;
  vector<vector<int>> cards;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cards.push_back({a, b, c});
  }

  int m;
  cin >> m;
  vector<vector<int>> moves;

  for (int i = 0; i < m; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    moves.push_back({a, b, c, d, e});
  }

  int q;
  cin >> q;

  vector<int> ans = solution(cards, moves, q);

  for (auto e : ans) cout << e << " ";
  cout << endl;
}
