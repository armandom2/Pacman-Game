#include "Random.hpp"

int generateRandom(int max){ // CREATES RANDOM GENERATOR
    int randomNumber = rand();
    float random = (randomNumber % max) + 0.5;
    int randnum = random;
    return randnum;
}

