/* 
 * File:   main.cpp
 * Author: LinhGT
 *
 * Created on 27 mars 2013, 21:40
 */


#include "FichierLog.h"



using namespace std;



int main(int argc, char** argv) {
    vector<FichierLog*> csvFile;

    DIR *rep = NULL;
    struct dirent *myRep;
    vector<string> files;

    if (argc == 2)
    {
         rep = opendir(argv[1]);
        if (rep == NULL)
        {
            cerr << "Error: opening" << errno << endl;
            return errno;
        }
        
        while ((myRep = readdir(rep)) != NULL)
        {
            string path(argv[1]);
            struct stat temp;
            path = path + "/" +  myRep->d_name;
            
            if (stat(path.c_str(), &temp))
                continue;
            if (S_ISDIR(temp.st_mode))
                continue;
             
            files.push_back(path);
        }
        closedir(rep);
    }
    else
        cerr << "No folder founded" << endl;
    for (int i = 0;i < files.size();i++) {
        FichierLog *file = new FichierLog();
        file->parser(files[i]);
        csvFile.push_back(file);
    }

    for (int i = 0; i < csvFile.size(); i++)
    {
        csvFile[i]->display();
		csvFile[i]->writeInBDD_libC(DBHOST, USER, PASSWORD, DATABASE, TABLE);
    }
    // desalocation csvFile
	return EXIT_SUCCESS;

}
