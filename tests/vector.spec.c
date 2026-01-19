#include <assert.h>
#include "vector.h"

static bool float_eq(float a, float b)
{
	constexpr float epsilon = 1e-6f; // 1e-6 = 0.000001
	const float absdiff = a > b ? a - b : b - a;
	if (absdiff <= epsilon) {
		return true;
	}
	return false;
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

int main(void)
{
 	test_vec3_f_add_spec_add_every_element();
	test_vec3_f_sub_spec_subtract_every_element();
	return 0;
}
