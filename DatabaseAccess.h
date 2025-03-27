#pragma once
#include "IDataAccess.h"
#include "sqlite3.h"

class DatabaseAccess : public IDataAccess
{
public:
	bool open() override;
	void close() override;
	void clear() override;

	void closeAlbum(Album& pAlbum) override;
private:
	sqlite3* db;


};

