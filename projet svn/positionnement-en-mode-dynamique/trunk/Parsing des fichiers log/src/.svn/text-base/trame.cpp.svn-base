/* 
 * File:   trame.cpp
 * Author: LinhGT
 * 
 * Created on 28 mars 2013, 21:48
 */

#include <stdlib.h>

#include "trame.h"

trame::trame() {
    horodatage = 0;
    id_trame = 0;
    id_tache = 0;
    position_x = 0;
    position_y = 0;
    nombre_pixel = 0;
}


trame::trame(unsigned int horo, unsigned int trame, 
          unsigned int tache, float x, float y, unsigned int pixels)
{
    horodatage = horo;
    id_trame = trame;
    id_tache = tache;
    position_x = x;
    position_y = y;
    nombre_pixel = pixels;
    
}

void trame::display() const
{
    cout << horodatage << delimiter << id_trame << delimiter
         << id_tache   << delimiter << position_x << delimiter
         << position_y << delimiter << nombre_pixel << delimiter << endl;   
}

void trame::write (string trame)
{
    stringstream line(trame);
    string cell;
    
    if (getline(line, cell, delimiter))
    {
        horodatage = atoi (cell.c_str());
        if (getline(line, cell, delimiter))
        {
            id_trame = atoi (cell.c_str());
            if (getline(line, cell, delimiter))
            {
                id_tache = atoi (cell.c_str());
                if (getline(line, cell, delimiter))
                {
                    position_x = atof (cell.c_str());
                    if (getline(line, cell, delimiter))
                    {
                        position_y = atof (cell.c_str());
                        if (getline(line, cell, delimiter))
                            nombre_pixel = atoi (cell.c_str());
                    }

                }
            }
        }
    }
}

trame::trame(const trame& orig) {
}

trame::~trame() {
}

