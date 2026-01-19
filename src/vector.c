#include "vector.h"
#include <math.h>

struct vec3_f vec3_f_add(struct vec3_f v1, struct vec3_f v2)
{
	struct vec3_f result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

struct vec3_f vec3_f_sub(struct vec3_f v1, struct vec3_f v2)
{
	struct vec3_f result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

struct vec3_f vec3_f_scale(struct vec3_f v, float s)
{
	struct vec3_f result;
	result.x = v.x * s;
	result.y = v.y * s;
	result.z = v.z * s;
	return result;
}

float vec3_f_dot(struct vec3_f v1, struct vec3_f v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct vec3_f vec3_f_mul(struct vec3_f v1, struct vec3_f v2)
{
	struct vec3_f result;
	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return result;
}

struct vec3_f vec3_f_cross(struct vec3_f v1, struct vec3_f v2)
{
	struct vec3_f result;
	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return result;
}

float vec3_f_dist(struct vec3_f v1, struct vec3_f v2)
{
	float dx = v1.x - v2.x;
	float dy = v1.y - v2.y;
	float dz = v1.z - v2.z;
	return sqrtf(dx * dx + dy * dy + dz * dz);
}
