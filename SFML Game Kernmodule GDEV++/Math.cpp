#include "Math.h"
#include <random>

float Math::Abs(float value)
{
    if (value >= 0) return value;
    else return -value;
}

float Math::Clamp(float value, float minValue, float maxValue)
{
    if (value < minValue) value = minValue;
    else if (value > maxValue) value = maxValue;
    return value;
}

float Math::randomRange(float min, float max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(min, max);

    return dist(mt);
}


