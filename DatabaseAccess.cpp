#include "DatabaseAccess.h"
#include <iostream> 

bool DatabaseAccess::open()
{
	int res = sqlite3_open("Gallery.VC.db", &db);

    if (res != SQLITE_OK)
    {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return false;
    }
    return true;
}

void DatabaseAccess::close()
{
    sqlite3_close(db);
}

void DatabaseAccess::clear()
{
    const char* sqlStatement = "DELETE FROM USERS;";
    char* errMessage = nullptr;

    int res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }

    sqlStatement = "DELETE FROM ALBUMS;";
    errMessage = nullptr;
    res = sqlite3_exec(db, sqlStatement, nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
    std::string albumName = pAlbum.getName();
    std::string sqlStatement = "DELETE FROM PERSONS WHERE LAST_NAME = '" + albumName + "';"; 
    
    char* errMessage = nullptr;
    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
   
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
}

