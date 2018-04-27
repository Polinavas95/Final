#include <RunAct.hh>
#include <G4SystemOfUnits.hh>
#include <iostream>

RunAct::RunAct() {
	result = new std::map<G4double, G4int>;
}

RunAct::~RunAct() {
	delete result;
}

void RunAct::BeginOfRunAction(const G4Run* aRun) {
	result->clear();
	G4int nStep = 500;
	G4double eMax = 5 * MeV;
	for (int i = 0; i < nStep; i++)
		result->insert(std::pair<G4double, G4int>(i*eMax / nStep, 0));
}

void RunAct::EndOfRunAction(const G4Run* aRun) {
	for (auto it: * result)
		std::cout << it.first << " | "<< it.second << '\n';
}

void RunAct::AddEvent(G4double energy) {
	auto it = result->lower_bound(energy);
	it->second++;
}