#include <iostream>
#include <string>
using namespace std;

class mytraits : public char_traits<char>
{
  public:
};

template <typename T,
          typename Traits = std::char_traits<T>,
          typename Allocator = std::allocator<T> >
class basic_string
{
  T* buff;

  bool operator=(const basic_string& s)
  {
    Traits::compare( buff, s.buff, sizeof(buff));
  }
};

using string = basic_string<char>;

int main() {
  string s1 = "abcd";
  string s2 = "ABCD";

  if (s1 == s2)
    cout << "same" << endl;
  else
    cout << "not same" << endl;

  return 0;
}


