#include "Numbers.h"
#include <math.h>

float3::float3(float x, float y, float z) : x(x), y(y), z(z) {}
float3::float3() : x(0.0), y(0.0), z(0.0) {}

float float3::length()
{
  return sqrt(x * x + y * y + z * z);
}

float3 float3::operator*(float scalar) const
{
  return float3(scalar * x, scalar * y, scalar * z);
}

float3 float3::operator+(float3 &rhs) const
{
  return float3(x + rhs.x, y + rhs.y, z + rhs.z);
}

float3 float3::rotateZ(float angle) 
{
  float cosine = cos(angle);
  float sine = sin(angle);

  // matrix multiplication with rotation matrix for Z-axis
  // [
  //  [cos, -sin, 0 ],
  //  [sin, cos,  0 ],
  //  [0,   0,    1 ],
  // ]
  return float3(
    x * cosine + y * -sine,
    x * sine + y * cosine,  
    z
  );
}

float4::float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
float4::float4() : x(0.0), y(0.0), z(0.0), w(0.0) {}

float float4::length()
{
  return sqrt(x * x + y * y + z * z);
}

float3 float4::asFloat3() {
  return float3(x,y,z);
}