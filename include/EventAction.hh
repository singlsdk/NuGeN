#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include <vector>

namespace HPGe
{
class RunAction;

class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction* runAction);
    ~EventAction() override = default;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;

    void AddEdep(G4double edep)
    {
      if (edep!=0)
        v_Edep.push_back(edep);
    }

  private:
    RunAction* fRunAction = nullptr;
    std::vector<G4double> v_Edep;
};

}
#endif


