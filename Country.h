/*
 * Country.h
 *
 *  Created on: 22/11/2021
 *      Author: Joel José Ginga
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <string>
#include <iostream>

using namespace std;

class Country {
private:
	/**properties**/
	string name;
	long long int population;
	float change;
	int density;
	long int area;
	float fertility;
	int medianAge;
	int urbanPopulation;

public:
	Country();
	virtual ~Country();

	/**setters**/
	void setArea(long int area) {this->area = area;}
	void setChange(float change) {this->change = change;}
	void setDensity(int density) {this->density = density;}
	void setFertility(float fertility) {this->fertility = fertility;}
	void setMedianAge(int medianAge) {this->medianAge = medianAge;}
	void setName(string name) {this->name = name;}
	void setPopulation(long long int population) {this->population = population;}
	void setUrbanPopulation(int urbanPopulation) {this->urbanPopulation = urbanPopulation;}

	/**getters**/
	float getChange() const {return change;}
	long int getArea() const {return area;}
	int getDensity() const {return density;}
	float getFertility() const {return fertility;}
	int getMedianAge() const {return medianAge;}
	const string& getName() const {return name;}
	long long int getPopulation() const {return population;}
	int getUrbanPopulation() const {return urbanPopulation;}

	void printCountry();//prints the country in the console
	void printPopulation();//prints the country name and it's population
	void printCountryDetails();//prints country details in the console
	int checkCountry(long long int);//checks if country population is higher than a given value
	int checkCountry(long int);//checks if a country has an area over a given area
	int checkCountry(string);//checks if country has given country name
	void operator+=(Country const&);//operator overload
};

#endif /* COUNTRY_H_ */
