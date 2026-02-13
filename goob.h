#ifndef GOOB_H
#define GOOB_H

#define LAYER_C 3

typedef struct {
    int inpSize;
    int outSize;
    float weights[][];
} Layer;

typedef struct {
    Layer layers[LAYER_C];
    Vector2 pos;
    Vector2 direction;
    int speed;
    int radius;
    Color c;
    int foodCount;
} Goob;

Goob initGoob(int layerSizes[LAYER_C], Vector2 pos, int speed, int radius, Color c);

void drawGoob(Goob g);
void moveGoob(Goob g);
void eatFood(Goob g, Vector2 foodPos[]);

void copyGoob(Goob parent, Goob child, int mutationChance, float mutationStreangth);

#endif