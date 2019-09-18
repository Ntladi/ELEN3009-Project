#ifndef OBJECTFACTORY_H_
#define OBJECTFACTORY_H_
#include "Player.h"
#include "Armada.h"
#include <vector>
using vec_of_objects = std::vector<std::shared_ptr<IEntity>>;
using two_floats = std::tuple<float,float>;

class ObjectFactory
{
public:
	ObjectFactory();
	void getObjects(vec_of_objects& objects);
	void getPlayers(vec_of_objects & objects);
	void getAliens(vec_of_objects & objects);
	void getPlayerBullets(vec_of_objects & objects);
	void getAlienBullets(vec_of_objects & objects);
	void changePlayerDirections(std::vector<bool> &inputs);
	bool gameOverStatus() const;
	bool gameWonStatus() const;

private:
	std::shared_ptr<Player> upPlayer_;
	std::shared_ptr<Player> downPlayer_;
	std::shared_ptr<Armada> upArmada_;
	std::shared_ptr<Armada> downArmada_;
	void loadSizes();
	void loadPositions();
	void populateObjects(vec_of_objects & upObjects,vec_of_objects & downObjects, vec_of_objects & targetObjects);
	void initializeObjects();

};

#endif
