#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

string word;
string rword;
char s[101];
char t[101][101];
int n, m;

bool wordFind(const string temp) {
	//printf("%s\n", temp.c_str());

	if (temp.find(word)!=string::npos) {
		return true;
	}
	else if (temp.find(rword)!=string::npos) {
		return true;
	}
	return false;
}

bool checkRow(void) {
	string temp;
	for (int i=0; i<n; i++) {
		temp = t[i];

		if (wordFind(temp))
			return true;
	}
	return false;
}

bool checkCol(void) {
	for (int i=0; i<m; i++) {
		string temp;
		for (int j=0; j<n; j++) {
			temp.push_back(t[j][i]);
		}
		if (wordFind(temp))
			return true;
	}
	return false;
}



bool checkDiagonal(void) {
	int limit = min(n, m);
	int i;
	string temp;

	for (i=n-1; i>=0; i--) {
		int r=i, c=0;
		temp.clear();
		while (r<limit && c<limit) {
			temp.push_back(t[r++][c++]);
		}
		if (wordFind(temp))
			return true;
	}

	for (int i=1; i<m; i++) {
		int r=0, c=i;
		temp.clear();
		while (r<limit && c<limit) {
			temp.push_back(t[r++][c++]);
		}
		if (wordFind(temp))
			return true;
	}

	for (int i=n-1; i>=0; i--) {
		int r=i, c=m-1;
		temp.clear();
		while (r<limit && c>=0) {
			temp.push_back(t[r++][c--]);
		}
		if (wordFind(temp))
			return true;
	}

	for (int i=m-2; i>=0; i--) {
		int r=0, c=i;
		temp.clear();
		while (r<limit && c>=0) {
			temp.push_back(t[r++][c--]);
		}
		if (wordFind(temp))
			return true;
	}

	return false;
}

int main() {
	scanf (" %s", s);
	word = s;
	for (int i=word.size()-1; i>=0; i--)
		rword.push_back(word[i]);

	scanf (" %d %d", &n, &m);
	for (int i=0; i<n; i++) {
		scanf (" %s", t[i]);
	}

	if (checkRow() || checkCol() || checkDiagonal())
		printf("1\n");
	else
		printf("0\n");

	return 0;
}

