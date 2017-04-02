/* 
 * File:   FichiersLog.cpp
 * Author: LinhGT
 * 
 * Created on 28 mars 2013, 22:02
 */

#include <list>

#include "FichierLog.h"

FichierLog::FichierLog() {
    id_module = 0;
}


FichierLog::FichierLog (string nom, int module)
{
    nom_module = nom;
    id_module = module;
    trame_list.clear();
}
    
FichierLog::FichierLog(const FichierLog& orig) {
}
//destructeur
FichierLog::~FichierLog() {

    while (!trame_list.empty())
    {
        trame *tr = trame_list.back();
        delete tr;
        trame_list.pop_back();
    }
    
    trame_list.clear();
}

int FichierLog::parser(string fileName)
{
    ifstream file(fileName.c_str());
    string csvLine;
    
    if (!file)
    {
        cerr << "file not found" << endl;
        return 1;   
    }
      
    while (getline(file, csvLine))
    {
        trame *tr = new trame();
        tr->write(csvLine);
        trame_list.push_back(tr);
    }  
    file.close();
    return 0;
}


int FichierLog::writeInBDD_libC(string host, string user, string password, string database, string table)
{
     //Options de connexion
    //mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

	
	const int size = trame_list.size ();
	unsigned int horo;
	float posx;
	float posy;
	unsigned int tache;
	unsigned int trame;
	unsigned int pixels;

	if (size == 0)
		return 0;

	
	vector <string> liste_requete;

	listtr::iterator it(trame_list.begin ());

	for (int i = 0; it != trame_list.end() && i < size; ++it, i++)
	{
		char buff[200];
		memset (buff, 0, 200);

		horo = (*it)->get_horodatage();
		posx = (*it)->get_position_x();
		posy = (*it)->get_position_y();
		tache = (*it)->get_id_tache();
		trame = (*it)->get_id_trame();
		pixels = (*it)->get_nombre_pixel();

		sprintf(buff, "INSERT INTO %s VALUES('', %i, %f, %f, %i, %i, %i)", table.c_str(), horo, posx, posy, tache, trame, pixels);
		
		liste_requete.push_back(buff);
	
	}

	MYSQL mysql;
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql, host.c_str(), user.c_str(), password.c_str(), database.c_str(),0,NULL,0))
	{
		for (int i = 0; i < size; i++)
			mysql_query(&mysql, liste_requete[i].c_str());
		
	}
	else
	{
		fprintf(stderr, "Impossible de se connecter à la base de données, erreur : %s\n", mysql_error(&mysql));
	} 

	//Fermeture de MySQL
	mysql_close(&mysql);
   
    return 0;
}

void FichierLog::display () const
{
    list<trame*>::const_iterator it;
    for (it = trame_list.begin(); it != trame_list.end(); it++)
        (*it)->display();
}


