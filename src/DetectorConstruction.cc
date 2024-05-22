#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace HPGe
{

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4Material* ge = nist->FindOrBuildMaterial("G4_Ge");

  // world
  G4double w_x = 0.1*m;
  G4double w_y = 0.1*m;
  G4double w_z = 0.1*m;

  G4Box* W_box = new G4Box("World", w_x, w_y, w_z);
  G4Material* W_mat = nist->FindOrBuildMaterial("G4_AIR");
  G4LogicalVolume* W_Log = new G4LogicalVolume(W_box, W_mat, "World");

  G4VPhysicalVolume* W_Phys = new G4PVPlacement(nullptr, G4ThreeVector(), W_Log, "World", nullptr, false, 0);

   // HPGe
  G4double Ge_in_R    = 0.*cm;
  G4double Ge_out_R = 3.1*cm;
  G4double Ge_H         = 3.1*cm;
  G4double Ge_start_Ang = 0.*deg;
  G4double Ge_span_Ang = 360.*deg;

  G4Tubs* Ge_cyl = new G4Tubs("Ge_cyl", Ge_in_R, Ge_out_R, Ge_H, Ge_start_Ang, Ge_span_Ang);
  G4LogicalVolume* Ge_Log = new G4LogicalVolume(Ge_cyl, ge, "HPGe");

  G4double pos_x = 0.0*m;
  G4double pos_y =  0.0*m;
  G4double pos_z =  0.0*m;
  G4VPhysicalVolume* Ge_Phys = new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), Ge_Log, "HPGe", W_Log, false, 0);

  fScoringVolume = Ge_Log;
  return W_Phys;
}
}
