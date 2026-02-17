#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"

#include "globals.hh"
#include <memory>

class G4GenericMessenger;

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    ~RunAction() override = default;
    void BeginOfRunAction(const G4Run*) override;
    void EndOfRunAction(const G4Run*) override;

private:
    // Base output name passed to Geant4 analysis manager.
    // For CSV output, Geant4 will create a .csv file (and may add ntuple suffixes depending on version).
    G4String fOutputBaseName;
    std::unique_ptr<G4GenericMessenger> fMessenger;
};

#endif
