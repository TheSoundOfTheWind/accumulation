#include <stdio.h>
#include <string.h>
#include "golfer.h"

Golfer::Golfer()
{
  printf("Golfer()\n");
  fullname = new char[0];
  fullname[0] = '\0';
  games  = 0;
  scores = nullptr;
}

Golfer::Golfer(const char * name, int g)
{
  printf("Golfer(const char * name, int g = 0)\n");
  fullname = new char[strlen(name)+1];
  strcpy(fullname, name);
  fullname[strlen(name)] = '\0';
  games = g;
  scores = nullptr;
}
  // creates empty dynamic array of g elements if g > 0
Golfer::Golfer(const Golfer & g)
{
  printf("Golfer(const Golfer & g)\n");
  fullname = new char[strlen(g.fullname)+1];
  fullname[strlen(g.fullname)] = '\0';
  games = g.games;
  scores = g.scores;
}

Golfer::~Golfer()
{
  printf("~Golfer()\n");
  delete [] fullname;
}

Golfer & Golfer::operator=(const Golfer & g)
{
  printf("Golfer::operator=(const Golfer &)\n");
  delete [] fullname;
  fullname = new char[strlen(g.fullname)+1];
  strcpy(fullname, g.fullname);
  fullname[strlen(g.fullname)] = '\0';
  games = g.games;
  scores = g.scores;
  return *this;
}
