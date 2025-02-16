#include <iostream>

using namespace std;

//[clock][switch]
int switches[16][10] = {
                      3, 0, 0, 3, 0, 3, 0, 0, 0, 0, //0
                      3, 0, 0, 0, 0, 0, 0, 0, 3, 0,
                      3, 0, 0, 0, 0, 3, 0, 0, 3, 0,
                      0, 3, 0, 0, 0, 0, 3, 0, 3, 3,
                      0, 0, 3, 3, 0, 0, 0, 3, 3, 3,
                      0, 0, 0, 3, 0, 0, 0, 3, 3, 3, //5
                      0, 0, 0, 3, 3, 0, 0, 0, 0, 0,
                      0, 3, 0, 3, 3, 0, 0, 3, 0, 0,
                      0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
                      0, 3, 0, 0, 0, 0, 0, 0, 0, 3,
                      0, 0, 3, 0, 3, 0, 0, 0, 0, 0, //10
                      0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 3, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
                      0, 0, 3, 0, 0, 3, 3, 3, 0, 0,
                      0, 0, 3, 0, 0, 3, 3, 3, 0, 0  //15
                      };

void switchOn(int clock[16], int numSwitch[10], int s, int n)
{
  numSwitch[s] += n;

  for(int i = 0; i < 16; i++)
    clock[i] += n*switches[i][s];
  return;
}

//find combinations of switch(order doesn't matter) that makes n=0(mod12)
//
int syncClock(int clock[16], int numSwitch[10], int cur)
{
  bool success = true;
  int ret = 2000000;
  int tmp = 0;

  for(int i = 0; i < 16; i++)
  {
    if(clock[i] % 12 != 0)
      success = false;
  }

  if(success)
  {
    ret = 0;
    for(int i = 0; i < 10; i++)
      ret += numSwitch[i];
  }

  if(cur == 10)
    return ret;

  //try switches
  for(int i = 0; i < 4; i++)
  {
    switchOn(clock, numSwitch, cur, i);
    tmp = syncClock(clock, numSwitch, cur+1);
    switchOn(clock, numSwitch, cur, -i);
    if(tmp < ret)
      ret = tmp;
  }

  return ret;
}

int solve(void)
{
  int clock[16] = {0};
  int numSwitch[10] = {0}; // the value should be less than 4

  for(int i = 0; i < 16; i++)
    cin >> clock[i];

  return syncClock(clock, numSwitch, 0);
}

int main(void)
{
  int t;
  int ret = 0;
  cin >> t;
  for(int n = 0; n < t; n++)
  {
    ret = solve();
    if(ret == 2000000)
      ret = -1;
    cout << ret << endl;
  }
}
