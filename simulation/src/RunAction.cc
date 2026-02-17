#include "RunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4GenericMessenger.hh"
#include "G4Run.hh"
#include "G4SystemOfUnits.hh"

#include <filesystem>
#include <string>

RunAction::RunAction()
{
    // Default output base name (can be overridden from macro)
    fOutputBaseName = "beamscan_output";

    // UI command: /beamscan/output/filename <path>
    // Notes:
    //  - You may include ".csv"; it will be stripped before passing to Geant4.
    //  - You may include directories; they will be created automatically.
    fMessenger = std::make_unique<G4GenericMessenger>(this, "/beamscan/output/", "Output controls");
    fMessenger->DeclareProperty("filename", fOutputBaseName,
        "Base output filename (optionally with path and/or .csv extension)");

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetDefaultFileType("csv");
    analysisManager->SetVerboseLevel(1);

    // Create ntuple with all observables
    analysisManager->CreateNtuple("beamscan", "BeamScan MCS and energy loss data");
    analysisManager->CreateNtupleDColumn("theta3D_mrad");    // 0: 3D scattering angle
    analysisManager->CreateNtupleDColumn("thetaX_mrad");     // 1: projected X scattering
    analysisManager->CreateNtupleDColumn("thetaY_mrad");     // 2: projected Y scattering
    analysisManager->CreateNtupleDColumn("pIn_GeV");         // 3: momentum before target
    analysisManager->CreateNtupleDColumn("pOut_GeV");        // 4: momentum after target
    analysisManager->CreateNtupleDColumn("deltaP_MeV");      // 5: momentum loss
    analysisManager->CreateNtupleDColumn("xTarget_mm");      // 6: x position at target
    analysisManager->CreateNtupleDColumn("yTarget_mm");      // 7: y position at target
    analysisManager->CreateNtupleDColumn("caloEdep_MeV");    // 8: calorimeter energy deposit
    analysisManager->FinishNtuple();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
    auto analysisManager = G4AnalysisManager::Instance();

    // Geant4 expects a base name (it adds the .csv extension).
    // Accept a user-provided ".csv" for convenience.
    std::string base = fOutputBaseName;
    if (base.size() >= 4 && base.substr(base.size() - 4) == ".csv") {
        base = base.substr(0, base.size() - 4);
    }

    // Ensure output directory exists (if any)
    try {
        std::filesystem::path p(base);
        if (p.has_parent_path()) {
            std::filesystem::create_directories(p.parent_path());
        }
    } catch (...) {
        // If directory creation fails, Geant4 will emit an error on OpenFile.
    }

    analysisManager->OpenFile(base);
}

void RunAction::EndOfRunAction(const G4Run*)
{
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
