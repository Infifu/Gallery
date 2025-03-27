#pragma once
#include "IDataAccess.h"
#include "User.h"
#include "Album.h"
#include "Picture.h"
#include "sqlite3.h"

class DatabaseAccess : public IDataAccess
{
public:
    const std::list<Album> getAlbums() override;
    const std::list<Album> getAlbumsOfUser(const User& user) override;
    void createAlbum(const Album& album) override;
    void deleteAlbum(const std::string& albumName, int userId) override; //done
    bool doesAlbumExists(const std::string& albumName, int userId) override;
    Album openAlbum(const std::string& albumName) override;
    void closeAlbum(Album& pAlbum) override; //done
    void printAlbums() override;

    // picture related
    void addPictureToAlbumByName(const std::string& albumName, const Picture& picture) override;
    void removePictureFromAlbumByName(const std::string& albumName, const std::string& pictureName) override;
    void tagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId) override; //in work rn
    void untagUserInPicture(const std::string& albumName, const std::string& pictureName, int userId) override; //in work rn

    // user related
    void printUsers() override;
    User getUser(int userId) override;
    void createUser(User& user) override; //done
    void deleteUser(const User& user) override; //done
    bool doesUserExists(int userId) override;

    // user statistics
    int countAlbumsOwnedOfUser(const User& user) override;
    int countAlbumsTaggedOfUser(const User& user) override;
    int countTagsOfUser(const User& user) override;
    float averageTagsPerAlbumOfUser(const User& user) override;

    // queries
    User getTopTaggedUser() override;
    Picture getTopTaggedPicture() override;
    std::list<Picture> getTaggedPicturesOfUser(const User& user) override;

    bool open() override; //done
    void close() override; //done
    void clear() override; //done

private:
	sqlite3* db;


};

