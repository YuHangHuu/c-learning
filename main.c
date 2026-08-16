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

int intFilter(
    const int *original,
    int *replace,
    const int length,
    const bool (*predicate)(int a))
{
  int replaceIndex = 0;
  for (int i = 0; i < length; i++)
  {
    int value = original[i];
    const bool isSatisfied = predicate(value);
    if (isSatisfied)
    {
      replace[replaceIndex] = value;
      replaceIndex++;
    }
  }

  return replaceIndex;
}

bool isEven(int number)
{
  return number % 2 == 0;
}

void printFile(FILE *file)
{
  int character;
  while (character = fgetc(file) != EOF)
  {
    printf("%c", character);
  }
}

void printLine(const int lineNumber, FILE *file)
{
  const int maxLineSize = 1024;
  char line[maxLineSize];
  int lineCount = 0;
  while ((fgets(line, maxLineSize, file)) != NULL)
  {
    lineCount++;
    if (lineCount == lineNumber)
    {
      printf("%s", line);
    }
  }
}

void printFormattedFile(FILE *file)
{
  char name[256];
  float weight;
  int height;
  while (fscanf(file, " %255[^;];%f;%i", name, &weight, &height) == 3)
  {
    printf("Name: %s\n", name);
    printf("Height: %i\n", height);
    printf("Weight: %f\n", weight);
    printf("\n");
  }
}

int main(void)
{
  // STRING STUFF
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

  // ARRAY STUFF

  // int arraySize = 6;
  // int intArray[6] = {1, 2, 3, 4, 5, 6};
  // int filtered[6];
  // const int replaceSize = intFilter(intArray, filtered , arraySize, isEven);

  // for (int i = 0; i < replaceSize; i++) {
  //   printf("%i\n", filtered[i]);
  // }

  // FILE STUFF

  FILE *file;

  // file = fopen("lorum-ipsum.txt", "w");

  // if (file == NULL)
  // {
  //   printf("File could not be found");
  //   return EXIT_FAILURE;
  // }

  // // printFile(filePointer);
  // // printLine(3, filePointer);

  // printFormattedFile(file);

  // file = fopen("example-output.text", "w");

  // const int intVar = 123;

  // fputc('1', file);
  // fputc('\n', file);
  // fputs("Hello world again\n", file);
  // fprintf(file, "Another new line with var: %i", intVar);

  // file = fopen("example-output.bin", "wb");
  // unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};

  // fwrite(bytes, sizeof(char), 6, file);

  // fclose(file);

  // file = fopen("example-output.bin", "rb");

  // unsigned char data[6] = {};

  // const int readSize = 4;
  // fread(&data, sizeof(char), readSize, file);

  // for (int i = 0; i < readSize; i++)
  // {
  //   printf("%d\n", data[i]);
  // }

  // fclose(file);

  return EXIT_SUCCESS;
}
