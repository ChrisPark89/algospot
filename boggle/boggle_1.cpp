#include <iostream>

using namespace std;

int findWord(string board[], string word, int numPicked, int row, int col)
{
  numPicked++;
  if( row < 0 || col < 0)
    return 0;

  if( numPicked > word.length() )
    return 0;

  if( board[row][col] != word[numPicked-1] )
    return 0;

  if( numPicked == word.length() && board[row][col] == word[numPicked-1])
    return 1;

  for(int i = -1; i < 2; i++)
  {
    for(int j = -1; j < 2; j++)
    {
      if( i == 0 && j == 0 )
        continue;
      if(findWord(board, word, numPicked, row + i, col + j))
        return 1;
    }
  }
  return 0;
}

int main()
{
  int numTest = 0;
  int numWords = 0;
  int rc = 0;

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
          if( board[j][k] == words[i][0] )
          {
            if(findWord(board, words[i], 0, j, k))
            {
              rc = 1;
              break;
            }
          }
        }
        if(rc)
          break;
      }
      if(rc == 1)
        cout << words[i] << " " << "YES" << endl;
      else
        cout << words[i] << " " << "NO" << endl;
      rc = 0;
    }
  }
}


