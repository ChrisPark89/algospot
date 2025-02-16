#include <iostream>

using namespace std;

int w, h = 0;
char board[20][20] = {0};

int coverBoard()
{
  int ret = 0;

  //find next white board
  int nextX = -1;
  int nextY = -1;
  for(int i = 0; i < w; i++)
  {
    for(int j = 0; j < h; j++)
    {
      if(board[i][j] == '.')
      {
        nextX = i;
        nextY = j;
        break;
      }
    }
    if(nextX != -1 && nextY != -1)
      break;
  }

  //no white board means it's a solution
  if(nextX == -1 || nextY == -1)
    return 1;

  //4 possibility to make the block
  if(nextX+1 < w && nextY+1 < h && board[nextX][nextY+1] == '.' && board[nextX+1][nextY] == '.')
  {
    board[nextX][nextY] = board[nextX][nextY+1] = board[nextX+1][nextY] = '#';
    ret += coverBoard();
    board[nextX][nextY] = board[nextX][nextY+1] = board[nextX+1][nextY] = '.';
  }
  if(nextX+1 < w && nextY+1 < h && board[nextX][nextY+1] == '.' && board[nextX+1][nextY+1] == '.')
  {
    board[nextX][nextY] = board[nextX][nextY+1] = board[nextX+1][nextY+1] = '#';
    ret += coverBoard();
    board[nextX][nextY] = board[nextX][nextY+1] = board[nextX+1][nextY+1] = '.';
  }
  if(nextX+1 < w && nextY+1 < h && board[nextX+1][nextY] == '.' && board[nextX+1][nextY+1] == '.')
  {
    board[nextX][nextY] = board[nextX+1][nextY] = board[nextX+1][nextY+1] = '#';
    ret += coverBoard();
    board[nextX][nextY] = board[nextX+1][nextY] = board[nextX+1][nextY+1] = '.';
  }
  if( nextY-1 >= 0 && nextX+1 < w && board[nextX+1][nextY] == '.' && board[nextX+1][nextY-1] == '.')
  {
    board[nextX][nextY] = board[nextX+1][nextY] = board[nextX+1][nextY-1] = '#';
    ret += coverBoard();
    board[nextX][nextY] = board[nextX+1][nextY] = board[nextX+1][nextY-1] = '.';
  }

  return ret;
}

int main()
{
  int n;
  cin >> n;
  for(int t = 0; t < n; t++)
  {
    int numWhite = 0;
    int ret = 0;

    cin >> w >> h;
    for(int i = 0; i < w; i++)
    {
      for(int j = 0; j < h; j++)
      {
        cin >> board[i][j];
        if(board[i][j] == '.')
          numWhite++;
      }
    }

    if(numWhite % 3 == 0)
      ret += coverBoard();
    else
      ret = 0;

    cout << ret << endl;
  }
}
