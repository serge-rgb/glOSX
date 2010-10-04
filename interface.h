/*
 * Interface.h
 *
 *  Created on: Aug 4, 2008
 *      Author: monachus
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include"common.h"

#define W 800
#define H 600


void engInit(int argc, char **argv);
void idle();
void resize(int, int);
void display();


#endif /* INTERFACE_H_ */
