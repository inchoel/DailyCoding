#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N;
map<string, vector<int>> m;
vector<pair<int, string>> v;

bool cmp (const pair<int,string>& a, const pair<int,string>& b)
{
	bool ret = false;
	if (a.first > b.first)
		ret = true;
	else if (a.first == b.first) {
		ret = (m[a.second][0] < m[b.second][0]);
	}
	return ret;
}

void Solve()
{
	int cnt = 0;
	for (auto e : v) {
		if (e.first < 2)
			continue;

		printf("%s ", e.second.c_str());
		for (auto ee: m[e.second]) {
			printf("%d ", ee);
		}
		printf("\n");

		cnt += m[e.second].size();
		if (cnt * 100 / N >= 50)
			break;
	}

	if (cnt==0)
		printf("unique\n");
}

void InputData()
{
	char name[21];
	map<string, vector<int>>::iterator it;

	scanf (" %d", &N);
	for (int i=1; i<=N; i++) {
		scanf (" %s", name);
		it = m.find(name);
		if (it == m.end()) {
			vector<int> vv(1, i);
			m[name] = vv;
		}
		else {
			it->second.push_back(i);
		}
	}

	for (auto model : m) {
		v.push_back(make_pair(model.second.size(), model.first));
	}
	sort (v.begin(), v.end(), cmp);
#if 0
	for (auto eee : v) {
		printf("%s ", eee.second.c_str());
		for (auto size : m[eee.second])
			printf("%d ", size);
		printf("\n");
	}
#endif
}

int main()
{
	InputData();
	Solve();
	return 0;
}
