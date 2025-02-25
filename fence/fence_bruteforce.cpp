#include <iostream>

using namespace std;

int findSquare(int bars[], int numBars, int n)
{
  int square = 0;
  //add left
  for(int i = n; i >= 0; i--)
  {
    if(bars[i] < bars[n])
      break;
    square += bars[n];
  }
  //add right
  for(int i = n+1; i < numBars; i++)
  {
    if(bars[i] < bars[n])
      break;
    square += bars[n];
  }
  
  return square;
}

void solve(void)
{
  int bars[20000];
  int numBars;
  int maxSquare = 0;
  int tmp;

  cin >> numBars;
  for(int i = 0; i < numBars; i++)
    cin >> bars[i];

  for(int i = 0; i < numBars; i++)
  {
    tmp = findSquare(bars, numBars, i);
    if(tmp > maxSquare)
      maxSquare = tmp;
  }

  cout << maxSquare << endl;

}

int main(void)
{
  int T;
  cin >> T;
  for(int i = 0; i < T; i++)
    solve();
}
