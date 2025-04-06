#include <windows.h>
#include "AlbumManager.h"
#include "DataBaseAccess.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

bool keepListening = true;

std::string* CreateAlbum(const std::string& buffer, AlbumManager& albumManager);
std::string* OpenAlbum(const std::string& buffer, AlbumManager& albumManager);
std::string* CloseAlbum(AlbumManager& albumManager);
std::string* DeleteAlbum(const std::string& buffer, AlbumManager& albumManager);
std::string* PrintAlbums(AlbumManager& albumManager);
std::string* ListAlbumsOfUser(const std::string& buffer, AlbumManager& albumManager);
std::string* AddPictureToAlbum(const std::string& buffer, AlbumManager& albumManager);
std::string* RemovePictureFromAlbum(const std::string& buffer, AlbumManager& albumManager);
std::string* ListPicturesInAlbum(AlbumManager& albumManager);
std::string* TagUserInPicture(const std::string& buffer, AlbumManager& albumManager);
std::string* UntagUserInPicture(const std::string& buffer, AlbumManager& albumManager);
std::string* ListUserTags(const std::string& buffer, AlbumManager& albumManager);
std::string* CreateUser(const std::string& buffer, AlbumManager& albumManager);
std::string* RemoveUser(const std::string& buffer, AlbumManager& albumManager);
std::string* PrintUsers(AlbumManager& albumManager);

std::string* requestHandler(std::string buffer, AlbumManager& albumManager)
{
    std::string* answer = nullptr;
    try
    {
        std::string codeStr;
        codeStr += buffer[0];
        codeStr += buffer[1];
        int code = std::stoi(codeStr);

        switch (code)
        {
        case 1:
            answer = CreateAlbum(buffer, albumManager);
            break;
        case 2:
            answer = OpenAlbum(buffer, albumManager);
            break;
        case 3:
            answer = CloseAlbum(albumManager);
            break;
        case 4:
            answer = DeleteAlbum(buffer, albumManager);
            break;
        case 5:
            answer = PrintAlbums(albumManager);
            break;
        case 6:
            answer = ListAlbumsOfUser(buffer, albumManager);
            break;
        case 7:
            answer = AddPictureToAlbum(buffer, albumManager);
            break;
        case 8:
            answer = RemovePictureFromAlbum(buffer, albumManager);
            break;
        case 10:
            answer = ListPicturesInAlbum(albumManager);
            break;
        case 11:
            answer = TagUserInPicture(buffer, albumManager);
            break;
        case 12:
            answer = UntagUserInPicture(buffer, albumManager);
            break;
        case 13:
            answer = ListUserTags(buffer, albumManager);
            break;
        case 14:
            answer = CreateUser(buffer, albumManager);
            break;
        case 15:
            answer = RemoveUser(buffer, albumManager);
            break;
        case 16:
            answer = PrintUsers(albumManager);
            break;
        default:
            answer = new std::string("1");
            break;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
        answer = new std::string("1");
    }

    return answer;
}

std::string* CreateAlbum(const std::string& buffer, AlbumManager& albumManager)
{
    std::string usernameID;
    std::string lengthStr;
    std::string albumName;
    std::string nameLengthStr;
    int length;
    int namelength;

    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        usernameID += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    nameLengthStr += buffer[nameLengthIndex];
    nameLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(nameLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        albumName += buffer[i];
    }

    albumManager.createAlbum(usernameID, albumName);
    return new std::string("0");
}

std::string* OpenAlbum(const std::string& buffer, AlbumManager& albumManager)
{
    std::string usernameID;
    std::string lengthStr;
    std::string albumName;
    std::string nameLengthStr;
    int length;
    int namelength;

    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        usernameID += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    nameLengthStr += buffer[nameLengthIndex];
    nameLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(nameLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        albumName += buffer[i];
    }

    albumManager.openAlbum(usernameID, albumName);
    return new std::string("0");
}

std::string* CloseAlbum(AlbumManager& albumManager)
{
    albumManager.closeAlbum();
    return new std::string("0");
}

std::string* DeleteAlbum(const std::string& buffer, AlbumManager& albumManager)
{
    std::string usernameID;
    std::string lengthStr;
    std::string albumName;
    std::string nameLengthStr;
    int length;
    int namelength;

    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        usernameID += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    nameLengthStr += buffer[nameLengthIndex];
    nameLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(nameLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        albumName += buffer[i];
    }

    albumManager.deleteAlbum(usernameID, albumName);
    return new std::string("0");
}

std::string* PrintAlbums(AlbumManager& albumManager)
{
    std::string response = albumManager.m_dataAccess.printAlbums();
    return new std::string(response);
}

std::string* ListAlbumsOfUser(const std::string& buffer, AlbumManager& albumManager)
{
    std::string usernameID;
    std::string lengthStr;
    int length;
    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        usernameID += buffer[i];
    }

    std::string response = albumManager.listAlbumsOfUser(usernameID);
    return new std::string(response);
}

