#include <iostream>
#include "model/WaterModel.h"
#include "arithmetic/Numbers.h"
#include "render.h"


int main() {
  WaterMolecule WaterOne(float3(0,0,0), float3(1,0,0));
  WaterMolecule WaterTwo(float3(0,2,0), float3(1,0,0));
  std::cout << "Water Molecule 1: \n" << WaterOne << "\n";
  std::cout << "Water Molecule 2: \n" << WaterTwo << "\n";

  Renderer render("CPU-Water Sim");
  render.initialize();
  render.renderLoop();
  return 0;
}
