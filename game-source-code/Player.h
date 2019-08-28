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
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class Player
{
public:
	Player(Orientation orientation);
	Orientation getOrientation() const;
	two_floats getPosition() const;
	two_floats getSize() const;
	MoveDirection getMoveDirection() const;
	HitBox getHitBox() const;
	Parameters getParameters() const;
	vec_of_bullets getShotsFired() const;
	void setMoveDirection(const MoveDirection &direction);
	void move();
	void shoot();

private:
	Parameters parameters_;
	HitBox player_hitbox_;
	void incrementPlayerPosition();
	bool isWithinScreenBounds();
	void movePlayerHorizontally();
	void updateHitBox();
};

#endif
