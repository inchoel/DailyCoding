#include <iostream>
#include <string>
using namespace std;

void encrypt(const string s, string& encrypted)
{
  encrypted = s;
  for(size_t i=0; i<s.size(); i++) {
    char c = s[i];
    if (c >= 'a' && c <= 'z')
      c = ((c - 'a') + 13) % 26 + 'a';
    if (c >= 'A' && c <= 'Z')
      c = ((c - 'A') + 13) % 26 + 'A';

    // cout << c;
    encrypted[i] = c;
  }
}

int main()
{
  string input, output;
  getline(cin, input);

  encrypt(input, output);
  cout << output << endl;
}
