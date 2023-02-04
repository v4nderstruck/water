#include "WaterModel.h"

WaterMolecule::WaterMolecule(float3 oxygen_pos, float3 rotation) : pointCharges({})
{

  pointCharges[WaterMolecule::Structure::OXYGEN] = float4(oxygen_pos.x,
                                                          oxygen_pos.y, oxygen_pos.z, CHARGE_OXYGEN);
  pointCharges[WaterMolecule::Structure::HYDROGEN_1] = calcMainHydroPos(oxygen_pos, rotation);
  pointCharges[WaterMolecule::Structure::HYDROGEN_2] = calcSecondHydroPos(oxygen_pos, rotation);
}

float4 WaterMolecule::calcMainHydroPos(float3 base, float3 rotation)
{
  // bring the rotation vector to proper length
  float m = ARM_LENGTH / rotation.length();
  float3 H1 = (rotation * m) + base;

  return float4(H1.x, H1.y, H1.z, CHARGE_HYDROGEN);
}

float4 WaterMolecule::calcSecondHydroPos(float3 base, float3 rotation)
{
  float m = ARM_LENGTH / rotation.length();
  float3 H1 = (rotation * m);
  float3 angled = H1.rotateZ(ANGLE_HYDROGEN);

  return float4(angled.x + base.x, angled.y + base.y, angled.z + base.z, CHARGE_HYDROGEN);
}

std::array<float4, 3> WaterMolecule::getPointCharges() const
{
  return pointCharges;
}

std::ostream &operator<<(std::ostream &os, const WaterMolecule &w)
{
  auto pointCharges = w.getPointCharges();
  os << "<OXYGEN> x: " << pointCharges[WaterMolecule::Structure::OXYGEN].x << " "
     << "y: " << pointCharges[WaterMolecule::Structure::OXYGEN].y << " "
     << "z: " << pointCharges[WaterMolecule::Structure::OXYGEN].z << "\n";

  os << "<HYDROGEN> x: " << pointCharges[WaterMolecule::Structure::HYDROGEN_1].x << " "
     << "y: " << pointCharges[WaterMolecule::Structure::HYDROGEN_1].y << " "
     << "z: " << pointCharges[WaterMolecule::Structure::HYDROGEN_1].z << "\n";

  os << "<HYDROGEN> x: " << pointCharges[WaterMolecule::Structure::HYDROGEN_2].x << " "
     << "y: " << pointCharges[WaterMolecule::Structure::HYDROGEN_2].y << " "
     << "z: " << pointCharges[WaterMolecule::Structure::HYDROGEN_2].z << "\n";

  return os;
}