#ifndef BULLET_H_
#define BULLET_H_
#include "Orientation.h"
#include "ObjectType.h"
#include "MoveDirection.h"
#include "HitBox.h"
#include "Parameters.h"
#include "IMovingEntity.h"
using two_floats = std::tuple<float, float>;
using four_floats = std::tuple<float,float,float, float>;

class Bullet : public IMovingEntity
{
public:
	Bullet(two_floats position = {0,0}, ObjectType bullet_type = ObjectType::PLAYER_BULLET, Orientation orientation = Orientation::FACE_UP);
	void move() override;
	bool isOnScreen();

private:
	void moveBullet();


};

#endif
