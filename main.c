#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./anime/anime.h"

int charLength(const char *string)
{
  int cursor = 0;
  while (1)
  {
    if (string[cursor] == 0)
    {
      return cursor;
    }
    else
    {
      cursor++;
    }
  }
}

int lengthIncludeNull(const char *string)
{
  return charLength(string) + 1;
}

void printHelloWorld()
{
  printf("Hello world\n");
}

int intFilter (
  const int *original, 
  int *replace,
  const int length,
  const bool (*predicate)(int a) 
) {
  int replaceIndex = 0;
  for (int i = 0; i < length; i ++) {
    int value = original[i];
    const bool isSatisfied = predicate(value);
    if (isSatisfied) {
      replace[replaceIndex] = value;
      replaceIndex++;
    }
  }

  return replaceIndex;
}

bool isEven (int number) {
  return number % 2 == 0;
} 

int main(void)
{
  // char *str = "Hello";

  // int len = lengthIncludeNull(str);
  // char copy[len];

  // strcpy(copy, str);

  // printf("%d", lengthIncludeNull(copy));

  // Anime pokemon = {
  //     .description = "Seasonal anime",
  //     .name = "Pokemon gogogogog",
  //     .rating = 10,
  //     .print = printAnime};

  // pokemon.print(&pokemon, printHelloWorld);

  int arraySize = 6;
  int intArray[6] = {1, 2, 3, 4, 5, 6};
  int filtered[6];
  const int replaceSize = intFilter(intArray, filtered , arraySize, isEven);

  for (int i = 0; i < replaceSize; i++) {
    printf("%i\n", filtered[i]);
  }

  return EXIT_SUCCESS;
}
