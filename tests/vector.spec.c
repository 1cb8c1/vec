#include <assert.h>
#include "vector.h"
#include "bool.h"

static int float_eq(float a, float b)
{
	const float epsilon = 1e-6f; /* 1e-6 = 0.000001 */
	const float absdiff = a > b ? a - b : b - a;
	if (absdiff <= epsilon) {
		return TRUE;
	}
	return FALSE;
}

static void test_vec3_f_add_spec_add_every_element(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	struct vec3_f result = vec3_f_add(a, b);
	assert(float_eq(result.x, 5.0f));
	assert(float_eq(result.y, 7.0f));
	assert(float_eq(result.z, 9.0f));
}

static void test_vec3_f_sub_spec_subtract_every_element(void)
{
	struct vec3_f a = {5.0f, 7.0f, 9.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	struct vec3_f result = vec3_f_sub(a, b);
	assert(float_eq(result.x, 1.0f));
	assert(float_eq(result.y, 2.0f));
	assert(float_eq(result.z, 3.0f));
}

static void test_vec3_f_scale_spec_scale_every_element(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	float scalar = 2.0f;
	struct vec3_f result = vec3_f_scale(a, scalar);
	assert(float_eq(result.x, 2.0f));
	assert(float_eq(result.y, 4.0f));
	assert(float_eq(result.z, 6.0f));
}

static void test_vec3_f_dot_spec_compute_dot_product(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	float result = vec3_f_dot(a, b);
	assert(float_eq(result, 32.0f)); 	/* 1*4 + 2*5 + 3*6 = 32 */
}

static void test_vec3_f_mul_spec_multiply_every_element(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	struct vec3_f result = vec3_f_mul(a, b);
	assert(float_eq(result.x, 4.0f)); 	/* 1*4 = 4  */
	assert(float_eq(result.y, 10.0f)); 	/* 2*5 = 10 */
	assert(float_eq(result.z, 18.0f)); 	/* 3*6 = 18 */
}

static void test_vec3_f_cross_spec_compute_cross_product(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	struct vec3_f result = vec3_f_cross(a, b);
	assert(float_eq(result.x, -3.0f)); 	/* 2*6 - 3*5 = -3 */
	assert(float_eq(result.y, 6.0f));  	/* 3*4 - 1*6 = 6  */
	assert(float_eq(result.z, -3.0f)); 	/* 1*5 - 2*4 = -3 */
}

static void test_vec3_f_dist_spec_compute_distance_between_points(void)
{
	struct vec3_f a = {1.0f, 2.0f, 3.0f};
	struct vec3_f b = {4.0f, 5.0f, 6.0f};
	float result = vec3_f_dist(a, b);
	/* sqrt((4-1)^2 + (5-2)^2 + (6-3)^2) = sqrt(27) = 5.196152 */
	assert(float_eq(result, 5.196152f));
}

int main(void)
{
 	test_vec3_f_add_spec_add_every_element();
	test_vec3_f_sub_spec_subtract_every_element();
	test_vec3_f_scale_spec_scale_every_element();
	test_vec3_f_dot_spec_compute_dot_product();
	test_vec3_f_mul_spec_multiply_every_element();
	test_vec3_f_cross_spec_compute_cross_product();
	test_vec3_f_dist_spec_compute_distance_between_points();
	return 0;
}
