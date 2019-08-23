#pragma once
#include "Data.h"
#include "MapTank.h"
#include "Logic.h"
#include "OPFile.h"
class Game:  public OPFile
{
public:
	bool WelcomeUI();
	bool InitTankAndBulletInfo();
	bool StartGame(int x);
private:
	void HomePage();
	void GameShows();
	void MapManage();
	/************************************
	* Method:    RecordManage
	* FullName:  RecordManage
	* Access:    public
	* Returns:   bool
	* Qualifier:
	************************************/
	bool RecordManage();
private:
	MapTank m_Map;
};

