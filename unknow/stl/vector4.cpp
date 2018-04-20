#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Findchar
{
  string data;

  FindChar (string s) : data(s) { }

  bool operator()(char c) const
  {
    auto p = find (begin(data), end(data));
    return p != end(data);
  }
};

int main()
{
  ifstream f("vector4.cpp");

  string s;
  // f >> s;  // 한 단어 읽기
  // getline(f, s);
  //
  vector<string> v;
  while (getline(f,s))
    v.push_back(s);

  //--------------------------
  // reverse (begin(v), end(v));

  for (int i=0; i<v.size(); i++) {
    // reverse (begin(v[i]), end(v[i]));

    replace (begin(v[i]), end(v[i]), 'i', ' ');

    // 모든 모음을 공백으로 치환 (여기서는 'a'만 처리함)
    replace_if (begin(v[i]), end(v[i]),
                [](char c) { return c=='a'; }, ' ');

    // 람다표현식을 사용하는 것보다 함수객체를 사용하는 것이 더 편리하다.
    // 함수객체는 상태(string data)를 가지기 때문에 활용이 편리하다.
    FindChar fc("aieouAIEOU");
    replace_if (begin(v[i]), end(v[i]),
                fc, ' ');


  }
  //--------------------------
  for (auto str : v)
    cout << str << endl;
}
