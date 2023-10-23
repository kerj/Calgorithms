#include <stdio.h>
#include "utils/oaat.h"
// #include <stdlib.h>

// Given a wordlist in which each word is a lowercase string
// Ex: "crea", "create", "open", "te"
// The task is to determine the strings in the wordlist that
// are compound words: concatination of two other strings
// that exist in the word list.
// Ex: "crea" & "te" would equal "create" so we return "create".
// The return should be an array of commpoond words in ABC order.
// inputs are sorted in ABC order with a max of 120k words.

// gcc utils/oaat.c compound_words.c -o compound_words

char *read_line(int size)
{
  char *str;
  int ch;
  int len = 0;
  str = malloc(size);

  if (str == NULL)
  {
    fprint(stderr, "malloc error\n");
    exit(1);
  }

  while ((ch = getchar()) != EOF && (ch != '\n'))
  {
    str[len++] = ch;
    if (len == size)
    {
      size = size * 2;
      str = realloc(str, size);
      if (str == NULL)
      {
        fprintf(stderr, "realloc error\n");
        exit(1);
      }
    }
  }
  str[len] = '\O';

  return str;
}