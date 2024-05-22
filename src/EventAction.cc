#include "EventAction.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

#include <fstream>

namespace HPGe
{

EventAction::EventAction(RunAction* runAction)
: fRunAction(runAction)
{}


void EventAction::BeginOfEventAction(const G4Event*)
{
  v_Edep.clear();
}


void EventAction::EndOfEventAction(const G4Event*)
{

  if (v_Edep.size()!=0)
  {
    std::fstream out("/home/singl/geant/HPGe/HPGe-build/edep.txt", std::ios::out | std::ios::app);

    G4double e_tot = 0;
    for (int i=0; i<v_Edep.size(); i++)
      e_tot+=v_Edep.at(i);
    out<<e_tot<<std::endl;
    out.close();
  }
}
}
