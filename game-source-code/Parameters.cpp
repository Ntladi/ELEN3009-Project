#include <Parameters.h>

Parameters::Parameters(ObjectType object, Orientation orientation,
		MoveDirection moveDirection)
{
	this->object_ = object;
	this->orientation_ = orientation;
	this->move_direction_ = moveDirection;
	this->is_Alive_ = true;

	if (object == ObjectType::PLAYER)
	{
		this->x_length_ = Constants::PLAYER_X_LENGTH;
		this->y_length_ = Constants::PLAYER_Y_LENGTH;
		this->movement_step_ = Constants::PLAYER_MAXIMUM_MOVEMENT_STEP;
		this->x_position_ = Constants::PLAYER_INITAL_X_POSITION;
		if (orientation == Orientation::FACE_UP)
			this->y_position_ = Constants::SCREEN_Y_LENGTH
					- Constants::PLAYER_Y_LENGTH / 2;
		else if (orientation == Orientation::FACE_DOWN)
			this->y_position_ = Constants::PLAYER_Y_LENGTH / 2;
	}

	if (object == ObjectType::PLAYER_BULLET || object == ObjectType::ALIEN_BULLET)
	{
		this->x_length_ = Constants::PLAYER_BULLET_X_LENGTH;
		this->y_length_ = Constants::PLAYER_BULLET_Y_LENGTH;
		this->movement_step_ = Constants::PLAYER_BULLET_MAXIMUM_MOVEMENT_STEP;
		this->x_position_ = 0;
		if (orientation == Orientation::FACE_UP)
			this->y_position_ = -(Constants::PLAYER_BULLET_Y_LENGTH / 2) - Constants::PLAYER_BULLET_Y_LENGTH;
		else if (orientation == Orientation::FACE_DOWN)
			this->y_length_ = (Constants::PLAYER_BULLET_Y_LENGTH / 2) + Constants::PLAYER_BULLET_Y_LENGTH;
	}

	if (object == ObjectType::ALIEN)
	{
		this->x_length_ = Constants::ALIEN_X_LENGTH;
		this->y_length_ = Constants::ALIEN_Y_LENGTH;
		this->movement_step_ = Constants::ALIEN_MAXIMUM_MOVEMENT_STEP;
		this->x_position_ = Constants::ALIEN_INITAL_X_POSITION;

		if (orientation == Orientation::FACE_UP)
			this->y_position_ = Constants::SCREEN_Y_LENGTH / 2
					- Constants::ALIEN_Y_LENGTH / 2 - 5;
		else if (orientation == Orientation::FACE_DOWN)
			this->y_position_ = Constants::SCREEN_Y_LENGTH / 2
					+ Constants::ALIEN_Y_LENGTH / 2 + 5;
	}

}

const float Parameters::getXLength() const
{
	return x_length_;
}

const float Parameters::getYHeight() const
{
	return y_length_;
}

const float Parameters::getScreenXLength() const
{
	return Constants::SCREEN_X_LENGTH;
}

const float Parameters::getScreenYHeight() const
{
	return Constants::SCREEN_Y_LENGTH;
}

const float Parameters::getMovementStep() const
{
	return movement_step_;
}

float Parameters::getXposition() const
{
	return x_position_;
}

float Parameters::getYposition() const
{
	return y_position_;
}

ObjectType Parameters::getObjectType() const
{
	return object_;
}
Orientation Parameters::getOrientation() const
{
	return orientation_;
}

MoveDirection Parameters::getMoveDirection() const
{
	return move_direction_;
}

bool Parameters::getStatus() const
{
	return is_Alive_;
}
void Parameters::setXPosition(const float &x)
{
	x_position_ = x;
}

void Parameters::setYPosition(const float &y)
{
	y_position_ = y;
}

void Parameters::setOrientation(const Orientation &orientation)
{
	orientation_ = orientation;
}

void Parameters::setMoveDirection(const MoveDirection &move_direction)
{
	move_direction_ = move_direction;
}

void Parameters::setStatus(const bool &status)
{
	is_Alive_ = status;
}
