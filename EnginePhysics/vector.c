#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

/**
 * A basic initialization function to give a vector x and y coordinates
 */
void vector_init(vector *vec, float x, float y) {
    // Position init
    vec->x_pos = x;
    vec->y_pos = y;
    // Velocity init
    vec->x_vel = 0;
    vec->y_vel = 0;
    // Acceleration init
    vec->x_acc = 0;
    vec->y_acc= 0;
}

/**
 * A basic addition function to add two vectors together and return a new vector
 */
vector vector_add(vector vec1, vector vec2) {
    vector new_vec;
    new_vec.x_pos = vec1.x_pos + vec2.x_pos;
    new_vec.y_pos = vec1.y_pos + vec2.y_pos;
    return new_vec;
}

/**
 * A basic subtraction function to subtract two vectors together and return a new vector
 */
vector vector_subtract(vector vec1, vector vec2) {
    vector new_vec;
    new_vec.x_pos = vec1.x_pos - vec2.x_pos;
    new_vec.y_pos = vec1.y_pos - vec2.y_pos;
    return new_vec;
}
/**
 * A basic multiplication function to multiply two vectors together and return a new vector
 */
vector vector_multiply(vector vec, float scalar) {
    vector new_vec;
    new_vec.x_pos = vec.x_pos * scalar;
    new_vec.y_pos = vec.y_pos * scalar;
    return new_vec;
}
/**
 * A basic division function to divide two vectors together and return a new vector
 */
vector vector_divide(vector vec, float scalar) {
    vector new_vec;
    new_vec.x_pos = vec.x_pos / scalar;
    new_vec.y_pos = vec.y_pos / scalar;
    return new_vec;
}

/**
 * A basic negation function to negate a vector and return a new vector
 */
vector vector_negate(vector vec) {
    return vector_multiply(vec, -1);
}