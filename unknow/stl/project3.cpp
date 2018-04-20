#include <iostream>
#include <string>
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

  
}
