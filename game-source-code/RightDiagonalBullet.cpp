#include <RightDiagonalBullet.h>

RightDiagonalBullet::RightDiagonalBullet(two_floats position, Orientation orientation)
{
	four_floats params =
	{ Constants::BULLET_X_LENGTH, Constants::BULLET_Y_LENGTH,
			Constants::BULLET_HIT_POINTS, Constants::BULLET_WORTH };

	setup(params,ObjectType::PLAYER_BULLET,orientation,position);
}

void RightDiagonalBullet::moveBullet()
{
	Bullet::moveBullet();
	auto x_position = position_.getXPosition();
	x_position += movement_.getMovementStep()/2;
	position_.setXPosition(x_position);
}
