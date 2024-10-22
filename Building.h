#ifndef BUILDING_H
#define BUILDING_H

class Building {

private:
	string name;
	float area;
	int floors;
	int capacity;
protected:
	float citizenSatisfaction;
	float economicGrowth;
	float resouceConsumption;

public:
	virtual void construct() = 0;

	float getSatisfaction();

	float getEconomicGrowth();

	float getResourceConsumption();

private:
	void updateImpacts();

public:
	virtual string getType() = 0;

protected:
	Building(int Builder);

private:
	virtual void calculateSatisfactionImpact() = 0;

	virtual void calculateEconomicImpact() = 0;

	virtual void calculateResourceConsumption() = 0;
};

#endif
