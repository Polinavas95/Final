#include <G4Step.hh>
#include <StepAction.hh>
#include <G4VProcess.hh>
#include <G4SIunits.hh>

void StepAct::UserSteppingAction(const G4Step* step) {
	if (step->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName() == "box_LOG")
		event->AddEnDep(step->GetTotalEnergyDeposit());
}