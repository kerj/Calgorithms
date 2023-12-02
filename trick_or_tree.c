// The task is to navigate through a binary node tree where each node contains up to a double-digit number or nothing.
// The nodes represent a house and the numbers contained in them represent the amount of candy they hand out.
// nodes without numbers represent intersections and each edge between nodes represent a street.
// Begining at the top of the tree, the goal is to collect candy from all houses in the fewest amount
// of streets walked. As soon as all candy has been collected you may end the count.
// return the amount of candy as well as the minimum number of streets traversed to achieve this.

// To compile and test use the following:
// gcc trick_or_tree.c -o trick_or_tree
// ./trick_or_tree < trick_or_tree_input.txt
// OR ~ with debugging
// gcc -g -o trick_or_tree trick_or_tree.c
// gdb ./trick_or_tree
// run < trick_or_tree_input.txt
// bt -> to check back trace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int candy;
  struct node *left, *right;
} node;

node *new_house(int candy)
{
  node *house = malloc(sizeof(node));
  if (house == NULL)
  {
    fprintf(stderr, "malloc error/n");
    exit(EXIT_FAILURE);
  }
  house->candy = candy;
  house->left = NULL;
  house->right = NULL;
  return house;
}

node *new_intersection(node *left, node *right)
{
  node *intersection = malloc(sizeof(node));
  if (intersection == NULL)
  {
    fprintf(stderr, "malloc error/n");
    exit(EXIT_FAILURE);
  }
  intersection->left = left;
  intersection->right = right;

  return intersection;
}

int tree_candy(node *tree)
{
  if (!tree->left && !tree->right)
  {
    return tree->candy;
  }
  return tree_candy(tree->left) + tree_candy(tree->right);
}

int tree_streets(node *tree)
{
  if (!tree->left && !tree->right)
  {
    return 0;
  }
  // add 4 since we split the tree in half; navigate left and right then back
  return tree_streets(tree->left) + tree_streets(tree->right) + 4;
}

int max(int v1, int v2)
{
  if (v1 > v2)
    return v1;
  else
    return v2;
}

int tree_height(node *tree)
{
  if (!tree->left && !tree->right)
    return 0;
  return 1 + max(tree_height(tree->left), tree_height(tree->right));
}

void tree_solve(node *tree)
{
  int candy = tree_candy(tree);
  int height = tree_height(tree);
  // subtract height since problem doesn't require returning to root
  int num_streets = tree_streets(tree) - height;

  printf("%d %d\n", num_streets, candy);
}

node *read_tree_helper(char *line, int *pos)
{
  node *tree;
  tree = malloc(sizeof(node));
  if (tree == NULL)
  {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }
  if (line[*pos] == '(')
  {
    (*pos)++;
    tree->left = read_tree_helper(line, pos);
    (*pos)++;
    tree->right = read_tree_helper(line, pos);
    (*pos)++;
    return tree;
  }
  else
  {
    tree->left = NULL;
    tree->right = NULL;
    tree->candy = line[*pos] - '0';
    (*pos)++;
    if (line[*pos] != ')' && line[*pos] != ' ' && line[*pos] != '\0')
    {
      tree->candy = tree->candy * 10 + line[*pos] - '0';
      (*pos)++;
    }
    return tree;
  }
}

node *read_tree(char *line)
{
  int pos = 0;
  return read_tree_helper(line, &pos);
}

#define SIZE 255
#define TEST_CASES 2

int main(void)
{
  int i;
  char line[SIZE + 1];
  node *tree;

  for (i = 0; i < TEST_CASES; i++)
  {
    fgets(line, SIZE, stdin);
    tree = read_tree(line);
    tree_solve(tree);
  }
  return 0;
}
