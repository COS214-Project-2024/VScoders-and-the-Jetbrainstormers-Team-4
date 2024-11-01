// Citizen.cpp

#include "Citizen.h"
#include "CitizenObserver.h"
//#include "LeavingCityState.h"
#include <algorithm>
#include <iostream>

template <typename T>
T clamp(T value, T min, T max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

Citizen::Citizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle)
    : name(name), age(age), resStatus(resStatus), jobTitle(jobTitle), satisfaction(50.0),
      maritalStatus(false), health(true), bankBalance(0.0), educationLevel("None"), taxRate(0.1f),
      housingSatisfaction(false), income(0.0), currentState(nullptr) , housingComfortLevel(5.0f), employed(false) {}

Citizen::~Citizen() {
    delete currentState;
}

void Citizen::setState(CitizenState* newState) {
    if (currentState) {
        delete currentState;
    }
    currentState = newState;
    notifyObservers();  // Notify observers of the state change
}

void Citizen::applyState() {
    if (currentState) {
        currentState->handleState(*this);
        notifyObservers();  // Notify observers after applying the state
    }
}

void Citizen::updateSatisfaction(float adjustment) {
    // Adjust satisfaction with clamping between 0 and 100
    satisfaction = clamp(satisfaction + adjustment, 0.0f, 100.0f);
    notifyObservers();  // Notify observers that satisfaction has changed
}

float Citizen::getSatisfactionLevel() const {
    return satisfaction;
}

std::shared_ptr<Citizen> Citizen::clone() const {
    return nullptr; // Placeholder, each subclass should implement this.
}

// Observer management
void Citizen::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

void Citizen::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Citizen::notifyObservers() {
    for (auto* observer : observers) {
        observer->update(this);
    }
}

// Update methods
void Citizen::updateJobSatisfaction() {
    // Update job satisfaction logic here
    notifyObservers();
}

void Citizen::updateMaritalStatus(bool status) {
    maritalStatus = status;
    notifyObservers();
}

void Citizen::updateTaxRate(double rate) {
    // Apply the tax rate change to the citizen's financial state
    // Possibly adjust bank balance or satisfaction
    notifyObservers();
}

void Citizen::updateHealth(bool status) {
    health = status;
    notifyObservers();
}


void Citizen::updateSatisfaction(float newSatisfaction) {
    satisfaction = newSatisfaction;
    notifyObservers();
}

void Citizen::updateTaxRatePolicy(const Policy& policy) {
    // Respond to tax policy change by adjusting tax-related satisfaction or bank balance
    notifyObservers();
}

void Citizen::updateResService(const CityService& service) {
    // Adjust satisfaction or other attributes based on service provided
    notifyObservers();
}

void Citizen::changeTaxRate(double rate) {
    // Logic to directly change the tax rate
    notifyObservers();
}

void Citizen::updateEducationLevel(const std::string& level) {
    educationLevel = level;
    notifyObservers();
}

void Citizen::updateHealthStatus(bool status) {
    health = status;
    notifyObservers();
}

void Citizen::updateHousingSatisfaction(bool satisfaction) {
    housingSatisfaction = satisfaction;
    notifyObservers();
}

void Citizen::updateBankBalance(double amount) {
    bankBalance += amount;
    notifyObservers();
}

void Citizen::updateService(const CityService* service) {
    // Logic to update citizen based on service provided
    notifyObservers();
}

void Citizen::updatePolicy(const Policy* policy) {
    // Logic to update citizen based on policy change
    notifyObservers();
}

// Getters
int Citizen::getAge() const {
    return age;
}

std::string Citizen::getName() const {
    return name;
}

std::string Citizen::getJob() const {
    return jobTitle;
}

bool Citizen::getHealth() const {
    return health;
}

bool Citizen::getMaritalStatus() const {
    return maritalStatus;
}

std::string Citizen::getResStatus() const {
    return resStatus;
}

std::string Citizen::getJobStatus() const {
    return jobTitle;
}

double Citizen::getBankBalance() const {
    return bankBalance;
}

// Relationship methods
std::string Citizen::getRelationshipStatus() const {
    return relationshipStatus;
}

void Citizen::setRelationshipStatus(const std::string& status) {
    relationshipStatus = status;
    notifyObservers();
}

void Citizen::incrementMarriageDuration() {
    if (relationshipStatus == "Married") {
        ++marriageDuration;
    }
}

void Citizen::resetMarriageDuration() {
    marriageDuration = 0;
}

int Citizen::getMarriageDuration() const {
    return marriageDuration;
}

void Citizen::addChild() {
    ++numChildren;
    notifyObservers();  // Notify observers of the new child
}

int Citizen::getNumChildren() const {
    return numChildren;
}

void Citizen::setJobTitle(const std::string& title) {
    jobTitle = title;
}

void Citizen::displayInfo() const {
    std::cout << "Name: " << name << ", Age: " << age
              << ", Job: " << jobTitle << std::endl;
}

bool Citizen::isLeaving() const {
    return dynamic_cast<LeavingCityState*>(currentState) != nullptr;
}

void Citizen::addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy) {
    satisfactionStrategies.push_back(strategy);
}

void Citizen::updateSatisfaction() {
    float totalSatisfaction = 0.0;
    for (const auto& strategy : satisfactionStrategies) {
        totalSatisfaction += strategy->calculateSatisfaction(*this);
    }
    // Average satisfaction score if multiple strategies are used
    satisfaction = totalSatisfaction / satisfactionStrategies.size();
    std::cout << name << "'s updated satisfaction: " << satisfaction << std::endl;
}