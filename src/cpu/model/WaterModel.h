#ifndef WATER_CPU_MODEL_WATER_MODEL_H
#define WATER_CPU_MODEL_WATER_MODEL_H

#include <math.h>
#include <memory>
#include <vector>
#include <array>
#include "../arithmetic/Numbers.h"

// TIP3P 
#define ARM_LENGTH          0.9572
#define CHARGE_OXYGEN       -0.834
#define CHARGE_HYDROGEN     0.417 
#define ANGLE_HYDROGEN      104.52

class WaterMolecule {
enum Structure {OXYGEN = 0, HYDROGEN_1, HYDROGEN_2};
public:
  // will put the molecule together in the right place
  WaterMolecule(float3 oxygen_position, float3 rotation);
  std::array<float4, 3> getPointCharges();
private:
  // applies rotation and ARM_LENGTH to get one hydrogen 
  // 'Main' because first Hydrogen
  float4 calcMainHydroPos(float3 base, float3 rotation);

  // applies angle between hydrogen atoms in the structure
  // angle rotation along z axis
  float4 calcSecondHydroPos(float3 base, float3 rotation);

  // [0] oxygen atom + charge 
  // [1] hydrogen atom + charge
  // [2] hydrogen atom + charge
  std::array<float4, 3> pointCharges;
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