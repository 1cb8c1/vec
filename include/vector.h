#ifndef VECTOR_H
#define VECTOR_H

struct vec3_f {
    float x;
    float y;
    float z;
};

struct vec3_f 	vec3_f_add(struct vec3_f v1, struct vec3_f v2);
struct vec3_f 	vec3_f_sub(struct vec3_f v1, struct vec3_f v2);
struct vec3_f 	vec3_f_scale(struct vec3_f v, float s);
float  		vec3_f_dot(struct vec3_f v1, struct vec3_f v2);
struct vec3_f 	vec3_f_mul(struct vec3_f v1, struct vec3_f v2);
struct vec3_f 	vec3_f_cross(struct vec3_f v1, struct vec3_f v2);
float  		vec3_f_dist(struct vec3_f v1, struct vec3_f v2);

#endif // VECTOR_H
