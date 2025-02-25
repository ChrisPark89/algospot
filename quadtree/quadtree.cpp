#include <iostream>

using namespace std;

string flip(string::iterator& it)
{
  char head = *it;
  it++;

  if(head == 'b' || head == 'w')
    return string(1, head);

  string upperLeft  = flip(it);
  string upperRight = flip(it);
  string lowerLeft  = flip(it);
  string lowerRight = flip(it);
 
  return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

void solve()
{
  string comp;
  cin >> comp;
  string::iterator it = comp.begin();

  cout << flip(it) << endl;
}

int main(void)
{
  int T;
  cin >> T;
  for(int n = 0; n < T; n++)
  {
    solve();
  }
}
