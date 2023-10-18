#include <stdio.h>
#include <stdlib.h>

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

#define SIZE 100000
typedef struct snowflake_node
{
  int snowflake[6];
  struct snowflake_node *next;
} snowflake_node;

int are_same(int s1[], int s2[]);
void check_flakes(snowflake_node *snowflakes[]);
int check_right(int s1[], int s2[], int start);
int check_left(int s1[], int s2[], int start);
// create a sum of all arm lengths, modolo operator to keep memory size to a minimum needed for the problem
int sum(int snowflake[])
{
  return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

int main(void)
{
  static snowflake_node *snowflakes[SIZE] = {NULL};
  snowflake_node *snow;
  int n, i, j, snowflake_sum;
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    snow = malloc(sizeof(snowflake_node));
    if (snow == NULL)
    {
      fprintf(stderr, "malloc error\n");
      exit(1);
    }
    // create single-linked list
    for (j = 0; j < 6; j++)
      scanf("%d", &snow->snowflake[j]);
    snowflake_sum = sum(snow->snowflake);
    snow->next = snowflakes[snowflake_sum];
    snowflakes[snowflake_sum] = snow;
    free(snow);
  }
  check_flakes(snowflakes);

  return 0;
}
// go through the linked lists for sum of snowflakes lengths % SIZE
// ex: 1,1,1,1,1,7 and 2,2,2,2,2,2 would get compared but we reduce the # of comparisions greatly
void check_flakes(snowflake_node *snowflakes[])
{
  snowflake_node *node1, *node2;
  int i;
  for (i = 0; i < SIZE; i++)
  {
    node1 = snowflakes[i];
    while (node1 != NULL)
    {
      node2 = node1->next;
      while (node2 != NULL)
      {
        if (are_same(node1->snowflake, node2->snowflake))
        {
          printf("Twin snowflakes found.\n");
          return;
        }
        node2 = node2->next;
      }
      node1 = node1->next;
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
