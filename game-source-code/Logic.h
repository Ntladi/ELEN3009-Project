#ifndef LOGIC_H_
#define LOGIC_H_
#include "Presentation.h"
#include "CollisionHandler.h"
#include "ObjectFactory.h"
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

private:
	Presentation presentation_;
	CollisionHandler collision_handler_;
	ObjectFactory object_factory_;
	void reset();
	void process(std::vector<bool> & inputs);
	void loadSizes();
	void loadPositions();
	void moveObject(std::shared_ptr<IEntity> &object);
	void moveAllObjects();
	void checkColisions();
	void checkGameOver();
};

#endif
