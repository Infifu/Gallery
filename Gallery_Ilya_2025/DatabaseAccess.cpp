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
    DatabaseAccess::deleteQuery("PICTURES","","");
    DatabaseAccess::deleteQuery("ALBUMS","","");
    DatabaseAccess::deleteQuery("TAGS","","");
    DatabaseAccess::deleteQuery("USERS","","");
}

const std::list<Album> DatabaseAccess::getAlbums()
{
    std::vector<std::map<std::string, std::string>> selected;
    std::list<Album> albums;
    selected = DatabaseAccess::selectQuery("ALBUMS", "", "");
    for (auto& row : selected)
    {
        albums.push_back(Album(std::stoi(row.at("USER_ID")), row.at("NAME"), row.at("CREATION_DATE")));
    }
    return albums;
}

const std::list<Album> DatabaseAccess::getAlbumsOfUser(const User& user)
{
    std::vector<std::map<std::string, std::string>> selected;

    std::list<Album> albums;
    selected = DatabaseAccess::selectQuery("ALBUMS", "USER_ID",std::to_string(user.getId()));

    for (auto& row : selected)
    {
        albums.push_back(Album(std::stoi(row.at("USER_ID")), row.at("NAME"), row.at("CREATION_DATE")));
    }
    return albums;
}

void DatabaseAccess::createAlbum(const Album& album)
{
    std::map<std::string, std::string> values;
    values.insert({ "NAME",album.getName() });
    values.insert({ "CREATION_DATE",album.getCreationDate() });
    values.insert({ "USER_ID",std::to_string(album.getOwnerId()) });
    DatabaseAccess::insertQuery("ALBUMS", values);
}

void DatabaseAccess::deleteAlbum(const std::string& albumName, int userId)
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("ALBUMS", "USER_ID", std::to_string(userId));
    DatabaseAccess::deleteQuery("ALBUMS", "NAME", albumName);
    for (auto const& row : selected)
    {
        if (row.find("ALBUM_ID") != row.end())
            DatabaseAccess::deleteQuery("PICTURES", "ALBUM_ID", row.at("ALBUM_ID"));
    }
}

bool DatabaseAccess::doesAlbumExists(const std::string& albumName, int userId)
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("ALBUMS", "NAME", albumName);
    for (const auto& row : selected)
    {
        if (row.at("USER_ID") == std::to_string(userId))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

Album DatabaseAccess::openAlbum(const std::string& albumName)
{
    std::vector<std::map<std::string, std::string>> selected;
    std::vector<std::map<std::string, std::string>> tags;
    selected = DatabaseAccess::selectQuery("ALBUMS", "NAME", albumName);
    std::string albumID;
    Album album;
    
    for (const auto& row : selected)
    {
        albumID = row.at("ID");
        album.setName(row.at("NAME"));
        album.setOwner(std::stoi(row.at("USER_ID")));
        album.setCreationDate(row.at("CREATION_DATE"));
    }
    
    selected = DatabaseAccess::selectQuery("PICTURES", "ALBUM_ID", albumID);
    for (const auto& row : selected)
    {
        album.addPicture(Picture(std::stoi(row.at("ID")), row.at("NAME"), row.at("LOCATION"), row.at("CREATION_DATE")));
    }

    std::list<Picture> pics = album.getPictures();
    for (auto& pic : pics)
    {
        tags = DatabaseAccess::selectQuery("TAGS", "PICTURE_ID", std::to_string(pic.getId()));
        for (auto& tag : tags)
        {
            pic.tagUser(std::stoi(tag.at("USER_ID")));
            album.removePicture(pic.getName());
            album.addPicture(pic);
        }
    }
    return album;
}

void DatabaseAccess::closeAlbum(Album& pAlbum)
{
    pAlbum.setName("");
    pAlbum.setOwner(0);
    pAlbum.setCreationDate("");
}

std::string DatabaseAccess::printAlbums()
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("ALBUMS", "", "");
    std::stringstream ss;


    for (const auto& row : selected)
    {
        ss << Album(std::stoi(row.at("USER_ID")), row.at("NAME"), row.at("CREATION_DATE"));
    }

    return ss.str();
}

std::string DatabaseAccess::printUsers()
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("USERS", "", "");
    std::stringstream ss;


    for (const auto& row : selected)
    {
        ss<< User(std::stoi(row.at("ID")), row.at("NAME"));
    }
    return ss.str();
}

User DatabaseAccess::getUser(int userId)
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("USERS", "ID", std::to_string(userId));

    for (const auto& row : selected)
    {
        return User(std::stoi(row.at("ID")), row.at("NAME"));
    }
}

