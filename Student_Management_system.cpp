#include <iostream>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
class Student
{
  char first_name[30];
  char last_name[30];
  int roll_no;
  int Section;
  char branch[30];

public:
  int insert(Student *p, int n)
  {
    cout << "Enter Roll Number of Student :\n";
    cin >> p[n].roll_no;
    cout << "Enter first name : \n";
    cin >> p[n].first_name;
    cout << "Enter last name :\n";
    cin >> p[n].last_name;
    cout << "Enter the Branch :\n";
    cin >> p[n].branch;
    cout << "Enter the Section\n";
    cin >> p[n].Section;
    n++;
    return n;
  }
  void Search(Student *p, int roll, int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (p[i].roll_no == roll)
      {
        cout << "Roll Number\t Name \t\t Branch\t Section\n";
        cout << p[i].roll_no << "\t" << p[i].first_name << " " << p[i].last_name << "\t" << p[i].branch << "\t" << p[i].Section << "\n";
        break;
      }
    }
    cout << "Record is not found\n";
  }
  void Show()
  {
    cout << "**********Information of Student *************"
         << "\n";
    cout << "Roll Number : " << roll_no << endl;
    cout << "Name of Student : " << first_name << " " << last_name << endl;
    cout << "Branch :" << branch << endl;
    cout << "Section : " << Section << endl;
  }
  int Delete(Student *p, int n, int roll)
  {

    int f = 0;
    int k, j = 0;
    for (j = 0; j < n; j++)
    {
      if (p[j].roll_no == roll)
      {
        f = 1;
        break;
      }
    }
    if (f == 1)
    {
      for (k = j; k < n; k++)
      {
        p[k] = p[k + 1];
      }
      cout << "Record Deleted \n";
      return n - 1;
    }
    else
    {
      cout << "Record not found \n";
      return n;
    }
  }
  int update(Student *p, int roll, int n)
  {
    int i, ch1;
    for (i = 0; i < n; i++)
    {
      if (p[i].roll_no == roll)
      {
        while (1)
        {
          cout << "Options in update :\n";
          cout << "1 for update section \n";
          cout << "2 for update department \n";
          cout << "3 for update both\n";
          cout << "Enter your choice \n";
          cout << "4 to return main Menu\n";
          cin >> ch1;
          switch (ch1)
          {
          case 1:
            cout << "Section:";
            cin >> p[i].Section;
            cout << "Record updated\n";
            cout << "Record updated\n";
          case 2:
            cout << "Department :";
            cin >> p[i].branch;
            cout << "Record updated\n";
            break;
          case 3:
            cout << "Section :";
            cin >> p[i].Section;
            cout << "Department :";
            cin >> p[i].branch;
            cout << "Record updated\n";
            break;
          case 4:
            return n;
          default:
            cout << "!! Wrong Choice!!\n";
            break;
          }
        }
        break;
      }
    }
    if (p[i].roll_no != roll)
    {
      cout << "Record not found\n";
    }
  }
};
int main()
{
  Student o[10];
  int i = 0, ch, j, roll;
  while (1)
  {
    cout << "1. insert\n";
    cout << "2. search\n";
    cout << "3. display\n";
    cout << "4. delete\n";
    cout << "5. update\n";
    cout << "6. exit\n";
    cout << "Enter your choice \n";
    cin >> ch;
    switch (ch)
    {
    case 1:
      i = o[0].insert(o, i);
      break;
    case 2:
      cout << "Enter roll number for search\n";
      cin >> roll;
      o[0].Search(o, roll, i);
      break;
    case 3:
      for (j = 0; j < i; j++)
      {
        o[j].Show();
      }
      break;
    case 4:
      cout << "Enter roll number to delete " << endl;
      cin >> roll;
      i = o[0].Delete(o, i, roll);
      break;
    case 5:
      cout << "Enter roll number for data update\n";
      cin >> roll;
      i = o[0].update(o, roll, i);
      break;
    default:
      cout << "Wrong key\n";
      break;
    case 6:
      exit(0);
    }
  }
  return 0;
}