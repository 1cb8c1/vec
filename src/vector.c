#include "vector.h"
#include <quadmath.h>

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

__float128 vec3_q_dot(struct vec3_q v1, struct vec3_q v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct vec3_q vec3_q_mul(struct vec3_q v1, struct vec3_q v2)
{
	struct vec3_q result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return result;
}

struct vec3_q vec3_q_cross(struct vec3_q v1, struct vec3_q v2)
{
	struct vec3_q result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

__float128 vec3_q_dist(struct vec3_q v1, struct vec3_q v2)
{
	__float128 dx = v1.x - v2.x;
	__float128 dy = v1.y - v2.y;
	__float128 dz = v1.z - v2.z;
	return sqrtq(dx * dx + dy * dy + dz * dz);
}
