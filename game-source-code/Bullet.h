#ifndef BULLET_H_
#define BULLET_H_
#include "Orientation.h"
#include "ObjectType.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
#include "IMovingEntity.h"
using two_floats = std::tuple<float, float>;

class Bullet : public IMovingEntity
{
public:
	Bullet(two_floats position, ObjectType bullet_type, Orientation orientation);
	void move() override;
	bool isOnScreen();

private:
	void moveBullet();
};

#endif
