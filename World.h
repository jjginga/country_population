/*
 * World.h
 *
 *  Created on: 22/11/2021
 *      Author: Joel José Ginga
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <fstream>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>

#include "Country.h"
using namespace std;

class World {
private:
	/**properties**/
	vector<Country*> countries; //container with all instances of world countries
	int numberOfCountries; //number of countries

	/**private methods**/
	
	void listCountries();//list all countries
	void listCountries(long long int);//list countries with a population over a given population
	void listCountries(long int);//list countries with an area over a given area
	void sortCountries(function<bool (Country*,Country*)>);//sort countries using a sorting function
	void searchForCountry(string);//search for countries
	void totalPopulation();//calculate all world population
	
	/**auxiliary methods.**/
	string removePercentage(string);//remove percentage sign
	Country* importCountry(vector<string>);//creates a country object using imported data
	friend class Menu;
	
public:
	World();//constructor
	virtual ~World();//descructor
	
	/**static metods that return the sorting functions**/
	static function<bool (Country*, Country*)>  compareCountryByName();
	static function<bool (Country*, Country*)>  compareCountryByPopulation();
	static function<bool (Country*, Country*)>  compareCountryByArea();
};

#endif /* WORLD_H_ */
