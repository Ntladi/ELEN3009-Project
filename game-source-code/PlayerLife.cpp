#include <PlayerLife.h>

PlayerLife::PlayerLife(Orientation orientation)
{
	four_floats params =
	{ Constants::GLYPH_X_LENGTH, Constants::GLYPH_Y_LENGTH,
			Constants::GLYPH_HIT_POINTS, 0 };

	parameters_ = Parameters
	{ ObjectType::PLAYER_LIFE, orientation, params };

	position_ = Position
	{ initializePosition() };

	hitbox_ = HitBox
	{ getSize(), getPosition() };

}

two_floats PlayerLife::initializePosition()
{
	auto x_position = 0;
	auto y_position = Constants::GLYPH_Y_LENGTH / 2 + 5;

	if (parameters_.isFacingUp())
		x_position = Constants::GLYPH_X_LENGTH / 2 + 5;
	else if(parameters_.isFacingDown())
		x_position = Constants::SCREEN_X_LENGTH - (Constants::GLYPH_X_LENGTH / 2) - 5;

	return
	{	x_position, y_position};
}
