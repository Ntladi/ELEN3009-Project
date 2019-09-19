#include <Parameters.h>

Parameters::Parameters(ObjectType object, Orientation orientation)
{
	this->object_ = object;
	this->orientation_ = orientation;
	this->is_Alive_ = true;

	if (object == ObjectType::PLAYER)
		initializePlayer();

	if (object == ObjectType::PLAYER_BULLET || object == ObjectType::ALIEN_BULLET)
		initializeBullet();

	if (object == ObjectType::ALIEN)
		initializeAlien();

}

two_floats Parameters::getSize() const
{
	return {x_length_,y_length_};
}

two_floats Parameters::getScreenSize() const
{
	return {Constants::SCREEN_X_LENGTH,Constants::SCREEN_Y_LENGTH};
}

const float Parameters::getMovementStep() const
{
	return movement_step_;
}

ObjectType Parameters::getObjectType() const
{
	return object_;
}
Orientation Parameters::getOrientation() const
{
	return orientation_;
}

bool Parameters::getStatus() const
{
	return is_Alive_;
}

void Parameters::setOrientation(const Orientation &orientation)
{
	orientation_ = orientation;
}

void Parameters::setStatus(const bool &status)
{
	is_Alive_ = status;
}

bool Parameters::isFacingDown()
{
	return orientation_ == Orientation::FACE_DOWN;
}

bool Parameters::isFacingUp()
{
	return orientation_ == Orientation::FACE_UP;
}

void Parameters::initializePlayer()
{
	x_length_ = Constants::PLAYER_X_LENGTH;
	y_length_ = Constants::PLAYER_Y_LENGTH;
	movement_step_ = Constants::PLAYER_MAXIMUM_MOVEMENT_STEP;
}

void Parameters::initializeBullet()
{
	x_length_ = Constants::PLAYER_BULLET_X_LENGTH;
	y_length_ = Constants::PLAYER_BULLET_Y_LENGTH;
	movement_step_ = Constants::PLAYER_BULLET_MAXIMUM_MOVEMENT_STEP;
}

void Parameters::initializeAlien()
{
	x_length_ = Constants::ALIEN_X_LENGTH;
	y_length_ = Constants::ALIEN_Y_LENGTH;
	movement_step_ = Constants::ALIEN_MAXIMUM_MOVEMENT_STEP;

}
