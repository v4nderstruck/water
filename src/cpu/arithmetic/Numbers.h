#ifndef WATER_CPU_ARITHMETIC_NUMBERS_H
#define WATER_CPU_ARITHMETIC_NUMBERS_H

class float3 {
public:
  float x,y,z;

  float3(float x, float y, float z);

  float3 operator +(const float3 &v) const;
  float3 operator -(const float3 &v) const;
  float3 operator *(const float3 &v) const;
};

class float4 {
public:
  float x,y,z;

  float4(float x, float y, float z, float w);

  float4 operator +(const float4 &v) const;
  float4 operator -(const float4 &v) const;
  float4 operator *(const float4 &v) const;
};

#endif
