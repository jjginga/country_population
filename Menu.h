/*
 * Menu.h
 *
 *  Created on: 23/11/2021
 *      Author: Joel José Ginga
 */

#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <iostream>

#include "World.h"

using namespace std;

class Menu {
private:
	/**properties**/
	World *world;
	int option;

	
	void showOption(); //show all the options in the menu
	void listCountriesPopulation();//lists countries with a population over a minimum value
	void listCountriesArea();//list countries with an area over a given area
	void searchCountry();//search country by name
	void sortCountries();//shows options for sorting countries
	void sortCountries(int);//sort countries
	void pauseTerminal();//pause terminal
public:
	Menu(World*);
	virtual ~Menu();
	void showMenu();//show menu
};

#endif /* MENU_H_ */
