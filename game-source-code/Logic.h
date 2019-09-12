#ifndef LOGIC_H_
#define LOGIC_H_
#include "Presentation.h"
#include "CollisionHandler.h"
#include "Player.h"
#include "Armada.h"
#include "IEntity.h"
#include <tuple>
#include <memory>
#include <vector>
using vec_of_objects = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;


class Logic {
public:
	Logic();
	void run();
	void reset();
	void loadInitialSizes();
	void loadInitialPositions();

private:
	std::shared_ptr<Player> upPlayer_;
	std::shared_ptr<Player> downPlayer_;
	std::shared_ptr<Armada> upArmada_;
	std::shared_ptr<Armada> downArmada_;
	Presentation presentation_;
	CollisionHandler collision_handler_;
	void process(std::vector<bool> & inputs);
	void changePlayerDirections(std::vector<bool> & inputs);
	void loadSizes();
	void loadPositions();
	void initializeObjects();
	void moveObject(std::shared_ptr<IEntity> &object);
	void moveAllObjects();
	void checkColisions();
	void getObjects(vec_of_objects& objects);
	void getPlayers(vec_of_objects & objects);
	void getAliens(vec_of_objects & objects);
	void getPlayerBullets(vec_of_objects & objects);
	void getAlienBullets(vec_of_objects & objects);
	void checkGameOver();
};

#endif
