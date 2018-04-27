#pragma once
#include "RunAct.hh"
#include <G4UserEventAction.hh>

class RunAct;

class EventAct : public G4UserEventAction {
public:
	EventAct(RunAct* runAct);
	~EventAct();
	void BeginOfEventAction(const G4Event* anEvent);
	void EndOfEventAction(const G4Event* anEvent);
	void AddEnDep(G4double en);
private:
	RunAct * run;
	G4double EnergyDep;
};