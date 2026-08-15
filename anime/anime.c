#include <stdio.h>
#include "anime.h"

void printAnime(
    struct Anime *anime,
    void (*printSomethingMore)(void)
)
{
    printSomethingMore();

    printf("name: %s\n", anime->name);
    printf("rating: %d\n", anime->rating);
    printf("description: %s\n", anime->description);
}