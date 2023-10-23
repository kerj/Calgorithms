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
