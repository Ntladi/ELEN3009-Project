#ifndef ALIEN_H_
#define ALIEN_H_
#include "Orientation.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
#include "IEntity.h"
using two_floats = std::tuple<float, float>;

class Alien : public IEntity
{
public:
	Alien(Orientation orientation);
	void setMoveDirection(const MoveDirection &direction);
	void setPosition(const two_floats & position);
	void moveAlienVertically();
	bool isAtEdgeOfScreen();
	bool isAtEndOfScreen();
	void move() override;

private:
	void moveAlienHorizontally();
	void incrementAlienPosition();
	void updateHitBox();
};

#endif
