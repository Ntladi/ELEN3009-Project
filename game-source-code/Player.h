#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <memory>
#include <algorithm>
#include <tuple>
#include "Orientation.h"
#include "MoveDirection.h"
#include "Parameters.h"
#include "HitBox.h"
#include "Bullet.h"
#include "IMovingEntity.h"
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class Player : public IMovingEntity
{
public:
	Player(Orientation orientation = Orientation::FACE_UP);
	vec_of_bullets getShotsFired();
	void setMoveDirection(const MoveDirection &direction);
	virtual void move() override;
	void shoot();

private:
	vec_of_bullets bulletsFired_;
	void incrementPlayerPosition();
	bool isWithinScreenBounds();
	void movePlayerHorizontally();
	void removeWaste();
	virtual two_floats initializePosition() override;
};

#endif
