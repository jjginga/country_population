/*
 * Country.cpp
 *
 *  Created on: 22/11/2021
 *      Author: Joel José Ginga
 */

#include "Country.h"

Country::Country() {}

Country::~Country() {}


void Country::printCountry(){
	string medianAgeStr = medianAge == -1 ? "N.A." : to_string(medianAge);
	cout << name <<" | population: "<< population << " | area: " << area << " | median age: " << medianAgeStr << endl;
};

void Country::printCountryDetails(){

	//we convert the -1 values, to values meaningful to the user
	string medianAgeStr = medianAge == -1 ? "N.A." : to_string(medianAge);
	string fertilityStr = fertility == -1 ? "N.A." : to_string(fertility);
	string urbanPopulationStr = urbanPopulation == -1 ? "N.A." : to_string(urbanPopulation);

	cout << "Name: "<< name << endl;
	cout << "Population: "<< population << endl;
	cout << "Area: " << area << " km2" << endl;
	cout << "Demographic evolution: "<< change << "%" << endl;
	cout << "Density: "<< density << " inhabitant/km2" << endl;
	cout << "Fertility rate: "<< fertilityStr << endl;
	cout << "Median Age: "<< medianAgeStr << endl;
	cout << "Urban Population: "<< urbanPopulationStr << endl;
};

void Country::printPopulation(){
	cout << name <<" | population: "<< population <<endl;
}

int Country::checkCountry(long long int popMin){
	return population>=popMin;
};

int Country::checkCountry(long int areaMin){
	return area>=areaMin;
};

int Country::checkCountry(string str){
	return !str.compare(name);
}

//we overload the operator - a sum of two countries is the sum of their population
void Country::operator+=(Country const &a){
	this->population=population+a.population;
}
