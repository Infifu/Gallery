#include "AlbumManager.h"
#include <iostream>
#include "Constants.h"
#include "MyException.h"
#include "AlbumNotOpenException.h"
#include <Windows.h>
#include <sstream>


AlbumManager::AlbumManager(IDataAccess& dataAccess) :
    m_dataAccess(dataAccess), m_nextPictureId(100), m_nextUserId(200)
{
	// Left empty
	m_dataAccess.open();
}


void AlbumManager::printHelp() const
{
	std::cout << "Supported Album commands:" << std::endl;
	std::cout << "*************************" << std::endl;
	
	for (const struct CommandGroup& group : m_prompts) {
		std::cout << group.title << std::endl;
		std::string space(".  ");
		for (const struct CommandPrompt& command : group.commands) {
			space = command.type < 10 ? ".   " : ".  ";

			std::cout << command.type << space << command.prompt << std::endl;
		}
		std::cout << std::endl;
	}
}


// ******************* Album ******************* 
void AlbumManager::createAlbum(std::string userIdStr,std::string name)
{
	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) )
	{
		throw MyException("Error: Can't create album since there is no user with id [" + userIdStr+"]\n");
	}

	if ( m_dataAccess.doesAlbumExists(name,userId))
	{
		throw MyException("Error: Failed to create album, album with the same name already exists\n");
	}

	Album newAlbum(userId,name);
	m_dataAccess.createAlbum(newAlbum);

	std::cout << "Album [" << newAlbum.getName() << "] created successfully by user@" << newAlbum.getOwnerId() << std::endl;
}

void AlbumManager::openAlbum(std::string userIdStr, std::string name)
{
	if (isCurrentAlbumSet()) {
		closeAlbum();
	}

	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) ) {
		throw MyException("Error: Can't open album since there is no user with id @" + userIdStr + ".\n");
	}

	if ( !m_dataAccess.doesAlbumExists(name, userId) ) {
		throw MyException("Error: Failed to open album, since there is no album with name:"+name +".\n");
	}

	m_openAlbum = m_dataAccess.openAlbum(name);
    m_currentAlbumName = name;
	// success
	std::cout << "Album [" << name << "] opened successfully." << std::endl;
}

void AlbumManager::closeAlbum()
{
	refreshOpenAlbum();

	std::cout << "Album [" << m_openAlbum.getName() << "] closed successfully." << std::endl;
	m_dataAccess.closeAlbum(m_openAlbum);
	m_currentAlbumName = "";
}

void AlbumManager::deleteAlbum(std::string userIdStr,std::string albumName)
{
	int userId = std::stoi(userIdStr);
	if (!m_dataAccess.doesUserExists(userId)) {
		throw MyException("Error: There is no user with id @" + userIdStr +"\n");
	}

	if ( !m_dataAccess.doesAlbumExists(albumName, userId) ) {
		throw MyException("Error: Failed to delete album, since there is no album with name:" + albumName + ".\n");
	}

	// album exist, close album if it is opened
	if ( (isCurrentAlbumSet() ) &&
		 (m_openAlbum.getOwnerId() == userId && m_openAlbum.getName() == albumName) ) {

		closeAlbum();
	}

	m_dataAccess.deleteAlbum(albumName, userId);
	std::cout << "Album [" << albumName << "] @"<< userId <<" deleted successfully." << std::endl;
}

void AlbumManager::listAlbums()
{
	m_dataAccess.printAlbums();
}

std::string AlbumManager::listAlbumsOfUser(std::string userIdStr)
{
	std::stringstream ss;
	int userId = std::stoi(userIdStr);
	if (!m_dataAccess.doesUserExists(userId)) {
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}

	const User& user = m_dataAccess.getUser(userId);
	const std::list<Album>& albums = m_dataAccess.getAlbumsOfUser(user);

	for (const auto& album : albums)
	{
		ss <<"   + [" << album.getName() <<"] - created on "<< album.getCreationDate() << std::endl;
	}

	return ss.str();
}


// ******************* Picture ******************* 
void AlbumManager::addPictureToAlbum(std::string picName, std::string picPath)
{
	refreshOpenAlbum();

	if (m_openAlbum.doesPictureExists(picName) )
	{
		throw MyException("Error: Failed to add picture, picture with the same name already exists.\n");
	}
	
	Picture picture(++m_nextPictureId, picName);
	picture.setPath(picPath);

	m_dataAccess.addPictureToAlbumByName(m_openAlbum.getName(), picture);

	std::cout << "Picture [" << picture.getId() << "] successfully added to Album [" << m_openAlbum.getName() << "]." << std::endl;
}

