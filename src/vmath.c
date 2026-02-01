#include "vmath.h"

float abs_f(float x)
{
	return (x < 0.0f) ? -x : x;
}


float sqrt_f_positive_unsafe(float x)
{
	float guess = (x > 1.0f) ? x : 1.0f;
	float prev_guess;

	do {
		prev_guess = guess;
		guess = 0.5f * (prev_guess + x / prev_guess);
	} while (abs_f(prev_guess - guess) > EPSILON_F);

	return guess;
}
