/*
 * Main.cpp
 *
 *  Created on: 23/11/2021
 *      Author: Joel Jos� Ginga
 */

#include "Menu.h"
#include "World.h"


int main(){
	World world;
	Menu menu(&world);
	menu.showMenu();
}