void AlbumManager::removePictureFromAlbum(std::string picName)
{
	refreshOpenAlbum();

	if (!m_openAlbum.doesPictureExists(picName))
	{
		throw MyException("Error: There is no picture with name <" + picName + ">.\n");
	}

	auto picture = m_openAlbum.getPicture(picName);
	m_dataAccess.removePictureFromAlbumByName(m_openAlbum.getName(), picture.getName());
	std::cout << "Picture <" << picName << "> successfully removed from Album [" << m_openAlbum.getName() << "]." << std::endl;
}

std::string AlbumManager::listPicturesInAlbum()
{
	refreshOpenAlbum();
	std::stringstream ss;
	
	const std::list<Picture>& albumPictures = m_openAlbum.getPictures();
	for (auto iter = albumPictures.begin(); iter != albumPictures.end(); ++iter)
	{
		ss << iter->getPath() + "|";
	}
	return ss.str();
}

void AlbumManager::showPicture()
{
	refreshOpenAlbum();

	std::string picName = getInputFromConsole("Enter picture name: ");
	if ( !m_openAlbum.doesPictureExists(picName) ) {
		throw MyException("Error: There is no picture with name <" + picName + ">.\n");
	}
	
	auto pic = m_openAlbum.getPicture(picName);
	if ( !fileExistsOnDisk(pic.getPath()) ) {
		throw MyException("Error: Can't open <" + picName+ "> since it doesnt exist on disk.\n");
	}

	int option;
	std::cout << "Choose opening option: " << std::endl;
	std::cout << "1.Regular " << std::endl;
	std::cout << "2.Paint " << std::endl;
	std::cout << "3.IrfanView " << std::endl;
	std::cin >> option;
	std::string command;


	switch (option)
	{
	case 1:
		command = "explorer.exe " + pic.getPath();
		break;
	case 2:
		command = "mspaint.exe " + pic.getPath();
		break;
	case 3:
		command = "C:\\Program Files\\IrfanView\\i_view64.exe " + pic.getPath();
		break;
	default:
		throw MyException("Option is not valid");
		break;
	}

	STARTUPINFO si{ sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi;

	if (CreateProcess(
		NULL,               
		const_cast<char*>(command.c_str()),
		NULL,              
		NULL,               
		FALSE,              
		0,                  
		NULL,             
		NULL,               
		&si,               
		&pi                 
	))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

void AlbumManager::tagUserInPicture(std::string picName,std::string userIdStr)
{
	refreshOpenAlbum();

	if ( !m_openAlbum.doesPictureExists(picName) ) {
		throw MyException("Error: There is no picture with name <" + picName + ">.\n");
	}
	
	Picture pic = m_openAlbum.getPicture(picName);
	
	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) ) {
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}
	User user = m_dataAccess.getUser(userId);

	m_dataAccess.tagUserInPicture(m_openAlbum.getName(), pic.getName(), user.getId());
	std::cout << "User @" << userIdStr << " successfully tagged in picture <" << pic.getName() << "> in album [" << m_openAlbum.getName() << "]" << std::endl;
}


void AlbumManager::untagUserInPicture(std::string picName, std::string userIdStr)
{
	refreshOpenAlbum();

	if (!m_openAlbum.doesPictureExists(picName))
	{
		throw MyException("Error: There is no picture with name <" + picName + ">.\n");
	}

	Picture pic = m_openAlbum.getPicture(picName);

	int userId = stoi(userIdStr);
	if (!m_dataAccess.doesUserExists(userId))
	{
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}
	User user = m_dataAccess.getUser(userId);

	if (! pic.isUserTagged(user)) {
		throw MyException("Error: The user was not tagged! \n");
	}

	m_dataAccess.untagUserInPicture(m_openAlbum.getName(), pic.getName(), user.getId());
	std::cout << "User @" << userIdStr << " successfully untagged in picture <" << pic.getName() << "> in album [" << m_openAlbum.getName() << "]" << std::endl;

}

std::string AlbumManager::listUserTags(std::string picName)
{
	refreshOpenAlbum();
	std::stringstream ss;

	if ( !m_openAlbum.doesPictureExists(picName) )
	{
		throw MyException("Error: There is no picture with name <" + picName + ">.\n");
	}
	auto pic = m_openAlbum.getPicture(picName); 

	const std::set<int> users = pic.getUserTags();

	if ( 0 == users.size() )
	{
		throw MyException("Error: There is no user tagged in <" + picName + ">.\n");
	}

	std::cout << "Tagged users in picture <" << picName << ">:" << std::endl;
	for (const int user_id: users)
	{
		const User user = m_dataAccess.getUser(user_id);
		ss << user << std::endl;
	}
	
	return ss.str();
}


// ******************* User ******************* 
void AlbumManager::addUser()
{
	std::string name = getInputFromConsole("Enter user name: ");

	User user(++m_nextUserId,name);
	
	m_dataAccess.createUser(user);
	std::cout << "User " << name << " with id @" << user.getId() << " created successfully." << std::endl;
}


