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

const std::list<Album> DatabaseAccess::getAlbums()
{
    return std::list<Album>();
}

const std::list<Album> DatabaseAccess::getAlbumsOfUser(const User& user)
{
    return std::list<Album>();
}

void DatabaseAccess::createAlbum(const Album& album)
{
}

void DatabaseAccess::deleteAlbum(const std::string& albumName, int userId)
{
    std::string sqlStatement = "DELETE FROM ALBUMS WHERE NAME = '" + albumName + "' AND USER_ID = '" + std::to_string(userId) + "';";

    char* errMessage = nullptr;
    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
}

bool DatabaseAccess::doesAlbumExists(const std::string& albumName, int userId)
{
    return false;
}

Album DatabaseAccess::openAlbum(const std::string& albumName)
{
    return Album();
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
    //delete the allocated memory from THE ALBUM
}

void DatabaseAccess::printAlbums()
{
}

void DatabaseAccess::printUsers()
{
}

User DatabaseAccess::getUser(int userId)
{
    return User(1,"");
}

void DatabaseAccess::createUser(User& user)
{
    std::string sqlStatement = "INSERT INTO USERS (ID, NAME) VALUES ('" + std::to_string(user.getId()) + "', '" + user.getName() + "');";
    char* errMessage = nullptr;
    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
}

void DatabaseAccess::deleteUser(const User& user)
{
    std::string sqlStatement = "DELETE FROM USERS WHERE ID = '" + std::to_string(user.getId()) + "' AND NAME = '" + user.getName() + "');";
    char* errMessage = nullptr;
    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
}

bool DatabaseAccess::doesUserExists(int userId)
{
    return false;
}

int DatabaseAccess::countAlbumsOwnedOfUser(const User& user)
{
    return 0;
}

int DatabaseAccess::countAlbumsTaggedOfUser(const User& user)
{
    return 0;
}

int DatabaseAccess::countTagsOfUser(const User& user)
{
    return 0;
}

float DatabaseAccess::averageTagsPerAlbumOfUser(const User& user)
{
    return 0.0f;
}

User DatabaseAccess::getTopTaggedUser()
{
    return User(1, "");
}

Picture DatabaseAccess::getTopTaggedPicture()
{
    return Picture(1,"");
}

std::list<Picture> DatabaseAccess::getTaggedPicturesOfUser(const User& user)
{
    return std::list<Picture>();
}

void DatabaseAccess::addPictureToAlbumByName(const std::string& albumName, const Picture& picture)
{
}

void DatabaseAccess::removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName)
{
}

void DatabaseAccess::tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
    std::string sqlStatement = "SELECT id FROM pictures WHERE name = '" + pictureName + "';";

    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return;
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        int pictureId = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt); 

        sqlStatement = "INSERT INTO TAGS (PICTURE_ID, USER_ID) VALUES ('" + std::to_string(pictureId) + "', '" + std::to_string(userId) + "');";
        res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);

        if (res != SQLITE_OK)
        {
            std::cerr << "error: " << errMessage << std::endl;
            sqlite3_free(errMessage);
        }
    }
    else
    {
        sqlite3_finalize(stmt); 
        return;
    }
}

void DatabaseAccess::untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
    std::string sqlStatement = "SELECT id FROM pictures WHERE name = '" + pictureName + "';";

    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return;
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        int pictureId = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);

        sqlStatement = "DELETE FROM TAGS WHERE id = " + std::to_string(pictureId) + ";";
        res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
    }
    else
    {
        std::cerr << "error: picture with this name wasnt found" << std::endl;
    }
}
