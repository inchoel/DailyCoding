#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Person_ {
  int registerNumber;
  int age;
  string name;
} Person;

bool comp (Person a, Person b)
{
  if (a.age < b.age)
    return true;

  if (a.age == b.age) {
    if (a.registerNumber > b.registerNumber)
      return true;
  }

  return false;
}


int main() {
  int n;
  Person temp;
  vector<Person> person;

  cin >> n;
  while (n--) {
    temp.registerNumber = n;
    cin >> temp.age >> temp.name;
    person.push_back(temp);
  }

  sort(person.begin(), person.end(), comp);

  for (auto e: person)
    cout << e.age << " " << e.name << endl;

  return 0;
}
