#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <thread>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

#define NEW_THREAD (true)

class NotificationCenter
{
  using HANDLER = function<void(void*)>;
  map<string, vector<tuple<HANDLER, int, bool>>> noti_map;

public:
  void Register(string key, HANDLER h, int pr, bool thread=false)
  {
    noti_map[key].push_back(make_tuple(h, pr, thread));
  }

  void Notify(string key, void* param)
  {
    vector<tuple<HANDLER, int, bool>>& v = noti_map[key];
    sort(begin(v), end(v), [](const tuple<HANDLER, int, bool>& x, const tuple<HANDLER, int, bool>& y) {
                              return get<1>(x) > get<1>(y);
                           });

    HANDLER h;
    int priority;
    bool use_thread;
    for (auto t: v) {
      tie(h, priority, use_thread) = t;

      if (use_thread == true)
        // thread t(&h, param);
        cout << "-- make thread -- " << endl;
      else
        h(param);
    }
  }
};

void foo(void* p, string name)
{
  cout << name << " : " << this_thread::get_id() << endl;
  this_thread::sleep_for(1s);
  cout << name << " end" << endl;
}

int main()
{
  NotificationCenter nc;

  nc.Register("TEST_EVENT", bind(&foo, _1, "one"s), 1);
  nc.Register("TEST_EVENT", bind(&foo, _1, "two"s), 2, NEW_THREAD);
  nc.Register("TEST_EVENT", bind(&foo, _1, "three"s), 3);

  nc.Notify("TEST_EVENT", (void*)0);

  getchar();
}

