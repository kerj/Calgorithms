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


int main(void) {
  int a[5] = { 1,2,3,1,5 };
  check_flakes(a, 5);
  return 0;
}
// for now, Just want to check that we correctly find a duplicate in an array
void check_flakes(int snowflakes[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++) {
      if (snowflakes[i] == snowflakes[j]) {
        printf("Duplicates found \n");
        return;

      }
    }
  }
  printf("No duplicates \n");
}