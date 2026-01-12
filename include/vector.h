#ifndef VECTOR_H
#define VECTOR_H

struct vec3_q {
    __float128 x;
    __float128 y;
    __float128 z;
};

struct vec3_q add(struct vec3_q v1, struct vec3_q v2);
struct vec3_q sub(struct vec3_q v1, struct vec3_q v2);
struct vec3_q scale(struct vec3_q v, __float128 s);
 __float128   dot(struct vec3_q v1, struct vec3_q v2);
struct vec3_q mul(struct vec3_q v1, struct vec3_q v2);
struct vec3_q cross(struct vec3_q v1, struct vec3_q v2);

#endif // VECTOR_H
