#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;
    float x_acc;
    float y_acc;
} vector;

void vector_init(vector *vec, float x, float y);
vector vector_add(vector vec1, vector vec2);
vector vector_subtract(vector vec1, vector vec2);
vector vector_multiply(vector vec, float scalar);
vector vector_divide(vector vec, float scalar);
vector vector_negate(vector vec);

#endif