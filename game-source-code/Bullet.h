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
	Bullet(two_floats position = {0,0}, ObjectType bullet_type = ObjectType::NONE, Orientation orientation = Orientation::FACE_UP);
	void move() override;
protected:
	virtual void moveBullet();
	void setup(four_floats params, ObjectType bullet_type,Orientation orientation, two_floats position);
	two_floats initializePosition() override;
};

#endif
