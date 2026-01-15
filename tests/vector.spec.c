#include <assert.h>
#include <quadmath.h>
#include "vector.h"

static bool __float128_eq(__float128 a, __float128 b)
{
	constexpr __float128 epsilon = FLT128_EPSILON;
	const __float128 absdiff = fabsq(a - b);
	if (absdiff <= epsilon) {
		return true;
	}
	return false;
}


static void test_vec3_q_add_spec_add_every_element(void)
{
	struct vec3_q a = {1.0Q, 2.0Q, 3.0Q};
	struct vec3_q b = {4.0Q, 5.0Q, 6.0Q};
	struct vec3_q result = vec3_q_add(a, b);
	assert(__float128_eq(result.x, 5.0Q));
	assert(__float128_eq(result.y, 7.0Q));
	assert(__float128_eq(result.z, 9.0Q));
}

static void test_vec3_q_sub_spec_subtract_every_element(void)
{
	struct vec3_q a = {5.0Q, 7.0Q, 9.0Q};
	struct vec3_q b = {4.0Q, 5.0Q, 6.0Q};
	struct vec3_q result = vec3_q_sub(a, b);
	assert(__float128_eq(result.x, 1.0Q));
	assert(__float128_eq(result.y, 2.0Q));
	assert(__float128_eq(result.z, 3.0Q));
}

int main(void)
{
 	test_vec3_q_add_spec_add_every_element();
	test_vec3_q_sub_spec_subtract_every_element();
	return EXIT_SUCCESS;
}
