#include <iostream>
#include <iomanip>

using namespace std;

double tsp(double d[8][8], bool visited[8], int numCity, int x)
{
  double ret = 99999;
  double temp;
  bool done = true;

  for(int i = 0; i < numCity; i++)
  {
    if(!visited[i])
    {
      done = false;
      visited[i] = true;
      temp = d[x][i] + tsp(d, visited, numCity, i);
      if (temp < ret)
        ret = temp;
      visited[i] = false;
    }
  }
  if(done)
    return 0;
  else
    return ret;
}

int main()
{
  int t;
  double d[8][8] = {0.0000000000};

  cout << setprecision(14);

  cin >> t;
  for(int n = 0; n < t; n++)
  {
    double temp;
    double ret = 99999;
    int numCity = 0;
    cin >> numCity;

    for(int i = 0; i < numCity; i++)
      for(int j = 0; j < numCity; j++)
        cin >> d[i][j];

    for(int i = 0; i < numCity; i++)
    {
      bool visited[8] = {false};
      visited[i] = true;
      temp = tsp(d, visited, numCity, i);
      if (temp < ret)
        ret = temp;
    }
    cout << ret << endl;
  }
}
