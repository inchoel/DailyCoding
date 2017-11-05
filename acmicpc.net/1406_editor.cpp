#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>
using namespace std;

void getInput(list<char>& v)
{
  char c;
  do {
    c = getchar();
    if (c != '\n')
      v.push_back(c);
  } while (c != '\n');
}

void moveLeft(const list<char>::iterator begin, list<char>::iterator& pos)
{
  if (pos == begin)
    return;

  pos--;
}

void moveRight(const list<char>::iterator end, list<char>::iterator& pos)
{
  if (pos == end)
    return;

  pos++;
}

void delChar(list<char>& text, list<char>::iterator& pos)
{
  if (text.empty())
    return;

  if (text.begin() != pos)
    pos--;
  pos = text.erase(pos);
}

void insertChar(list<char>& v, list<char>::iterator& pos)
{
  char c;
  do {
    c = getchar();
    if (c != '\n' && c != ' ') {
      v.insert(pos, c);
    }
  } while (c != '\n');
}

int main()
{
  list<char> text;
  getInput(text);
  list<char>::iterator cursor = text.end();

  size_t numOfCommand;
  char command;
  cin >> numOfCommand;

  while (numOfCommand) {
    // cout << "cursor : " << cursor << endl;
    cin >> command;
    switch(command) {
      case 'L':
        moveLeft(text.begin(), cursor);
        break;
      case 'D':
        moveRight(text.end(), cursor);
        break;
      case 'B':
        delChar(text, cursor);
        break;
      case 'P':
        insertChar(text, cursor);
        break;
    }
    numOfCommand--;
  }

  // cout << "text size = " << text.size() << endl;
  for(auto i: text)
    cout << i;
  cout << endl;
  return 0;
}
