#include <PlayerGlyph.h>

PlayerGlyph::PlayerGlyph(Orientation orientation)
{
	four_floats params =
	{ Constants::GLYPH_X_LENGTH, Constants::GLYPH_Y_LENGTH,
			Constants::GLYPH_HIT_POINTS, 0 };

	parameters_ = Parameters
	{ ObjectType::PLAYER_GLYPH, orientation, params };

	position_ = Position
	{ initializePosition() };

	hitbox_ = HitBox
	{ getSize(), getPosition() };

}

void PlayerGlyph::setPosition(const two_floats & position)
{
	auto [x_position,y_position] = position;
	position_.setXPosition(x_position);
	position_.setYPosition(y_position);
}

two_floats PlayerGlyph::initializePosition()
{
	auto x_position = 0;
	auto y_position = Constants::GLYPH_Y_LENGTH / 2 + 5;

	if (parameters_.isFacingUp())
		x_position = Constants::GLYPH_X_LENGTH / 2 + 5;
	else if(parameters_.isFacingDown())
		x_position = std::get<0>(parameters_.getScreenSize()) - (Constants::GLYPH_X_LENGTH / 2) - 5;

	return
	{	x_position, y_position};
}