void DatabaseAccess::createUser(User& user)
{
    std::map<std::string, std::string> values;
    values.insert({ "ID",std::to_string(user.getId()) });
    values.insert({ "NAME",user.getName() });
    DatabaseAccess::insertQuery("USERS", values);
}

void DatabaseAccess::deleteUser(const User& user)
{
    DatabaseAccess::deleteQuery("USERS", "ID", std::to_string(user.getId()));
    DatabaseAccess::deleteQuery("ALBUMS", "USER_ID", std::to_string(user.getId()));
}

bool DatabaseAccess::doesUserExists(int userId)
{
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("USERS", "ID", std::to_string(userId));
    if (!selected.empty())
        return true;
    else
        return false;
}

int DatabaseAccess::countAlbumsOwnedOfUser(const User& user)
{
    std::list<Album> albums = getAlbumsOfUser(user);
    return albums.size();
}

int DatabaseAccess::countAlbumsTaggedOfUser(const User& user)
{
    int albumsCount = 0;
    std::set<int> albumsID;
    std::vector<int> picturesID;

    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("TAGS", "USER_ID", std::to_string(user.getId()));
    for (const auto& row : selected)
    {
        picturesID.push_back(std::stoi(row.at("PICTURE_ID")));
    }

    for (auto const& picture : picturesID)
    {
        selected = DatabaseAccess::selectQuery("PICTURES", "ID", std::to_string(picture));
        for (const auto& row : selected)
        {
            albumsID.insert(std::stoi(row.at("ALBUM_ID")));
        }
    }
    return albumsID.size();
}



int DatabaseAccess::countTagsOfUser(const User& user)
{
    int tagOfUser = 0;
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("TAGS", "USER_ID", std::to_string(user.getId()));

    for (const auto& row : selected)
    {
        tagOfUser++;
    }
    return tagOfUser;
}

float DatabaseAccess::averageTagsPerAlbumOfUser(const User& user)
{

    int albumsTaggedCount = countAlbumsTaggedOfUser(user);

    if (0 == albumsTaggedCount)
    {
        return 0;
    }

    return static_cast<float>(countTagsOfUser(user)) / albumsTaggedCount;
}

User DatabaseAccess::getTopTaggedUser()
{
    std::vector<std::map<std::string, std::string>> selected;
    int mostTags = 0;
    int currentTags = 0;
    int ID = 0;
    std::string name;
    
    selected = DatabaseAccess::selectQuery("USERS", "","");

    for (const auto& row : selected)
    {
        currentTags = countTagsOfUser(User(std::stoi(row.at("ID")), row.at("NAME")));
        if (currentTags > mostTags)
        {
            mostTags = currentTags;
            name = row.at("NAME");
            ID = std::stoi(row.at("ID"));
        }
    }
    return User(ID, name);
}

Picture DatabaseAccess::getTopTaggedPicture()
{
    std::string sqlStatement = "SELECT PICTURE_ID, COUNT(*) AS count FROM tags GROUP BY PICTURE_ID ORDER BY count DESC LIMIT 1;";
    std::vector<std::map<std::string, std::string>> selected;
    sqlite3_stmt* stmt;
    std::string pictureID;

    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "Error has occured while preparing the statement" << std::endl;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        pictureID = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        selected = DatabaseAccess::selectQuery("PICTURES", "ID", pictureID);
        for (const auto& row : selected)
        {
            return Picture(std::stoi(pictureID), row.at("NAME"), row.at("LOCATION"), row.at("CREATION_DATE"));
        }
    }
    throw MyException("No tagged picture found");
}


std::list<Picture> DatabaseAccess::getTaggedPicturesOfUser(const User& user)
{
    std::vector<std::map<std::string, std::string>> selected;
    std::list<Picture> pictures;
    std::string pictureID;
    selected = DatabaseAccess::selectQuery("TAGS", "USER_ID", std::to_string(user.getId()));
    

    for (const auto& row : selected)
    {
        pictureID = row.at("PICTURE_ID");
    }

    selected = DatabaseAccess::selectQuery("PICTURES", "ID", pictureID);

    for (const auto& row : selected)
    {
        pictures.push_back(Picture(std::stoi(pictureID), row.at("NAME"), row.at("LOCATION"), row.at("CREATION_DATE")));
    }

    return pictures;
}

