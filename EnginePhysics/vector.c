#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

/**
 * A basic initialization function to give a vector x and y coordinates
 */
void vector_init(vector *vec, float x, float y) {
    vec->x = x;
    vec->y = y;
}

/**
 * A basic addition function to add two vectors together and return a new vector pointer
 */
vector vector_add(vector vec1, vector vec2) {
    vector new_vec;
    new_vec.x = vec1.x + vec2.x;
    new_vec.y = vec1.y + vec2.y;
    return new_vec;
}

/**
 * A basic subtraction function to add two vectors together and return a new vector pointer
 */
vector vector_subtract(vector vec1, vector vec2) {
    vector new_vec;
    new_vec.x = vec1.x - vec2.x;
    new_vec.y = vec1.y - vec2.y;
    return new_vec;
}
/**
 * A basic multiplication function to add two vectors together and return a new vector pointer
 */
vector vector_multiply(vector vec, float scalar) {
    vector new_vec;
    new_vec.x = vec.x * scalar;
    new_vec.y = vec.y * scalar;
    return new_vec;
}
/**
 * A basic division function to add two vectors together and return a new vector pointer
 */
vector vector_divide(vector vec, float scalar) {
    vector new_vec;
    new_vec.x = vec.x / scalar;
    new_vec.y = vec.y / scalar;
    return new_vec;
}

vector vector_negate(vector vec) {
    return vector_multiply(vec, -1);
}