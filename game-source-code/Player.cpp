#include <Player.h>

Player::Player(Orientation orientation)
{
	four_floats params =
	{ Constants::PLAYER_X_LENGTH, Constants::PLAYER_Y_LENGTH,
			Constants::PLAYER_HIT_POINTS, Constants::PLAYER_WORTH };

	parameters_ = Parameters
	{ ObjectType::PLAYER, orientation, params };

	position_ = Position
	{ initializePosition() };

	movement_ = Movement
	{ MoveDirection::NONE, Constants::PLAYER_MAXIMUM_MOVEMENT_STEP };

	hitbox_ = HitBox
	{ getPosition(), getSize() };
}

void Player::setMoveDirection(const MoveDirection &direction)
{
	movement_.setMoveDirection(direction);
}

vec_of_bullets Player::getShotsFired()
{
	return bullet_factory_.getShotsFired();
}

void Player::setPosition(const two_floats &position)
{
	position_.setXPosition(std::get<0>(position));
	position_.setYPosition(std::get<1>(position));
	updateHitBox();
}

void Player::move()
{
	if ((movement_.isMovingLeft() || movement_.isMovingRight())
			&& isWithinScreenBounds())
		movePlayerHorizontally();
	if ((movement_.isMovingUp() || movement_.isMovingDown())
			&& isAtNotAtEndOfScreen())
		movePlayerVertically();

	updateHitBox();
	movement_.setMoveDirection(MoveDirection::NONE);
}

void Player::shoot()
{
	bullet_factory_.shoot(parameters_.getOrientation(), getPosition());
}

bool Player::isWithinScreenBounds()
{
	updateHitBox();
	if (movement_.isMovingLeft())
	{
		auto left_x = std::get<0>(hitbox_.getTopLeft());
		left_x -= movement_.getMovementStep();

		if (left_x >= 0)
			return true;
	}

	else if (movement_.isMovingRight())
	{
		auto right_x = std::get<0>(hitbox_.getTopRight());
		right_x += movement_.getMovementStep();

		if (right_x <= std::get<0>(parameters_.getScreenSize()))
			return true;
	}
	return false;
}

bool Player::isAtNotAtEndOfScreen()
{
	if ((position_.getYPosition() - movement_.getMovementStep()
			< (Constants::PLAYER_Y_LENGTH * 1.5)) && movement_.isMovingUp())
		return false;
	if ((position_.getYPosition() + movement_.getMovementStep()
			> (Constants::SCREEN_Y_LENGTH - Constants::PLAYER_Y_LENGTH / 2))
			&& movement_.isMovingDown())
		return false;
	changeOrientation();
	return true;
}

bool Player::isNotMovingVertucally()
{
	if ((position_.getYPosition() < (Constants::PLAYER_Y_LENGTH * 1.5 + 5)))
		return true;
	if ((position_.getYPosition()
			> (Constants::SCREEN_Y_LENGTH - Constants::PLAYER_Y_LENGTH / 2 - 5)))
		return true;
	return false;
}

void Player::movePlayerHorizontally()
{
	auto player_x_position = position_.getXPosition();
	if (movement_.isMovingLeft())
		player_x_position -= movement_.getMovementStep();
	else if (movement_.isMovingRight())
		player_x_position += movement_.getMovementStep();

	position_.setXPosition(player_x_position);
}

void Player::changeOrientation()
{
	if (position_.getYPosition()
			> Constants::SCREEN_Y_LENGTH - Constants::PLAYER_Y_LENGTH / 2 - 5)
		parameters_.setOrientation(Orientation::FACE_UP);
	else if (position_.getYPosition() < Constants::PLAYER_Y_LENGTH * 1.5 + 5)
		parameters_.setOrientation(Orientation::FACE_DOWN);
}

void Player::movePlayerVertically()
{
	auto player_y_position = position_.getYPosition();
	if (movement_.isMovingUp())
		player_y_position -= movement_.getMovementStep();
	else if (movement_.isMovingDown())
		player_y_position += movement_.getMovementStep();

	position_.setYPosition(player_y_position);
}

two_floats Player::initializePosition()
{
	auto x_position = Constants::PLAYER_INITAL_X_POSITION;
	auto y_position = 0.0f;

	if (parameters_.isFacingUp())
		y_position = Constants::SCREEN_Y_LENGTH
				- Constants::PLAYER_Y_LENGTH / 2;
	else if (parameters_.isFacingDown())
		y_position = Constants::PLAYER_Y_LENGTH * 1.5;

	return
	{	x_position,y_position};
}