std::vector<std::map<std::string, std::string>> DatabaseAccess::selectQuery(const std::string& table, std::string column, std::string argument)
{
    std::vector<std::map<std::string, std::string>> selected;
    std::string sqlStatement;
    sqlite3_stmt* stmt;

    if (argument.empty() && column.empty())
        sqlStatement = "SELECT * FROM " + table;
    else 
        sqlStatement = "SELECT * FROM " + table + " WHERE " + column + " = '" + argument + "';";

    int res = sqlite3_prepare_v2(db, sqlStatement.c_str(), -1, &stmt, nullptr);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: Failed to prepare statement" << std::endl;
        return {}; 
    }

    while ((res = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        std::map<std::string, std::string> row;
        int colCount = sqlite3_column_count(stmt);
        for (int i = 0; i < colCount; i++)
        {
            std::string column_name = sqlite3_column_name(stmt, i);

            if (sqlite3_column_type(stmt, i) == SQLITE_TEXT)
            {
                row[column_name] = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            }
            else if (sqlite3_column_type(stmt, i) == SQLITE_INTEGER)
            {
                row[column_name] = std::to_string(sqlite3_column_int(stmt, i));
            }
        }
        selected.push_back(row);
    }

    sqlite3_finalize(stmt);
    return selected;
}

bool DatabaseAccess::insertQuery(const std::string& table, std::map<std::string, std::string> values)
{
    std::string sqlStatement;
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;

    if (table == "ALBUMS")
    {
        sqlStatement = "INSERT INTO ALBUMS (NAME, CREATION_DATE, USER_ID) VALUES (";
        sqlStatement += "'" + values.at("NAME") + "', '" + values.at("CREATION_DATE") + "', " + values.at("USER_ID") + ");";
    }
    else if (table == "PICTURES")
    {
        sqlStatement = "INSERT INTO PICTURES (NAME, LOCATION, CREATION_DATE, ALBUM_ID) VALUES (";
        sqlStatement += "'" + values.at("NAME") + "', '" + values.at("LOCATION") + "', '" + values.at("CREATION_DATE") + "', " + values.at("ALBUM_ID") + ");";
    }
    else if (table == "TAGS")
    {
        sqlStatement = "INSERT INTO TAGS (PICTURE_ID, USER_ID) VALUES (";
        sqlStatement += values.at("PICTURE_ID") + ", " + values.at("USER_ID") + ");";
    }
    else if (table == "USERS")
    {
        sqlStatement = "INSERT INTO USERS (ID, NAME) VALUES (";
        sqlStatement += values.at("ID") + ", '" + values.at("NAME") + "');";
    }

    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        return false;
    }
    return true;
}

bool DatabaseAccess::deleteQuery(const std::string& table, std::string column, std::string argument)
{
    std::string sqlStatement;
    sqlite3_stmt* stmt;
    char* errMessage = nullptr;

    if (column.empty() && argument.empty())
        sqlStatement = "DELETE FROM " + table + ";";
    else
        sqlStatement = "DELETE FROM " + table + " WHERE " + column + " = '" + argument + "';";

    int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &errMessage);

    if (res != SQLITE_OK)
    {
        std::cerr << "error: " << errMessage << std::endl;
        sqlite3_free(errMessage);
        return false;
    }
    return true;
}


void DatabaseAccess::addPictureToAlbumByName(const std::string& albumName, const Picture& picture)
{
    int albumID = 0;
    std::vector<std::map<std::string, std::string>> selected;
    std::map<std::string, std::string> values;
    selected = DatabaseAccess::selectQuery("ALBUMS", "NAME", albumName);

    for (const auto& row : selected)
    {
        albumID = std::stoi(row.at("ID"));
        values.insert({ "NAME",picture.getName() });
        values.insert({ "LOCATION",picture.getPath() });
        values.insert({ "CREATION_DATE",picture.getCreationDate() });
        values.insert({ "ALBUM_ID",std::to_string(albumID) });
        break;
    }
    DatabaseAccess::insertQuery("PICTURES", values);
}

void DatabaseAccess::removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName)
{
    std::string albumID;
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("ALBUMS", "NAME", albumName);

    for (const auto& row : selected)
    {
        albumID = row.at("ID");
    }

    DatabaseAccess::deleteQuery("PICTURES", "ALBUM_ID", albumID);
}

void DatabaseAccess::tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
    std::string pictureID;
    std::vector<std::map<std::string, std::string>> selected;
    std::map<std::string, std::string> values;
    selected = DatabaseAccess::selectQuery("PICTURES", "NAME", pictureName);

    for (const auto& row : selected)
    {
        pictureID = row.at("ID");
        break;
    }

    values.insert({ "PICTURE_ID",pictureID });
    values.insert({ "USER_ID",std::to_string(userId)});
    DatabaseAccess::insertQuery("TAGS", values);
}

void DatabaseAccess::untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId)
{
    std::string pictureID;
    std::vector<std::map<std::string, std::string>> selected;
    selected = DatabaseAccess::selectQuery("PICTURES", "NAME", pictureName);

    for (const auto& row : selected)
    {
        pictureID = row.at("ID");
    }

    DatabaseAccess::deleteQuery("TAGS", "ID", pictureID);
}
