#include <iostream>
#include <memory>
#include "ResidentialBuildingBuilder.h"
#include "CommercialBuildingBuilder.h"
#include "IndustrialBuildingBuilder.h"
#include "LandmarkBuildingBuilder.h"

//utilities includes
#include "UtilityMediator.h"
#include "Utility.h"
#include "WaterSupply.h"
#include "WasteManagement.h"


//GOV includes
#include "Government.h"
#include "SetTaxCommand.h"
#include "EnforcePolicyCommand.h"
#include "AllocateBudgetCommand.h"
#include "CollectTaxesCommand.h"
#include "CityService.h"
#include "Policy.h"
#include "Business.h"

// Test ResidentialBuildingBuilder
void testResidentialBuildingBuilder() {
    std::cout << "\nTesting ResidentialBuildingBuilder\n";

    ResidentialBuildingBuilder builder;
    builder.setName("Green Villa")
           .setArea(1200.0f)
           .setFloors(2)
           .setCapacity(60)
           .setCitizenSatisfaction(2.5f)
           .setEconomicGrowth(1.5f)
           .setResourceConsumption(1.0f);                // Residential-specific method

builder.setResidentialUnit(30);
builder.setComfort(4.0f);
    auto residentialBuilding = builder.build();
    residentialBuilding->construct();
    residentialBuilding->updateImpacts();

    //testing specific funtions in residential builder
    std::cout<<"Testing getResidentialUnit:"<<builder.getResidentialUnit()<<std::endl;
    std::cout<<"Testing getComfort:"<<builder.getComfort()<<std::endl;

    //testing building
ResidentialBuilding resbuild = ResidentialBuilding("Green Villa", 1200.0f, 2, 60, 2.5f, 1.5f, 1.0f, 30, 4.0f);
    resbuild.construct();
    resbuild.updateImpacts();
    resbuild.upgradeComfort(1.0f);
   // resbuild.calculateEconomicImpact();
    //resbuild.calculateResourceConsumption();
    //resbuild.calculateSatisfactionImpact();
    //resbuild.hostEvent(10);
    //resbuild.calculateEconomicImpact();
    //resbuild.calculateResourceConsumption();
    //resbuild.calculateSatisfactionImpact();
    resbuild.updateImpacts();

    resbuild.construct();
    resbuild.getType();
    
}

// Test CommercialBuildingBuilder
void testCommercialBuildingBuilder() {
    std::cout << "\nTesting CommercialBuildingBuilder\n";

    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);

builder.setBusinessUnits(50);
builder.setCustomerTraffic(500);
    auto commercialBuilding = builder.build();
    commercialBuilding->construct();
    commercialBuilding->updateImpacts();
}

// Test IndustrialBuildingBuilder
void testIndustrialBuildingBuilder() {
    std::cout << "\nTesting IndustrialBuildingBuilder\n";

    IndustrialBuildingBuilder builder;
    builder.setName("Tech Factory")
           .setArea(5000.0f)
           .setFloors(5)
           .setCapacity(300)
           .setCitizenSatisfaction(-1.0f)
           .setEconomicGrowth(4.5f)
           .setResourceConsumption(3.0f);

builder.setPollutionLevel(2.0f);
builder.setProductionCapacity(10.0f);
    auto industrialBuilding = builder.build();
    industrialBuilding->construct();
    industrialBuilding->updateImpacts();
}

// Test LandmarkBuildingBuilder
void testLandmarkBuildingBuilder() {
    std::cout << "\nTesting LandmarkBuildingBuilder\n";

    LandmarkBuildingBuilder builder;
    builder.setName("National Museum")
           .setArea(4000.0f)
           .setFloors(4)
           .setCapacity(250)
           .setCitizenSatisfaction(5.0f)
           .setEconomicGrowth(2.5f)
           .setResourceConsumption(1.5f);             
           // Landmark-specific method

builder.setVisitorCapacity(1000);
builder.setCulturalValue(10.0f);
builder.setIsHistoric(true);
    auto landmarkBuilding = builder.build();
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
}

//test Utilities water supply and waste management
void testUtilities() {
    std::cout << "\nTesting Utilities\n";

    // Create mediator
    UtilityMediator mediator;

    // Create water supply and waste management utilities
    WaterSupply waterSupply(&mediator);
    WasteManagement wasteManagement(&mediator);

    // Register buildings with utilities
    // Building building1("Building 1", 1000.0f, 2, 50, 3.0f, 2.0f, 1.0f);
    // Building building2("Building 2", 2000.0f, 3, 100, 2.5f, 1.5f, 1.5f);
    //registering buildings (commercial,landmark and industrial)
    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);
    
    builder.setBusinessUnits(50);
    builder.setCustomerTraffic(500);
    auto commercialBuilding = builder.build();
    commercialBuilding->construct();
    commercialBuilding->updateImpacts();
    // waterSupply.registerBuilding(commercialBuilding.get());

    LandmarkBuildingBuilder builder1;
    builder1.setName("National Museum")
           .setArea(4000.0f)
           .setFloors(4)
           .setCapacity(250)
           .setCitizenSatisfaction(5.0f)
           .setEconomicGrowth(2.5f)
           .setResourceConsumption(1.5f);             
           // Landmark-specific method
    
    builder1.setVisitorCapacity(1000);
    builder1.setCulturalValue(10.0f);
    builder1.setIsHistoric(true);
    auto landmarkBuilding = builder1.build();
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
    // waterSupply.registerBuilding(landmarkBuilding.get());


    waterSupply.registerBuilding(commercialBuilding.get());
    waterSupply.registerBuilding(landmarkBuilding.get());

    wasteManagement.registerBuilding(commercialBuilding.get());
    wasteManagement.registerBuilding(landmarkBuilding.get());

    // Supply resources to buildings
    waterSupply.supplyResources(commercialBuilding.get());
    waterSupply.supplyResources(landmarkBuilding.get());

    wasteManagement.supplyResources(commercialBuilding.get());
    wasteManagement.supplyResources(landmarkBuilding.get());

    // Adjust utilities based on citizens
    // Citizen citizen1("Citizen 1", 25, 1.0f, 1.0f, 1.0f);
    // Citizen citizen2("Citizen 2", 30, 1.5f, 1.5f, 1.5f);

    // waterSupply.adjustForCitizen(&citizen1);
    // waterSupply.adjustForCitizen(&citizen2);

    // wasteManagement.adjustForCitizen(&citizen1);
    // wasteManagement.adjustForCitizen(&citizen2);
}

