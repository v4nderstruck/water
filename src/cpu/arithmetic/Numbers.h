#ifndef WATER_CPU_ARITHMETIC_NUMBERS_H
#define WATER_CPU_ARITHMETIC_NUMBERS_H

class float3
{
public:
  float x, y, z;
  float3();
  float3(float x, float y, float z);
  float length();
  float3 rotateZ(float angle);
  float3 operator *(float scalar) const;
  float3 operator +(float3 &rhs) const;
};

class float4
{
public:
  float x, y, z, w;
  float4();
  float3 asFloat3();
  float4(float x, float y, float z, float w);
  // will only consider x,y,z
  float length();

};

#endif
