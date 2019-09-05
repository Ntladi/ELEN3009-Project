#include <Bullet.h>
#include <iostream>

Bullet::Bullet(two_floats position, Orientation orientation)
{
	if (orientation == Orientation::FACE_UP)
		parameters_ = Parameters
			{ ObjectType::PLAYER_BULLET, orientation, MoveDirection::UP };

	else if (orientation == Orientation::FACE_DOWN)
		parameters_ = Parameters
			{ ObjectType::PLAYER_BULLET, orientation, MoveDirection::DOWN };

	auto[x_position, y_position] = position;
	parameters_.setXPosition(x_position);
	parameters_.setYPosition(y_position);
	hitbox_ = HitBox
	{ getPosition(), getSize() };

}

Bullet::~Bullet()
{
	std::cout << "Bullet is destroyed" << std::endl;
}


void Bullet::move()
{
	if(isOnScreen())
		moveBullet();
	else
		killEntity();

	updateHitBox();
}


bool Bullet::isOnScreen()
{
	updateHitBox();
	auto bullet_movement_direction = parameters_.getMoveDirection();
	if (bullet_movement_direction == MoveDirection::DOWN)
	{
		auto top_left = hitbox_.getTopLeft();
		auto y_top_left = std::get<1>(top_left);

		if (y_top_left <= parameters_.getScreenYHeight())
			return true;
	}
	else if (bullet_movement_direction == MoveDirection::UP)
	{
		auto bottom_right = hitbox_.getBottomLeft();
		auto y_bottom_right = std::get<1>(bottom_right);

		if (y_bottom_right >= 0)
			return true;
	}

	return false;
}

void Bullet::updateHitBox()
{
	hitbox_.setNewPositions(getPosition(), getSize());
}

void Bullet::moveBullet()
{
	auto bullet_movement_direction = parameters_.getMoveDirection();
	auto bullet_y_position = parameters_.getYposition();

	if (bullet_movement_direction == MoveDirection::UP)
	{
		bullet_y_position -= parameters_.getMovementStep();
		parameters_.setYPosition(bullet_y_position);
	}
	else if (bullet_movement_direction == MoveDirection::DOWN)
	{
		bullet_y_position += parameters_.getMovementStep();
		parameters_.setYPosition(bullet_y_position);

	}
}
