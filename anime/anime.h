// # pragma once
#ifndef ANIME_H
#define ANIME_H

// typedef struct Anime Anime;

typedef struct Anime
{
  const char *name;
  int rating;
  const char *description;

  void (*print)(
      struct Anime *,
      void (*)(void));
} Anime;

void printAnime(
    struct Anime *anime,
    void (*printSomethingMore)(void)
);

#endif