#ifndef VECTOR_H
#define VECTOR_H

struct vec3_q {
    __float128 x;
    __float128 y;
    __float128 z;
};

struct vec3_q vec3_q_add(struct vec3_q v1, struct vec3_q v2);
struct vec3_q vec3_q_sub(struct vec3_q v1, struct vec3_q v2);
struct vec3_q vec3_q_scale(struct vec3_q v, __float128 s);
 __float128   vec3_q_dot(struct vec3_q v1, struct vec3_q v2);
struct vec3_q vec3_q_mul(struct vec3_q v1, struct vec3_q v2);
struct vec3_q vec3_q_cross(struct vec3_q v1, struct vec3_q v2);
__float128    vec3_q_dist(struct vec3_q v1, struct vec3_q v2);

#endif // VECTOR_H
