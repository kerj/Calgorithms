#include <stdio.h>

// Given a collection of snowflakes, determine whether any
// of the snowflakes in the collection are identical.
// A snowflake is represented by six intergers, where each interger gives the arm length of the snowflake.
// for example: 3, 9, 15, 2, 1, 10
// Snowflakes can have repeated intergers and here are some examples of snowflakes that are identical:

// S1 = 1,2,3,4,5,6
// S2 = 1,2,3,4,5,6

// S1 = 1,2,3,4,5,6
// S2 = 3,4,5,6,1,2

// S1 = 1,2,3,4,5,6
// S2 = 3,2,1,6,5,4

// the inputs will be n, the number of snowflakes between 1 - 100,000
// and an array of snowflakes whose arm lengths are between 0 and 10,000,000.
// The output should be "Duplicates found" if a duplicate snowfake exists or "No dupicates" if one does not.

int are_same(int s1[], int s2[]);
void check_flakes(int snowflakes[][6], int n);
int check_right(int s1[], int s2[], int start);
int check_left(int s1[], int s2[], int start);

    int main(void)
{
  static int snowflakes[100000][6];
  int n,i,j;
  scanf("%d", &n);

  for (i = 0; i < n; i++) 
    for (j=0; j < 6; j++) 
      scanf("%d", &snowflakes[i][j]);
  check_flakes(snowflakes, n);
  return 0;
}

void check_flakes(int snowflakes[][6], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (are_same(snowflakes[i],snowflakes[j]))
      {
        printf("Twin snowflakes found.\n");
        return;
      }
    }
  }
  printf("No two snowflakes are alike.\n");
}

int check_right(int s1[], int s2[], int start)
{
  int offset, index_s2;
  for (offset = 0; offset < 6; offset++)
  {
    index_s2 = offset + start;
    if (index_s2 >= 6)
    {
      index_s2 = index_s2 - 6;
    }
    if (s1[offset] != s2[index_s2])
    {
      return 0;
    }
  }
  return 1;
}

int check_left(int s1[], int s2[], int start)
{
  int offset, index_s2;
  for (offset = 0; offset < 6; offset++)
  {
    index_s2 = start - offset;
    if (index_s2 < 0)
    {
      index_s2 = index_s2 + 6;
    }
    if (s1[offset] != s2[index_s2])
    {
      return 0;
    }
  }
  return 1;
}

int are_same(int s1[], int s2[])
{
  int start;
  for (start = 0; start < 6; start++)
  {
    if (check_right(s1, s2, start))
    {
      return 1;
    }
    if (check_left(s1, s2, start))
    {
      return 1;
    }
  }
  return 0;
}
