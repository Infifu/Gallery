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
    std::list<Album> albums;
    std::string sqlStatement = "SELECT * FROM ALBUMS;";
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string creationDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int user_ID = sqlite3_column_int(stmt, 3);
        albums.push_back(Album(user_ID, name, creationDate));
    }

    sqlite3_finalize(stmt);
    return albums;
}

const std::list<Album> DatabaseAccess::getAlbumsOfUser(const User& user)
{
    std::list<Album> albums;
    std::string sqlStatement = "SELECT * FROM ALBUMS WHERE USER_ID = " + std::to_string(user.getId()) + ";";
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string creationDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int user_ID = sqlite3_column_int(stmt, 3);
        albums.push_back(Album(user_ID, name, creationDate));
    }

    sqlite3_finalize(stmt);
    return albums;
}

void DatabaseAccess::createAlbum(const Album& album)
{
    std::string sqlStatement = "INSERT INTO ALBUMS (NAME, CREATION_DATE, USER_ID) VALUES ('" + album.getName() + "', '" + album.getCreationDate() + "', " + std::to_string(album.getOwnerId()) + ");";
    char* errMessage = nullptr;
    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);
    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
    }
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
    std::string sqlStatement = "SELECT * FROM ALBUMS WHERE name = '" + albumName + "';";

    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return false;
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        return true;
    }
    else
    {
        sqlite3_finalize(stmt);
        return false;
    }
}

Album DatabaseAccess::openAlbum(const std::string& albumName)
{
    std::string sqlStatement = "SELECT * FROM ALBUMS WHERE name = '" + albumName + "';";

    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return Album();
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        int userID = sqlite3_column_int(stmt, 4);
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string creation_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        sqlite3_finalize(stmt);
        return Album(userID, name, creation_date);
    }
    sqlite3_finalize(stmt);
    return Album();
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
    //delete the allocated memory from THE ALBUM
}

void DatabaseAccess::printAlbums()
{
    std::string sqlStatement = "SELECT * FROM ALBUMS;";
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return;
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int userID = sqlite3_column_int(stmt, 4);
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string creation_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::cout << Album(userID, name, creation_date) << std::endl;
    }

    sqlite3_finalize(stmt);
    return;
}

void DatabaseAccess::printUsers()
{
    std::string sqlStatement = "SELECT * FROM USERS;";
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return;
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int userID = sqlite3_column_int(stmt, 0);
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::cout << User(userID, name) << std::endl;
    }

    sqlite3_finalize(stmt);
    return;
}

User DatabaseAccess::getUser(int userId)
{
    std::string sqlStatement = ("SELECT * FROM USERS WHERE ID = " + std::to_string(userId));
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return User(-1, "ERROR");
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        sqlite3_finalize(stmt);
        return User(userId, name);
    }
    return User(-1, "ERROR");
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
    std::string sqlStatement = "SELECT * FROM USERS WHERE ID = " + std::to_string(userId) + ";";

    sqlite3_stmt* stmt;
    char* errMessage = nullptr;
    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return false;
    }

    res = sqlite3_step(stmt);
    if (res == SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        return true;
    }
    else
    {
        sqlite3_finalize(stmt);
        return false;
    }
}

int DatabaseAccess::countAlbumsOwnedOfUser(const User& user)
{
    std::list<Album> albums = getAlbumsOfUser(user);
    return albums.size();
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
    return Picture(1, "");
}

std::list<Picture> DatabaseAccess::getTaggedPicturesOfUser(const User& user)
{
    return std::list<Picture>();
}

void DatabaseAccess::addPictureToAlbumByName(const std::string& albumName, const Picture& picture)
{
    std::string sqlStatement = "SELECT * FROM ALBUMS WHERE NAME = '" + albumName + "';";

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
        int albumID = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);

        sqlStatement = "INSERT INTO PICTURES (NAME,LOCATION,CREATION_DATE,ALBUM_ID) VALUES (";
        sqlStatement += "'" + picture.getName() + "', '" + picture.getPath() + "', '" + picture.getCreationDate() + "', " + std::to_string(picture.getId()) + ");";

        res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

        if (res != SQLITE_OK)
        {
            std::cerr << "error: Failed to prepare statement" << std::endl;
            return;
        }
    }
}

void DatabaseAccess::removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName)
{
    std::string sqlStatement = "SELECT * FROM ALBUMS WHERE NAME = '" + albumName + "';";

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
        int albumID = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);

        //find the pictures with matching albumID
        sqlStatement = "DELETE FROM PICTURES WHERE ID = " + std::to_string(albumID) + " AND NAME = '" + pictureName + "';";
        res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

        if (res != SQLITE_OK)
        {
            std::cerr << "error: Failed to prepare statement" << std::endl;
            return;
        }
        sqlite3_finalize(stmt);
    }
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
