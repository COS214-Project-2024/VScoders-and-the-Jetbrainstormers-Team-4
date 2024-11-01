#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include "GovObserver.h"
#include "CityService.h"
#include "Policy.h"

using namespace std;

class Government {
private:
    string governmentName;
    double taxRate;
    double budget;
    vector<GovObserver*> observers;

public:
    // Constructor
    explicit Government(string name);

    // Tax-related methods
    void setTax(double rate);
    double getTaxRate() const;
    double collectTaxes();
    void refundTaxes(double amount);

    // Notification methods
    void notifyCitizen();
    void notifyBusinesses();
    void notifyServices();

    // Budget methods
    void allocateBudget(CityService& service, double amount);
    void revertBudgetAllocation(CityService& service, double amount);

    // Policy methods
    void enforcePolicy(Policy* policy);

    // Population update
    void update(int newPopulation);

    // Observer pattern methods
    void registerObserver(GovObserver* observer);
    void unregisterObserver(GovObserver* observer);
    void notifyObservers();
};

#endif // GOVERNMENT_H