/* 
 * File:   FichiersLog.h
 * Author: LinhGT
 *
 * Created on 28 mars 2013, 22:02
 */

#ifndef FICHIERLOG_H
#define	FICHIERLOG_H
#include "trame.h"

typedef list<trame*> listtr;


class FichierLog { 
public:
    FichierLog();
    FichierLog (string nom_module, int module);
    FichierLog(const FichierLog& orig);
    
    int writeInBDD_libC(string host, string user, string password, string database, string table);
    int writeInBDD (string host, string user, string password, string database, string table);

    
    int parser(string fileName);
    void display () const;
    
    virtual ~FichierLog();
private:
    string nom_module;
    int id_module;
    list<trame*> trame_list;
};

#endif	/* FICHIERLOG_H */

