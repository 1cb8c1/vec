#include "vector.h"

struct vec3_q vec3_q_add(struct vec3_q v1, struct vec3_q v2)
{
	struct vec3_q result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

struct vec3_q vec3_q_sub(struct vec3_q v1, struct vec3_q v2)
{
	struct vec3_q result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

struct vec3_q vec3_q_scale(struct vec3_q v, __float128 s)
{
	struct vec3_q result;
	result.x = v.x * s;
	result.y = v.y * s;
	result.z = v.z * s;
	return result;
}

