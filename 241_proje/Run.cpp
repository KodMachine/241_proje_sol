#include "Run.h"


Run::Run()
{
}

void Run::moveEnemy(Object* &v,bool** map)
{
	if(v->getMoveType()==2 )
	{
		//Vertical
		rlutil::locate(v->getLocationX(), v->getLocationY());
		std::cout << " ";
		if (map[v->getLocationX() - 5][v->getLocationY() - v->getStep() - 5])
		{
			v->setLocationX(v->getLocationX());
			v->setLocationY(v->getLocationY() - v->getStep() );
			v->draw();
		}
		else
		{
			v->setStep(v->getStep()*-1);
			v->draw();
		}
	}
	if (v->getMoveType() == 0)
	{
		//Trap
		rlutil::locate(v->getLocationX(), v->getLocationY());
		v->draw();
	}
	else if(v->getMoveType() == 3)
	{
		//Horizontal
		rlutil::locate(v->getLocationX(), v->getLocationY());
		std::cout << " ";
		if (map[v->getLocationX() -v->getStep() -5 - v->getStep()][v->getLocationY() -5 ])
		{
			v->setLocationX(v->getLocationX() - v->getStep() );
			v->setLocationY(v->getLocationY());
			v->draw();
		}
		else
		{
			v->setStep(v->getStep() * -1);
			v->draw();
		}
	}
}

void Run::movePlayer(Object*& v, bool** map, int i)
{
	rlutil::locate(v->getLocationX(), v->getLocationY());
	std::cout << " ";
	if (i == rlutil::KEY_UP)
	{
		if (map[v->getLocationX() - 5][v->getLocationY() - 5 - 1])
		{
			v->setLocationX(v->getLocationX());
			v->setLocationY(v->getLocationY()-1);
			v->draw();
		}
		else
		{
			v->draw();
		}
	}

	else if (i == rlutil::KEY_RIGHT)
	{
		if (map[v->getLocationX() - 5 +1 ][v->getLocationY() - 5 ])
		{
			v->setLocationX(v->getLocationX() +1);
			v->setLocationY(v->getLocationY());
			v->draw();
		}
		else
		{
			v->draw();
		}
	}
	else if (i == rlutil::KEY_LEFT)
	{
		if (map[v->getLocationX() - 5 -1 ][v->getLocationY() - 5])
		{
			v->setLocationX(v->getLocationX() -1);
			v->setLocationY(v->getLocationY());
			v->draw();
		}
		else
		{
			v->draw();
		}
	}
	else if (i == rlutil::KEY_DOWN)
	{
		if (map[v->getLocationX() - 5][v->getLocationY() - 5 + 1])
		{
			v->setLocationX(v->getLocationX());
			v->setLocationY(v->getLocationY() + 1);
			v->draw();
		}
		else
		{
			v->draw();
		}
	}
	else {
		v->draw();
	}
}

void Run::play()
{
	rlutil::CursorHider curs;
	level.playIntro();
	level.getInfo();
	bool jumped = false;
	bool jump = false;
	while (true)
	{
		level.drawMap();
		//move loop with gravity etc.
		while ((!level.isFinish(level.p.getLocationX(), level.p.getLocationY())) && level.p.getAlive())
		{
			rlutil::msleep(75);
			if (kbhit())
			{
				int i = rlutil::getkey();
				//if jumped
				if (i == rlutil::KEY_UP)
				{
					jump = true;
					//rising
					for (int k = 0; k < 5; k++)
					{
						rlutil::msleep(75);
						movePlayer(level.objects[0], level.map, rlutil::KEY_UP);
						//move all other objects
						for (Object* x : level.objects)
						{
							if (x->getMoveType() == 1)
								continue;
							else
								moveEnemy(x, level.map);
							//check if player dead
							if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
							{
								level.p.setAlive(false);
								level.p.death();
							}
						}
						//if jumped left and right movement
						if (kbhit())
						{
							i = rlutil::getkey();
							if (i == rlutil::KEY_LEFT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);
									//check if player dead
									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
							else if (i == rlutil::KEY_RIGHT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_RIGHT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);
									//check if player dead
									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
						}
					}
					//fall
					while (level.map[level.p.getLocationX() - 5][level.p.getLocationY() - 5 + 1])
					{
						rlutil::msleep(75);
						movePlayer(level.objects[0], level.map, rlutil::KEY_DOWN);
						//move all other objects
						for (Object* x : level.objects)
						{
							if (x->getMoveType() == 1)
								continue;
							else
								moveEnemy(x, level.map);
							//check if player dead
							if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
							{
								level.p.setAlive(false);
								level.p.death();
							}
						}
						if (kbhit())
						{
							i = rlutil::getkey();
							if (i == rlutil::KEY_LEFT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);
									//check if player dead
									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
							else if (i == rlutil::KEY_RIGHT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_RIGHT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);
									//check if player dead
									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
						}
					}
				}
				//not jumped
				else
				{
					movePlayer(level.objects[0], level.map, i);
					//move all other objects
					for (Object* x : level.objects)
					{
						if (x->getMoveType() == 1)
							continue;
						//check if player dead
						if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
						{
							level.p.setAlive(false);
							level.p.death();
						}
					}
					while (level.map[level.p.getLocationX() - 5][level.p.getLocationY() - 5 + 1])
					{
						rlutil::msleep(75);
						movePlayer(level.objects[0], level.map, rlutil::KEY_DOWN);
						//move all other objects
						for (Object* x : level.objects)
						{
							if (x->getMoveType() == 1)
								continue;
							else
								moveEnemy(x, level.map);
							//check if player dead
							if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
							{
								level.p.setAlive(false);
								level.p.death();
							}
						}
						if (kbhit())
						{
							i = rlutil::getkey();
							if (i == rlutil::KEY_LEFT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);
									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
							else if (i == rlutil::KEY_RIGHT)
							{
								rlutil::msleep(75);
								movePlayer(level.objects[0], level.map, rlutil::KEY_RIGHT);
								//move all other objects
								for (Object* x : level.objects)
								{
									if (x->getMoveType() == 1)
										continue;
									else
										moveEnemy(x, level.map);

									if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
									{
										level.p.setAlive(false);
										level.p.death();
									}
								}
							}
						}
					}
				}
			}
			//move all other objects
			for (Object* x : level.objects)
			{
				if (x->getMoveType() == 1)
					continue;
				else
					moveEnemy(x, level.map);
				//check if player dead
				if (level.p.getLocationX() == x->getLocationX() && level.p.getLocationY() == x->getLocationY())
				{
					level.p.setAlive(false);
					level.p.death();
				}
			}
		}
		
		level.p.setAlive(true);
	}
	
}

void Run::runLevel_1(Level_1 level)
{
}

