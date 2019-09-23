#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_
#include "Player.h"
#include "Armada.h"
#include "LifeFactory.h"
#include "PlayerObjectHandler.h"
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include "ScreenStates.h"
using vec_of_moving_objects = std::vector<std::shared_ptr<IMovingEntity>>;
using vec_of_static_objects = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;
using map_of_two_floats = std::map<ObjectType,two_floats>;

class ObjectFactory
{
public:
	ObjectFactory();
	void getSizes(map_of_two_floats& sizes);
	void getMovingObjects(vec_of_moving_objects& objects);
	void getStaticObjects(vec_of_static_objects& objects);
	void getPlayers(vec_of_moving_objects & objects);
	void getAliens(vec_of_moving_objects & objects);
	void getPlayerBullets(vec_of_moving_objects & objects);
	void getAlienBullets(vec_of_moving_objects & objects);
	void changePlayerDirections(std::vector<bool> &inputs);
	void checkPlayer();
	bool gameOverStatus() const;
	bool gameWonStatus() const;
	void startPowerClock();

private:
	std::shared_ptr<Player> up_player_;
	std::shared_ptr<Player> down_player_;
	std::shared_ptr<Armada> up_armada_;
	std::shared_ptr<Armada> down_armada_;
	std::shared_ptr<LifeFactory> up_lives_;
	std::shared_ptr<LifeFactory> down_lives_;
	PlayerObjectHandler player_input_handler_;
	void initializeObjects();
	void getGlyphs(vec_of_static_objects& objects);

};

#endif
