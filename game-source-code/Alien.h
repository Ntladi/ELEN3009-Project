#ifndef ALIEN_H_
#define ALIEN_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "IEntity.h"
#include "IMovingEntity.h"
#include "Bullet.h"
#include <tuple>
using two_floats = std::tuple<float, float>;

class Alien : public IMovingEntity
{
public:
	Alien(Orientation orientation);
	void setMoveDirection(const MoveDirection &direction);
	void setPosition(const two_floats & position);
	void moveAlienVertically();
	bool isAtEdgeOfScreen();
	bool isAtEndOfScreen();
	void move() override;
	Bullet shoot();

private:
	void moveAlienHorizontally();
	void incrementAlienPosition();
};

#endif
