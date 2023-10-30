#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <iostream>
#include <Car.h>
#include <Oto.h>
#include <Motor.h>
#include <vector>
using namespace std;

// void function(vector<Car> *database);

void add(vector<Car*> &data);
void display(vector<Car*> &data);

#endif