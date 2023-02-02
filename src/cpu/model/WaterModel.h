#ifndef WATER_CPU_MODEL_WATER_MODEL_H
#define WATER_CPU_MODEL_WATER_MODEL_H

#include <math.h>
#include <memory>
#include <vector>
#include <array>
#include "arithmetic/Numbers.h"

enum class WaterMolecularStructure {OXYGEN, HYDROGEN_1, HYDROGEN_2};

class WaterMolecule {
public:
  // will put the molecule together in the right place
  WaterMolecule(float3 oxygen_position, float3 rotation);
  std::array<float4, 3> getPointCharges();
private:
  // [0] oxygen atom + charge 
  // [1] hydrogen atom + charge
  // [2] hydrogen atom + charge
  std::array<float4, 3> pointCharges();
};

class WaterModelSim {
public:
  WaterModelSim(const std::vector<float3> init_space);

  void update_sim(float ticks);

  const std::weak_ptr<std::vector<float3>> getPos();

private: 
  float3 computeMoleculeAccel(float3 accel, float4 chargeThis, float4 chargeOther); 
  std::vector<float4> pointCharges;         // position and charge
  std::vector<float3> accelerations;        // acceleration of each point charge
};

#endif