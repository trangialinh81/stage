/* 
 * File:   trame.h
 * Author: LinhGT
 *
 * Created on 28 mars 2013, 21:48
 */

#ifndef TRAME_H
#define	TRAME_H

#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <sys/stat.h>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <iterator>
#include <memory>
#include <stdexcept>

/* MySQL Connector/C++ specific headers */
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>

#define PORT "3306"
#define DBHOST "localhost"
#define URL "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD ""
#define DATABASE "donneescapteurs"
#define TABLE "donneesbrutes"

#define NUMOFFSET 100
#define COLNAME 200

using namespace sql;
using namespace std;

const char delimiter = ';';

class trame {
public:
    trame();
    trame(unsigned int horo, unsigned int trame, 
          unsigned int tache, float x, float y, unsigned int pixels);
    trame(const trame& orig);
    
    void set_horodatage (unsigned int horo)
    {
        horodatage = horo;
    }
    
    unsigned int get_horodatage () const 
    {
        return horodatage;
    }
    void set_id_trame(unsigned int tr)
    {
        id_trame = tr;
    }
    unsigned int get_id_trame() const
    {
        return id_trame;
    }
     void set_id_tache(unsigned int ta)
    {
        id_tache = ta;
    }
    unsigned int get_id_tache() const
    {
        return id_tache;
    }
     void set_position_x(float px)
    {
        position_x = px;
    }
    float get_position_x() const
    {
        return position_x;
    }
       
    void set_position_y(float py)
    {
        position_x = py;
    }
    float get_position_y() const
    {
        return position_y;
    }
       void set_nombre_pixel(unsigned int np)
    {
        nombre_pixel = np;
    }
    unsigned int get_nombre_pixel() const
    {
        return nombre_pixel;
    }
    
    void write (string trame);
    void display () const;  
    virtual ~trame(); //destructeur
    
private:
    unsigned int horodatage; // nombre entier non signe 8 octets
    unsigned int id_trame; // nombre entier non signe 4 octets
    unsigned int id_tache; //nombre entier non signe 1 octet
    float position_x; //nombre a virgule 4 octets       
    float position_y; //nombre a virgule 4 octets
    unsigned int nombre_pixel; //nombre de pixel 4 octets
};

#endif	/* TRAME_H */

