#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_
#include "Player.h"
#include "Armada.h"
#include "LifeFactory.h"
#include <vector>
using vec_of_moving_objects = std::vector<std::shared_ptr<IMovingEntity>>;
using vec_of_static_objects = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;

class ObjectFactory
{
public:
	ObjectFactory();
	void getMovingObjects(vec_of_moving_objects& objects);
	void getStaticObjects(vec_of_static_objects& objects);
	void getGlyphs(vec_of_static_objects& objects);
	void getPlayers(vec_of_moving_objects & objects);
	void getAliens(vec_of_moving_objects & objects);
	void getPlayerBullets(vec_of_moving_objects & objects);
	void getAlienBullets(vec_of_moving_objects & objects);
	void changePlayerDirections(std::vector<bool> &inputs);
	bool gameOverStatus() const;
	bool gameWonStatus() const;

private:
	std::shared_ptr<Player> upPlayer_;
	std::shared_ptr<Player> downPlayer_;
	std::shared_ptr<Armada> upArmada_;
	std::shared_ptr<Armada> downArmada_;
	std::shared_ptr<LifeFactory> upLives_;
	std::shared_ptr<LifeFactory> downLives_;
	void loadSizes();
	void loadPositions();
	void initializeObjects();

};

#endif
