#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{

  string map[3][3] = {
      {" - ", " - ", " - "},
      {" - ", " - ", " - "},
      {" - ", " - ", " - "}};

  string n;
  int row;
  int column;

  cout << "Funky tic tac toe!" << endl;

  bool key = true;
  for (int i = 0; i < 9 && key == true; i++)
  {
    cout << endl;
    if (i <= 0)
    {
      cout << "Insert x or o: (or something else and see if that works :D) \n";
    }
    else
    {
      cout << "Insert x or o: \n";
    }
    cin >> n;
    cout << endl;
    cout << "Enter the location (num 0-2) row = ";
    cin >> row;
    cout << "(num 0-2) column = ";
    cin >> column;
    cout << "\n";
    map[row][column] = n;

    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        cout << map[j][k] << " ";
      }
      cout << endl;
    }

    // purposeful inefficient checking (learning purposes)

    int k = 0;
    for (int j = 0; j < 3; j++)
    {
      if (map[j][k] == "x" && map[j][k + 1] == "x" && map[j][k + 2] == "x")
      {
        cout << "X won!";
        key == false;
        break;
      }
      if (map[j][k] == "o" && map[j][k + 1] == "o" && map[j][k + 2] == "o")
      {
        cout << "O won!";
        key == false;
        break;
      }
    }

    int j = 0;
    for (int k = 0; k < 3; k++)
    {
      if (map[j][k] == "x" && map[j + 1][k] == "x" && map[j + 2][k] == "x")
      {
        cout << "X won!" << endl;
        key = false;
        break;
      }
      if (map[j][k] == "o" && map[j + 1][k] == "o" && map[j + 2][k] == "o")
      {
        cout << "O won!" << endl;
        key = false;
        break;
      }
    }

    string n[] = {"x", "o"};
    int length = sizeof(n);

    for (int i = 0; i < length; i++)
    {
      if (map[0][0] == n[i] && map[1][1] == n[i] && map[2][2] == n[i])
      {
        cout << "X Won!" << endl;
        key = false;
        break;
      }
      if (map[0][0] == n[i] && map[1][1] == n[i] && map[2][2] == n[i])
      {
        cout << "O Won!" << endl;
        key = false;
        break;
      }
    }

    for (int i = 0; i < length; i++)
    {
      if (map[0][2] == n[i] && map[1][1] == n[i] && map[2][0] == n[i])
      {
        cout << "X Won!" << endl;
        key = false;
        break;
      }
      if (map[0][2] == n[i] && map[1][1] == n[i] && map[2][0] == n[i])
      {
        cout << "O Won!" << endl;
        key = false;
        break;
      }
    }
  }
  return 0;
}