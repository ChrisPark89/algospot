#include <iostream>

using namespace std;


int pairStudents(bool taken[], bool areFriends[][10], int numStudents)
{
  // find the first
  int firstFree = -1;  
  for(int i = 0; i < numStudents; i++)
    if (taken[i] == false)
    {
      firstFree = i;
      cout << "firstFree: " << firstFree << endl; 
      break;
    }

  // base case: everyone is taken
  if (firstFree == -1)
  {
    cout << "Found" << endl;
    return 1;
  }

 :
  int ret = 0;
  for(int i = firstFree + 1; i < numStudents; i++)
  {
    if(taken[i] == false && areFriends[firstFree][i])
    {
      taken[firstFree] = taken[i] = true;
      cout << firstFree << i << endl;
      ret += pairStudents(taken, areFriends, numStudents);
      taken[firstFree] = taken[i] = false;
    }
  }
  return ret;

}

int main()
{
  int numCase = 0;

  cin >> numCase;
  
  for(int n = 0; n < numCase; n++)
  {
    int numStudents = 0;
    int numPairs = 0;
    bool areFriends[10][10] = {false, };
    bool taken[10] = {false, };

    int ret = 0;

    cin >> numStudents;
    cin >> numPairs;
    for(int i = 0; i < numPairs; i++)
    {
      int x, y = 0;
      cin >> x;
      cin >> y;
      areFriends[x][y] = true;
      areFriends[y][x] = true; // << need to set the reverse order so it makes all cases in order.
    }
    
    cout << pairStudents(taken, areFriends, numStudents) << endl;
  }
}
