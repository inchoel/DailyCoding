#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct People
{
  string name;
  int age;

  People(string n, int a) : name(n), age(a) {}
  void Dump() const { cout << name << "(" << age << ")" << endl; }
};

int main()
{
  vector<shared_ptr<People>> v;

  v.push_back(make_shared<People>("kim", 10));
  v.push_back(make_shared<People>("lee", 15));
  v.push_back(make_shared<People>("park", 5));
  v.push_back(make_shared<People>("jung", 20));
  v.push_back(make_shared<People>("choi", 12));

  cout << "이름순정렬" << endl;
  sort (begin(v), end(v),
      [](shared_ptr<People>& a, shared_ptr<People>& b) {
        return a->name < b->name;
      });
  for (auto p : v)
    p->Dump();

  cout << "나이순정렬" << endl;
  sort (begin(v), end(v),
      [](shared_ptr<People>& a, shared_ptr<People>& b) {
      return a->age < b->age;
      });
  for (auto p : v)
    p->Dump();

}
