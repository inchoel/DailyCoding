#if 0
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

#define SIZE (100010)

int main() {
  stack<char> s;
  vector<int> laser;
  char input[SIZE];
  char ch, prev;
  fgets(input, SIZE, stdin);

  int i=0, stick=0;
  do {
    ch = input[i++];

    if (ch == '(') {
      s.push(ch);
      laser.push_back(0);
    }
    else if (ch == ')') {
      if (prev == '(') {
        s.pop();
        laser.pop_back();
        for (int j=0; j<laser.size(); j++) {
          laser[j]++;
          // printf("laser %d: cnt:%d\n", j, laser[j]);
        }
      }
      else {
        stick += (laser[laser.size()-1] + 1);
        s.pop();
        laser.pop_back();
        // printf("\n\n --- stick = %d\n", stick);
      }

      }
    prev = ch;
  } while (ch != '\n');

  printf("%d\n", stick);
  return 0;
}
#endif
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  string input;
  stack<char> s;
  int result = 0;

  cin >> input;

  for(int i = 0; i < input.size(); i++) {
    if(input[i] == '(')
      s.push(input[i]);
    else{
      s.pop();
      if(input[i-1] == '(')
        result += s.size(); //스택의 사이즈만큼 더해준다.
      else
        result += 1;    //1을 더해준다.
    }
  }
  cout << result << endl;
  return 0;
}

