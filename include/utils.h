#ifndef UTILS_H_
#define UTILS_H_

void drawCoord(int sizeX, int sizeY, SDL_Renderer *renderer);
void convertToCenter(int x, int y, int *newX, int *newY);
void draw8Points(int x, int y, SDL_Renderer *renderer, int sizeX, int sizeY);
void getArgs(char *argv[], int *r);

#endif