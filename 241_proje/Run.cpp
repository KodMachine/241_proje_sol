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
}

void Run::play()
{
	level.drawMap();
	// Printing elements of an array using 
	// foreach loop 
	bool jumped = false;
	rlutil::CursorHider curs;
	bool jump = false;
	while (!level.isFinish(level.p.getLocationX(),level.p.getLocationY()))
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
					//if jumped left and right movement
					if (kbhit())
					{
						i = rlutil::getkey();
						if(i == rlutil::KEY_LEFT)
						{
							rlutil::msleep(75);
							movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
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
				//fall
				while (level.map[level.p.getLocationX()-5][level.p.getLocationY()-5+1])
				{
					rlutil::msleep(75);
					movePlayer(level.objects[0], level.map, rlutil::KEY_DOWN);
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
					if (kbhit())
					{
						i = rlutil::getkey();
						if (i == rlutil::KEY_LEFT)
						{
							rlutil::msleep(75);
							movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
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
			//not jumped
			else
			{
				movePlayer(level.objects[0], level.map, i);
				for (Object* x : level.objects)
				{
					if (x->getMoveType() == 1)
						continue;
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
					if (kbhit())
					{
						i = rlutil::getkey();
						if (i == rlutil::KEY_LEFT)
						{
							rlutil::msleep(75);
							movePlayer(level.objects[0], level.map, rlutil::KEY_LEFT);
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

void Run::runLevel_1(Level_1 level)
{
}



