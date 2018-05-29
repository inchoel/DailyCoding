#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int area;
vector<pair<int,int>> v;

void show(const vector<pair<int,int>>& v)
{
	printf("--- show ---\n");
	for (auto e: v)
		printf("%d %d\n", e.first, e.second);
	printf("\n");
}

bool cmp (const pair<int,int>& a, const pair<int,int>& b)
{
	return (a.first < b.first);
}

bool cmph (const pair<int,int>& a, const pair<int,int>& b)
{
	return (a.second > b.second);
}

int main()
{
	scanf (" %d", &N);
	int l, h, maxl=0, maxh=0;
	for (int i=0; i<N; i++) {
		scanf (" %d %d", &l, &h);
		v.push_back(make_pair(l, h));
		if (maxh < h) {
			maxh = h;
			maxl = l;
		}
	}
	//printf("maxl=%d, maxh=%d\n", maxl, maxh);
	//show (v);
	sort (v.begin(), v.end(), cmp);
	//show (v);

	int maxh_vpos;
	for (int i=0; i<N; i++) {
		if (maxh == v[i].second) {
			maxh_vpos = i;
			break;
		}
	}
	sort (v.begin(), v.begin()+maxh_vpos, cmph);
	sort (v.begin() + maxh_vpos, v.end(), cmph);
	//show (v);

	// 왼쪽면적
	int lpos = maxl;
	for (int i=0; i<maxh_vpos; i++) {
		if (lpos < v[i].first)
			continue;

		area += ((lpos-v[i].first) * v[i].second);
		lpos = v[i].first;
		//printf("area=%d\n", area);
	}

	int rpos = maxl;
	int rh = maxh;
	for (int i=maxh_vpos; i<N; i++) {
		if (rpos > v[i].first)
			continue;

		if (v[i].second == rh) {
			area += rh;
			//printf("area=%d\n", area);
			rpos = v[i].first;
		}
		else {
			area += ((v[i].first - rpos) * v[i].second);
			//printf("area=%d\n", area);
			rpos = v[i].first;
			rh = v[i].second;
		}
	}

	printf("%d\n", area);

	return 0;
}
