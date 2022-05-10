/*
 * Menu.cpp
 *
 *  Created on: 23/11/2021
 *      Author: Joel José Ginga
 */

#include "Menu.h"

Menu::Menu(World *mundoValor){
	this->world = mundoValor;
}

Menu::~Menu() {}

void Menu::showMenu(){
	
	cout<<"Please select one of the options: <Number>+<Enter>"<< endl;
	cout<<"1 - List all countries;"<< endl;
	cout<<"2 - List countries with a population over a given one;"<< endl;
	cout<<"3 - List countries with an area over a given one;"<< endl;
	cout<<"4 - Show country detail;"<< endl;
	cout<<"5 - Sort countries;"<< endl;
	cout<<"6 - World total population;"<< endl;
	cout<<"7 - Exit."<< endl;
	cout<<"\n";
	cin>>option;
		
	showOption();
};

void Menu::showOption(){
	
	switch(option){
			case 1:
				world->listCountries();
				break;
			case 2:
				listCountriesPopulation();
				break;
			case 3:
				listCountriesArea();
				break;
			case 4:
				searchCountry();
				break;
			case 5:
				sortCountries();
				break;
			case 6:
				world->totalPopulation();
				break;
			case 7:
				cout<<"Thanks for your visit.";
				exit(0);
			default:
				cout << "Invalid option." << endl;
				
	}
	
	cout <<"\n\n";
	
	pauseTerminal();
	
	showMenu();
}

void Menu::listCountriesPopulation(){
	long long int pop;
	cout << "Please insert the value of the minimum population:" << endl;
	cin >> pop;
	world->listCountries(pop);
};

void Menu::listCountriesArea(){
	long int area;
	cout << "Please insert the minimum area:" << endl;
	cin >> area;
	world->listCountries(area);
};

void Menu::searchCountry(){
	string name;	
	cout << "Please insert the name of the country." << endl;
	cin.ignore();
	getline(cin,name);
	world->searchForCountry(name);
	
};

void Menu::sortCountries(){
	int n_sort;
		
	cout << "Please choose the sorting method:" << endl;
	cout << "1 - Sort alphabetically;" << endl;
	cout << "2 - Sort by population;" << endl;
	cout << "3 - Sort by area." << endl;
	cin >> n_sort;
	
	sortCountries(n_sort);
};

void Menu::sortCountries(int n_sort){
	switch(n_sort){
					case 1:
						world->sortCountries(World::compareCountryByName());
						world->listCountries();
						break;
					case 2:
						world->sortCountries(World::compareCountryByPopulation());
						world->listCountries();
						break;
					case 3:
						world->sortCountries(World::compareCountryByArea());
						world->listCountries();
						break;
					default:
						cout << "Invalid option" << endl;
						pauseTerminal();
						sortCountries();
	}
};

void Menu::pauseTerminal(){
	cin.ignore();
	cout<<"Please press enter to return to the menu.\n";
	cin.get();
}



