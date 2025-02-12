#include <iostream>

using namespace std;

int pairStus(int paired[10], bool areFriends[10][10], int numStus)
{
  int ret = 0;

  // check all paired
  int first = -1;
  for(int i = 0; i < numStus; i++)
  {
    if(!paired[i])
    {
      first = i;
      break;
    }
  }

  // all paired
  if(first == -1)
    return 1;

  for(int i = first + 1; i < numStus; i++)
  {
    if(!paired[i] && areFriends[first][i])
    {
      paired[i] = paired[first] = true;

      ret += pairStus(paired, areFriends, numStus);
      paired[i] = paired[first] = false;
    }
  }
  
  return ret;
}

int main()
{
  int t;
  int solution[50];
  
  cin >> t;
  for(int n = 0; n < t; n++)
  {
    int numStus = 0;
    int numPairs = 0;
    bool areFriends[10][10] = {false};
    int paired[10] = {false};

    cin >> numStus >> numPairs;
    for(int i = 0; i < numPairs; i++)
    {
      int a, b;
      cin >> a >> b;
      areFriends[a][b] = true;
      areFriends[b][a] = true;
    }

    solution[n] = pairStus(paired, areFriends, numStus);
  }
  for(int n = 0; n < t; n++)
    cout << solution[n] << endl;

  return 0;
}
