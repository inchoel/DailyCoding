#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int arg, char* argv[])
{
  if (arg != 3) {
    cout << "preprocessor input.txt result.txt" << endl;
    return 0;
  }

  ifstream inputFile(argv[1]);
  unordered_map<string, string> m;

  // input processing
  string line;
  vector<string> vstr;
  while ( getline(inputFile, line) ) {
    istringstream iss(line);
    string word;
    iss >> word;
    if (word.empty())
      continue;

    if (word == "define") {
      string key, value;
      iss >> key;
      iss >> value;
      m[key] = value;
    }
    else {
      vstr.push_back(line);
    }
  }

  // replace
  ofstream outputFile(argv[2]);
  for (auto line : vstr) {
    istringstream iss(line);
    istreambuf_iterator<char> p1(iss), p2;

    while (*p1 != EOF) {
      ostringstream oss;
      while (*p1 != ' ' && *p1 != EOF) {
        oss << *p1;
        p1++;
      }
      string key = oss.str();
      if (m.find(key) != m.end())
        key = m[key];

      outputFile << key;
      if (*p1 != EOF)
        outputFile << *p1;
      else
        outputFile << '\n';

      p1++;
    }
  }
}
