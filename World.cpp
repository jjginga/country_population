/*
 * World.cpp
 *
 *  Created on: 22/11/2021
 *      Author: Joel José Ginga
 */

#include "World.h"

/** path for the file with the stored data **/
/** the used file was taken from the website Kaggle - https://www.kaggle.com/eng0mohamed0nabil/population-by-country-2020/metadata **/
const string path = "population_by_country_2020.csv";


//Anonymous sorting functions
struct sortName{
	bool operator()(Country* a, Country* b) const{
		return a->getName()<b->getName();
	}
};
struct sortPopulation{
	bool operator()(Country* a, Country* b) const{
		return a->getPopulation()<b->getPopulation();
	}
};

struct sortArea{
	bool operator()(Country* a, Country*  b) const{
		return a->getArea()<b->getArea();
	}
};

/**in the constructor we import all the countries from the file**/
World::World() {
		int n=0;
		ifstream fin;
		
		fin.open(path, ios::in); //open filestream
		
		//show error if we can't find the file
		if(!fin.is_open()){
			cout<<"Unable to open file";
		}
			
		vector<string> row;
		string line, word, temp;
		
		//remove header
		getline(fin, line);	
		
		//we read the file, line by line and create an instance of Country from each line
		//that we then store in the countries vector
		while(getline(fin, line)){
			row.clear();
					
			stringstream s(line);
				
			while(getline(s, word, ','))
				row.push_back(word);
			
			Country *country = importCountry(row);
			
			countries.push_back(country);
			++n;
		}
		
		this->numberOfCountries = n;
}

World::~World() {

}

/** list all countries **/
void World::listCountries(){
	for (int c = 0 ; c<numberOfCountries ; c++)
			countries[c]->printCountry();
};

/** list all countries with a population over a given population - popMin**/
void World::listCountries(long long int popMin){
	for (int c = 0 ; c<numberOfCountries ; c++){
		if(countries[c]->checkCountry(popMin))
			countries[c]->printCountry();
	}
};

/**list countries with an area over a minimum area - areaMin **/
void World::listCountries(long int areaMin){
	for (int c = 0 ; c<numberOfCountries ; c++){
			if(countries[c]->checkCountry(areaMin))
				countries[c]->printCountry();
	}
};

/** sort countries with a sorting function **/
void World::sortCountries(function<bool (Country*,Country*)> f){
	sort(countries.begin(), countries.end(), f);
};

/** search for country by name **/
void World::searchForCountry(string str){
	for (int c = 0 ; c<numberOfCountries ; c++){
			if(countries[c]->checkCountry(str)){
					countries[c]->printCountryDetails();
					return;
			}
	}
	cout<<"Country not found."<<endl;
};

/** calculate the world total population **/
//we do this by creating a country instance where we store all the world population
void World::totalPopulation(){
	Country mankind;
	mankind.setPopulation(0);
	mankind.setName("World");
	for (int c = 0 ; c<numberOfCountries ; c++){
			mankind+=*countries[c];
	}
	mankind.printPopulation();
}


Country* World::importCountry(vector<string> row){
	
	/*because some of the data doesn't exist in our dataset
	 * we set the corresponding attribute in the country object 
	 * with the value -1, that we know is an error value
	 */
	
	float fertility = -1;
	int medianAge = -1;
	int urbanPopulation = -1;
	
	if(row[7].compare("N.A."))
		fertility = stof(row[7]);
	
	if(row[8].compare("N.A."))
		medianAge = stoi(row[8]);
	
	if(row[9].find("%")!=string::npos)
		urbanPopulation = stoi(removePercentage(row[9]));
	
	
	Country *country= new Country();
	country->setName(row[0]);
	country->setPopulation(stoll(row[1]));
	country->setChange(stof(removePercentage(row[2])));
	country->setDensity(stoi(row[4]));
	country->setArea(stol(row[5]));
	country->setFertility(fertility);
	country->setMedianAge(medianAge);
	country->setUrbanPopulation(urbanPopulation);
		
	return country;
}

string World::removePercentage(string str){
	int pos = str.find("%");
	return str.substr(0, pos);
}

function<bool (Country*, Country*)>  World::compareCountryByName(){
	return sortName();
}

function<bool (Country*, Country*)>  World::compareCountryByPopulation(){
	return sortPopulation();
}

function<bool (Country*, Country*)> World::compareCountryByArea(){
	return sortArea();
}