void AlbumManager::removeUser(std::string userIdStr)
{
	// get user name
	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) ) {
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}
	const User& user = m_dataAccess.getUser(userId);
	if (isCurrentAlbumSet() && userId == m_openAlbum.getOwnerId()) {
		closeAlbum();
	}

	m_dataAccess.deleteUser(user);
	std::cout << "User @" << userId << " deleted successfully." << std::endl;
}

void AlbumManager::listUsers()
{
	m_dataAccess.printUsers();	
}

void AlbumManager::userStatistics()
{
	std::string userIdStr = getInputFromConsole("Enter user id: ");
	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) ) {
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}

	const User& user = m_dataAccess.getUser(userId);

	std::cout << "user @" << userId << " Statistics:" << std::endl << "--------------------" << std::endl <<
		"  + Count of Albums Tagged: " << m_dataAccess.countAlbumsTaggedOfUser(user) << std::endl <<
		"  + Count of Tags: " << m_dataAccess.countTagsOfUser(user) << std::endl <<
		"  + Avarage Tags per Alboum: " << m_dataAccess.averageTagsPerAlbumOfUser(user) << std::endl <<
		"  + Amount of user's owned albums: " << m_dataAccess.countAlbumsOwnedOfUser(user) << std::endl;
}


// ******************* Queries ******************* 
void AlbumManager::topTaggedUser()
{
	const User& user = m_dataAccess.getTopTaggedUser();

	std::cout << "The top tagged user is: " << user.getName() << std::endl;
}

void AlbumManager::topTaggedPicture()
{
	const Picture& picture = m_dataAccess.getTopTaggedPicture();

	std::cout << "The top tagged picture is: " << picture.getName() << std::endl;
}

void AlbumManager::picturesTaggedUser()
{
	std::string userIdStr = getInputFromConsole("Enter user id: ");
	int userId = std::stoi(userIdStr);
	if ( !m_dataAccess.doesUserExists(userId) ) {
		throw MyException("Error: There is no user with id @" + userIdStr + "\n");
	}

	auto user = m_dataAccess.getUser(userId);

	auto taggedPictures = m_dataAccess.getTaggedPicturesOfUser(user);

	std::cout << "List of pictures that User@" << user.getId() << " tagged :" << std::endl;
	for (const Picture& picture: taggedPictures) {
		std::cout <<"   + "<< picture << std::endl;
	}
	std::cout << std::endl;
}


// ******************* Help & exit ******************* 
void AlbumManager::exit()
{
	std::exit(EXIT_SUCCESS);
}

void AlbumManager::help()
{
	system("CLS");
	printHelp();
}

std::string AlbumManager::getInputFromConsole(const std::string& message)
{
	std::string input;
	do {
		std::cout << message;
		std::getline(std::cin, input);
	} while (input.empty());
	
	return input;
}

bool AlbumManager::fileExistsOnDisk(const std::string& filename)
{
	struct stat buffer;   
	return (stat(filename.c_str(), &buffer) == 0); 
}

void AlbumManager::refreshOpenAlbum() {
	if (!isCurrentAlbumSet()) {
		throw AlbumNotOpenException();
	}
    m_openAlbum = m_dataAccess.openAlbum(m_currentAlbumName);
}

bool AlbumManager::isCurrentAlbumSet() const
{
    return !m_currentAlbumName.empty();
}

const std::vector<struct CommandGroup> AlbumManager::m_prompts  = {
	{
		"Supported Albums Operations:\n----------------------------",
		{
			{ CREATE_ALBUM        , "Create album" },
			{ OPEN_ALBUM          , "Open album" },
			{ CLOSE_ALBUM         , "Close album" },
			{ DELETE_ALBUM        , "Delete album" },
			{ LIST_ALBUMS         , "List albums" },
			{ LIST_ALBUMS_OF_USER , "List albums of user" }
		}
	},
	{
		"Supported Album commands (when specific album is open):",
		{
			{ ADD_PICTURE    , "Add picture." },
			{ REMOVE_PICTURE , "Remove picture." },
			{ SHOW_PICTURE   , "Show picture." },
			{ LIST_PICTURES  , "List pictures." },
			{ TAG_USER		 , "Tag user." },
			{ UNTAG_USER	 , "Untag user." },
			{ LIST_TAGS		 , "List tags." }
		}
	},
	{
		"Supported Users commands: ",
		{
			{ ADD_USER         , "Add user." },
			{ REMOVE_USER      , "Remove user." },
			{ LIST_OF_USER     , "List of users." },
			{ USER_STATISTICS  , "User statistics." },
		}
	},
	{
		"Supported Queries:",
		{
			{ TOP_TAGGED_USER      , "Top tagged user." },
			{ TOP_TAGGED_PICTURE   , "Top tagged picture." },
			{ PICTURES_TAGGED_USER , "Pictures tagged user." },
		}
	},
	{
		"Supported Operations:",
		{
			{ HELP , "Help (clean screen)" },
			{ EXIT , "Exit." },
		}
	}
};