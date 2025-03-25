#pragma once
#include "IDataAccess.h"
#include "User.h"
#include "Album.h"
#include "Picture.h"
#include "sqlite3.h"

class DatabaseAccess : public IDataAccess
{
public:
    const std::list<Album> getAlbums() override; //done
    const std::list<Album> getAlbumsOfUser(const User& user) override; //done
    void createAlbum(const Album& album) override; //done
    void deleteAlbum(const std::string& albumName, int userId) override; //done
    bool doesAlbumExists(const std::string& albumName, int userId) override; //done
    Album openAlbum(const std::string& albumName) override; //done
    void closeAlbum(Album& pAlbum) override; //done
    void printAlbums() override; //done

    // picture related
    void addPictureToAlbumByName(const std::string& albumName, const Picture& picture) override; //done needs review
    void removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName) override; //done needs review
    void tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId) override; //done
    void untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId) override; //done

    // user related
    void printUsers() override; //done
    User getUser(int userId) override; //done needs review
    void createUser(User& user) override; //done
    void deleteUser(const User& user) override; //done
    bool doesUserExists(int userId) override; //done

    // user statistics
    int countAlbumsOwnedOfUser(const User& user) override; //done
    int countAlbumsTaggedOfUser(const User& user) override;
    int countTagsOfUser(const User& user) override;
    float averageTagsPerAlbumOfUser(const User& user) override;

    // queries
    User getTopTaggedUser() override;
    Picture getTopTaggedPicture() override;
    std::list<Picture> getTaggedPicturesOfUser(const User& user) override;

    bool open() override; //done
    void close() override; //done
    void clear() override; //to do

private:
    sqlite3* db;


};