//=========================================================================================================
//                                            GOV TESTING :
//=========================================================================================================
void testGOVF1() {
    // Create a CityService instance
    CityService cityService("Public Transport", 1000.0);
    // Test setServiceName and getServiceName
    cityService.setServiceName("Healthcare");
    std::cout << "Service Name: " << cityService.getServiceName() << std::endl;
    // Test printDetails
    cityService.printDetails();
    // Test isWithinBudget
    std::cout << "Is within budget (500): " << cityService.isWithinBudget(500) << std::endl;
    std::cout << "Is within budget (1500): " << cityService.isWithinBudget(1500) << std::endl;
    // Test allocateAdditionalBudget
    try {
        cityService.allocateAdditionalBudget(200, 500);
        cityService.printDetails();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test reduceBudget
    try {
        cityService.reduceBudget(300);
        cityService.printDetails();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Create a Business instance
    Business business(5000.0, 10.0);
    // Test addService and removeService
    business.addService("Consulting");
    business.addService("IT Support");
    business.printDetails();
    business.removeService("Consulting");
    business.printDetails();
    // Test addPolicy and removePolicy
    Policy policy1("Policy1", "High");
    Policy policy2("Policy2", "Medium");
    business.addPolicy(policy1);
    business.addPolicy(policy2);
    business.printDetails();
    business.removePolicy(policy1);
    business.printDetails();
    // Test calculateTax
    std::cout << "Calculated Tax: " << business.calculateTax() << std::endl;
    // Test payTax
    business.payTax(business.calculateTax());
    business.printDetails();
}

void TESTGOVCOMMAND() {
    // Create a Government instance
    Government government("City Government");
    // Create a CityService instance
    CityService cityService("Public Transport", 1000.0);
    // Create a Policy instance
    Policy policy("Policy1", "High");
    // Create command instances
    SetTaxCommand setTaxCommand(&government, 15.0);
    EnforcePolicyCommand enforcePolicyCommand(&government, policy);
    AllocateBudgetCommand allocateBudgetCommand(&government, cityService, 500.0);
    CollectTaxesCommand collectTaxesCommand(&government);
    // Execute commands
    std::cout << "Executing SetTaxCommand..." << std::endl;
    setTaxCommand.execute();
    std::cout << "Executing EnforcePolicyCommand..." << std::endl;
    enforcePolicyCommand.execute();
    std::cout << "Executing AllocateBudgetCommand..." << std::endl;
    allocateBudgetCommand.execute();
    std::cout << "Executing CollectTaxesCommand..." << std::endl;
    collectTaxesCommand.execute();
    // Undo commands
    std::cout << "Undoing SetTaxCommand..." << std::endl;
    setTaxCommand.undo();
    std::cout << "Undoing AllocateBudgetCommand..." << std::endl;
    allocateBudgetCommand.undo();
    std::cout << "Undoing CollectTaxesCommand..." << std::endl;
    collectTaxesCommand.undo();
    // Test new command functions
    std::cout << "Testing new command functions..." << std::endl;
    // Test getName and getDescription for SetTaxCommand
    std::cout << "SetTaxCommand Name: " << setTaxCommand.getName() << std::endl;
    std::cout << "SetTaxCommand Description: " << setTaxCommand.getDescription() << std::endl;
    // Test canExecute for SetTaxCommand
    std::cout << "Can execute SetTaxCommand: " << setTaxCommand.canExecute() << std::endl;
    // Test executeWithValidation for AllocateBudgetCommand
    try {
        allocateBudgetCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test validateCollection for CollectTaxesCommand
    std::cout << "Can execute CollectTaxesCommand: " << collectTaxesCommand.validateCollection() << std::endl;
    // Test executeWithValidation for CollectTaxesCommand
    try {
        collectTaxesCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test isPolicyEnforced for EnforcePolicyCommand
    std::cout << "Is policy enforced: " << enforcePolicyCommand.isPolicyEnforced() << std::endl;
    // Test executeWithValidation for EnforcePolicyCommand
    try {
        enforcePolicyCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


//=============================================================================================
//                                    END    GOV    TESTING
//=============================================================================================

int main() {
    // Testing each builder class separately
    testResidentialBuildingBuilder();
    testCommercialBuildingBuilder();
    testIndustrialBuildingBuilder();
    testLandmarkBuildingBuilder();
    testUtilities();
    std::cout << "============================GOVT1========================" << std::endl;
    TESTGOVCOMMAND();
    std::cout << "============================GOVT2========================" << std::endl;
    testGOVF1();
    return 0;
}
