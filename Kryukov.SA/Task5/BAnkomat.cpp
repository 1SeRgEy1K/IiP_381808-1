#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Bankomat.h"
#include <utility>
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
Bankomat::Bankomat()
{
	for (int i=0; i<6; i++)
	    Count[i] = 1600; 
    
}