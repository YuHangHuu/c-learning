#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./anime/anime.h"

typedef int number;

int stringLength(char *string)
{
  // int cursor = 0;
  // while (1)
  // {
  //   if (string[cursor] == 0)
  //   {
  //     return cursor;
  //   }
  //   else
  //   {
  //     cursor++;
  //   }
  // }

  char *cursor = string;
  while (*cursor != '\0')
  {
    cursor++;
  }

  return cursor - string;
}

int lengthIncludeNull(char *string)
{
  return stringLength(string) + 1;
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

void reverseString(
    char *original,
    char *replacement,
    size_t buffer_size)
{
  const int size = stringLength(original);
  if (buffer_size > (size + 1))
  {
    return;
  }

  for (int i = 0; i < size; i++)
  {
    const int replacementIndex = size - 1 - i;
    replacement[i] = original[replacementIndex];
  }
  replacement[size] = '\0';
}

void copyString(
    char *original,
    char *copy,
    size_t buffer_size)
{
  const int size = stringLength(original) + 1;
  if (buffer_size > (size + 1))
  {
    return;
  }

  for (int i = 0; i < size; i++)
  {
    copy[i] = original[i];
  }
}

void *genericCopy(
    void *destination,
    const void *source,
    size_t byte_count)
{

  const unsigned char *sourcePointer = source;
  unsigned char *destinationPointer = destination;

  // for (int i = 0; i < byte_count; i++)
  // {
  //   *destinationPointer++ = *sourcePointer++;

  //   *destinationPointer = *sourcePointer;
  //   sourcePointer++;
  //   destinationPointer++;

  //   destinationPointer[i] = sourcePointer[i];
  // }

  while (byte_count--)
  {
    *destinationPointer++ = *sourcePointer++;

    // *destinationPointer = *sourcePointer;
    // sourcePointer++;
    // destinationPointer++;
  }

  return destination;
}

bool genericByteEquals(
    const void *a,
    size_t a_byte_count,
    const void *b,
    size_t b_byte_count)
{
  if (a_byte_count != b_byte_count)
  {
    return false;
  }

  const unsigned char *ap = a;
  const unsigned char *bp = b;

  while (a_byte_count--)
  {
    if (*ap++ != *bp++)
    {
      return false;
    }
    // if (*ap++ != *bp++) {
    //   return false;
    // }
  }

  // for (size_t i = 0; i < a_byte_count; i++) {
  //   if (ap[i] != bp[i]) {
  //     return false;
  //   }
  // }

  return true;
}

char *toBoolString(int value)
{
  return value == 0 ? "false" : "true";
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

  // FILE *file;

  // file = fopen("lorum-ipsum.txt", "w");

  // if (file == NULL)
  // {
  //   printf("File could not be found");
  //   return EXIT_FAILURE;
  // }

  // // printFile(filePointer);
  // // printLine(3, filePointer);

  // printFormattedFile(file);

  // file = fopen("example-output.txt", "w");

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

  /////////// Pointers II: Arithmetic ///////

  // const int intArray[4] = {1, 2, 3, 4};
  // const char helloWorld[] = "Hello world";
  // const int size = sizeof(charArray) / sizeof(char);

  // // for (int i = 0; i < size; i++) {
  // //   printf("%c\n",  *(charArray + i));
  // // }

  // const int charArraySize = sizeof(charArray);
  // char reversed[size];

  // reverseString(charArray, reversed, sizeof reversed);
  // printf("%s", reversed);

  // printf("String length : %i", stringLength(charArray));

  // char copiedString[sizeof charArray];
  // copyString(charArray, copiedString, sizeof charArray);

  // printf("%s", boolString(&charArray == &copiedString));

  // char copy[sizeof helloWorld];
  // genericCopy(copy, helloWorld, sizeof helloWorld);

  // printf("IsSameMemoryAddress: %s\n", toBoolString(&copy == &helloWorld));
  // const bool isEqual = genericEquals(helloWorld, sizeof helloWorld, copy, sizeof copy);
  // printf("IsSameValue: %s\n", toBoolString(isEqual));

  // const int intArray[] = {1, 2, 3, 4};
  // int copy[sizeof intArray / sizeof(intArray[0])];
  // genericCopy(copy, intArray, sizeof intArray);

  // printf("IsSameMemoryAddress: %s\n", toBoolString(&copy[0] == &intArray[0]));
  // const bool isEqual = genericByteEquals(intArray, sizeof intArray, copy, sizeof copy);
  // printf("IsSameValue: %s\n", toBoolString(isEqual));

  //////////////////////////////// Manual Memory Allocation /////////////

  // const int arraySize = 10;
  // int *memory = malloc(sizeof(int) * arraySize);
  // if (memory == NULL)
  // {
  //   return 1;
  // }
  // memset(memory, 0, sizeof(int) * arraySize);
  // // for (int i = 0; i < arraySize; i++)
  // // {
  // //   printf("%i\n", memory[i]);
  // // }
  // free(memory);

  // int *arrayMemory = calloc(arraySize, sizeof(int));
  // //   for (int i = 0; i < arraySize; i++)
  // // {
  // //   printf("%i\n", arrayMemory[i]);
  // // }
  // free(arrayMemory);

  // size_t memSize = sizeof(int) * arraySize;
  // int *pIntArray = calloc(arraySize, sizeof(int));
  // if (pIntArray == NULL)
  // {
  //   return 1;
  // }
  // for (int i = 0; i < arraySize; i++)
  // {
  //   pIntArray[i] = i + 1;
  // }

  // int *pNewIncrease = realloc(pIntArray, memSize * 2);
  // if (pNewIncrease == NULL)
  // {
  //   free(pIntArray);
  //   return 1;
  // }
  // pIntArray = pNewIncrease;

  // int *pNewReduction = realloc(pIntArray, memSize / 2);
  // if (pNewReduction == NULL)
  // {
  //   free(pIntArray);
  //   return 1;
  // }
  // pIntArray = pNewReduction;

  // for (int i = 0; i < arraySize; i++)
  // {
  //   printf("%i\n", pIntArray[i]);
  // }

  // free(pIntArray);

  // char *alterNativeMalloc = realloc(NULL, sizeof(char) * 100);
  // free(alterNativeMalloc);

  return EXIT_SUCCESS;
}
