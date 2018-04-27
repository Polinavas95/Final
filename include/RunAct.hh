#pragma once
#include <G4UserRunAction.hh>
#include <map>

class RunAct : public G4UserRunAction {
public:
	RunAct();
	~RunAct();
	void BeginOfRunAction(const G4Run* aRun);
	void EndOfRunAction(const G4Run* aRun);
	void AddEvent(G4double energy);

private:
	std::map<G4double, G4int>* result;
};
