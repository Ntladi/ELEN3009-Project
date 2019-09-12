#include <Bullet.h>
#include <iostream>

Bullet::Bullet(two_floats position, ObjectType bullet_type, Orientation orientation)
{
	if (orientation == Orientation::FACE_UP)
		parameters_ = Parameters
			{ bullet_type, orientation, MoveDirection::UP };

	else if (orientation == Orientation::FACE_DOWN)
		parameters_ = Parameters
			{ bullet_type, orientation, MoveDirection::DOWN };

	auto[x_position, y_position] = position;
	parameters_.setXPosition(x_position);
	parameters_.setYPosition(y_position);
	hitbox_ = HitBox
	{ getPosition(), getSize() };

}

Bullet::~Bullet()
{
	//std::cout << "Bullet is destroyed" << std::endl;
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
	if (parameters_.getMoveDirection() == MoveDirection::DOWN)
	{
		auto y_top_left = std::get<1>(hitbox_.getTopLeft());

		if (y_top_left <= parameters_.getScreenYHeight())
			return true;
	}
	else if (parameters_.getMoveDirection() == MoveDirection::UP)
	{
		auto y_bottom_right = std::get<1>(hitbox_.getBottomLeft());

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
	auto bullet_y_position = parameters_.getYposition();

	if (parameters_.getMoveDirection() == MoveDirection::UP)
	{
		bullet_y_position -= parameters_.getMovementStep();
		parameters_.setYPosition(bullet_y_position);
	}
	else if (parameters_.getMoveDirection() == MoveDirection::DOWN)
	{
		bullet_y_position += parameters_.getMovementStep();
		parameters_.setYPosition(bullet_y_position);

	}
}
