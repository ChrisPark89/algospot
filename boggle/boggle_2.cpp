#include <iostream>

using namespace std;

int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool findWord(string board[], string word, int x, int y)
{
  if( x < 0 || y < 0)
    return false;

  if(word[0] != board[x][y])
    return false;

  if(word.length() == 1)
    return true;


  for(int i = 0; i < 8; i++)
  {
    int nextX = x + dx[i];
    int nextY = y + dy[i];

    if(findWord(board, word.substr(1), nextX, nextY))
      return true;
  }
  return false;
}

int main()
{
  int numTest = 0;
  int numWords = 0;
  bool rc = false;

  string board[5];
  string words[10]; string str;


  cin >> numTest;
  cin.ignore();
  for(int t = 0; t < numTest; t++)
  {

    // scan board
    for(int i = 0; i < 5; i++)
      getline(cin, board[i]);

    // scan words
    cin >> numWords;
    cin.ignore();
    for(int i = 0; i < numWords; i++)
      getline(cin, words[i]);

    for(int i = 0; i < numWords; i++)
    {
      for(int j = 0; j < 5; j++)
      {
        for(int k = 0; k < 5; k++)
        { 
          rc = findWord(board, words[i], j, k);
          if(rc)
            break;
        }
        if(rc)
          break;
      }

      if(rc)
        cout << words[i] << " " << "YES" << endl;
      else
        cout << words[i] << " " << "NO" << endl;
    }
  }
}


