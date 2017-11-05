#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Student_ {
  string name;
  int kor;
  int eng;
  int math;
} Student;

bool comp (Student a, Student b)
{
  if (a.kor != b.kor)
    return (a.kor > b.kor);

  if (a.eng != b.eng)
    return (b.eng < b.eng);

  if (a.math != b.math)
    return (a.math > b.math);

  return a.name.compare(b.name);
}

int main() {
  int n;
  cin >> n;

  vector<Student> students(n);
  for (int i=0; i<n; i++) {
    cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
  }

  sort(students.begin(), students.end(), comp);

  for (auto s : students)
    cout << s.name << endl;
  return 0;
}