std::string* AddPictureToAlbum(const std::string& buffer, AlbumManager& albumManager)
{
    std::string Name;
    std::string nameStr;
    std::string path;
    std::string PathLengthStr;
    int length;
    int namelength;

    nameStr += buffer[3];
    nameStr += buffer[4];
    length = std::stoi(nameStr);
    for (int i = 6; i < length + 6; i++)
    {
        Name += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    PathLengthStr += buffer[nameLengthIndex];
    PathLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(PathLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        path += buffer[i];
    }

    albumManager.addPictureToAlbum(Name, path);
    return new std::string("0");
}

std::string* RemovePictureFromAlbum(const std::string& buffer, AlbumManager& albumManager)
{
    std::string picName;
    std::string lengthStr;
    int length;
    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        picName += buffer[i];
    }
    albumManager.removePictureFromAlbum(picName);
    return new std::string("0");
}

std::string* ListPicturesInAlbum(AlbumManager& albumManager)
{
    std::string response = albumManager.listPicturesInAlbum();
    return new std::string(response);
}

std::string* TagUserInPicture(const std::string& buffer, AlbumManager& albumManager)
{
    std::string Name;
    std::string nameStr;
    std::string userID;
    std::string IDLengthStr;
    int length;
    int namelength;

    nameStr += buffer[3];
    nameStr += buffer[4];
    length = std::stoi(nameStr);
    for (int i = 6; i < length + 6; i++)
    {
        Name += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    IDLengthStr += buffer[nameLengthIndex];
    IDLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(IDLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        userID += buffer[i];
    }

    albumManager.tagUserInPicture(Name, userID);
    return new std::string("0");
}

std::string* UntagUserInPicture(const std::string& buffer, AlbumManager& albumManager)
{
    std::string Name;
    std::string nameStr;
    std::string userID;
    std::string IDLengthStr;
    int length;
    int namelength;

    nameStr += buffer[3];
    nameStr += buffer[4];
    length = std::stoi(nameStr);
    for (int i = 6; i < length + 6; i++)
    {
        Name += buffer[i];
    }

    int nameLengthIndex = 6 + length + 1;
    IDLengthStr += buffer[nameLengthIndex];
    IDLengthStr += buffer[nameLengthIndex + 1];
    namelength = std::stoi(IDLengthStr);

    int albumStartIndex = nameLengthIndex + 3;
    for (int i = albumStartIndex; i < albumStartIndex + namelength; i++)
    {
        userID += buffer[i];
    }

    albumManager.untagUserInPicture(Name, userID);
    return new std::string("0");
}

std::string* ListUserTags(const std::string& buffer, AlbumManager& albumManager)
{
    std::string Name;
    std::string nameStr;
    int length;

    nameStr += buffer[3];
    nameStr += buffer[4];
    length = std::stoi(nameStr);
    for (int i = 6; i < length + 6; i++)
    {
        Name += buffer[i];
    }

    std::string response = albumManager.listUserTags(Name);
    return new std::string(response);
}

std::string* CreateUser(const std::string& buffer, AlbumManager& albumManager)
{
    std::string username;
    std::string lengthStr;
    int length;
    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        username += buffer[i];
    }
    User user(++albumManager.m_nextUserId, username);
    albumManager.m_dataAccess.createUser(user);
    return new std::string("0");
}

std::string* RemoveUser(const std::string& buffer, AlbumManager& albumManager)
{
    std::string usernameID;
    std::string lengthStr;
    int length;
    lengthStr += buffer[3];
    lengthStr += buffer[4];
    length = std::stoi(lengthStr);
    for (int i = 6; i < length + 6; i++)
    {
        usernameID += buffer[i];
    }

    albumManager.removeUser(usernameID);
    return new std::string("0");
}

std::string* PrintUsers(AlbumManager& albumManager)
{
    std::string response = albumManager.m_dataAccess.printUsers();
    return new std::string(response);
}

int main()
{
    const char* pipeName = "\\\\.\\pipe\\galleryPIPE";

    HANDLE hPipe = CreateFileA(
        pipeName,               
        GENERIC_READ | GENERIC_WRITE, 
        0,                      
        NULL,                  
        OPEN_EXISTING,          
        0,                      
        NULL                   
    );

    if (hPipe == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to connect to pipe. Error: " << GetLastError() << std::endl;
        return 1;
    }

    std::cout << "Connected to C# server!" << std::endl;

    char buffer[1024];
    DWORD bytesRead;

    DatabaseAccess dataAccess;
    AlbumManager albumManager(dataAccess);

    while (true)
    {
        BOOL success = ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL);

        if (!success || bytesRead == 0)
        {
            std::cerr << "Failed to read from pipe. Error: " << GetLastError() << std::endl;
            break;
        }

        buffer[bytesRead] = '\0';
        std::cout << "Received from C#: " << buffer << std::endl;

        if (std::string(buffer) == "quit") break;

        std::string* response = requestHandler(std::string(buffer), albumManager);
        DWORD BytesWritten, RequestBytes;
        RequestBytes = response->length() + 1; 

        BOOL bResult = WriteFile(            
            hPipe,                           
            response->c_str(),             
            RequestBytes,                    
            &BytesWritten,                  
            NULL);                           

        if (!bResult || RequestBytes != BytesWritten)
        {
            _tprintf(_T("WriteFile failed w/err 0x%08lx\n"), GetLastError());
        }

        _tprintf(_T("Sends %ld bytes; Message: \"%s\"\n"),
            BytesWritten, response->c_str());

        delete response; 

        std::cout << "Sent response to C#." << std::endl;
    }

    CloseHandle(hPipe);
    return 0;
}