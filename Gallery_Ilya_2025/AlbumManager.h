#pragma once
#include <vector>
#include "Constants.h"
#include "MemoryAccess.h"
#include "Album.h"


class AlbumManager
{
public:
	AlbumManager(IDataAccess& dataAccess);
	void printHelp() const;

	using handler_func_t = void (AlbumManager::*)(void);    

public:
    int m_nextPictureId{};
    int m_nextUserId{};
    std::string m_currentAlbumName{};
	IDataAccess& m_dataAccess;
	Album m_openAlbum;

	void help();
	// albums management
	void createAlbum(std::string userIdStr, std::string name);
	void openAlbum(std::string userIdStr, std::string name);
	void closeAlbum();
	void deleteAlbum(std::string userIdStr, std::string albumName);
	void listAlbums();
	std::string listAlbumsOfUser(std::string userIdStr);

	// Picture management
	void addPictureToAlbum(std::string picName, std::string picPath);
	void removePictureFromAlbum(std::string picName);
	std::string listPicturesInAlbum();
	void showPicture();

	// tags related
	void tagUserInPicture(std::string picName, std::string userIdStr);
	void AlbumManager::untagUserInPicture(std::string picName, std::string userIdStr);
	std::string AlbumManager::listUserTags(std::string picName);

	// users management
	void addUser();
	void removeUser(std::string userIdStr);
	void listUsers();
	void userStatistics();

	void topTaggedUser();
	void topTaggedPicture();
	void picturesTaggedUser();
	void exit();

	std::string getInputFromConsole(const std::string& message);
	bool fileExistsOnDisk(const std::string& filename);
	void refreshOpenAlbum();
    bool isCurrentAlbumSet() const;

	static const std::vector<struct CommandGroup> m_prompts;
};

