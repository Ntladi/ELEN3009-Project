#include <PlayerGlyph.h>

PlayerGlyph::PlayerGlyph(Orientation orientation)
{
	four_floats params =
	{ Constants::GLYPH_X_LENGTH, Constants::GLYPH_Y_LENGTH,
			Constants::GLYPH_HIT_POINTS, 0 };

	parameters_ = Parameters
	{ ObjectType::PLAYER_GLYPH, orientation, params };

	position_ = Position{initializePosition()};

	hitbox_ = HitBox{getSize(), getPosition()};

}

two_floats PlayerGlyph::initializePosition()
{
	auto x_position = Constants::GLYPH_X_LENGTH/2 + 5;
	auto y_position = Constants::GLYPH_Y_LENGTH/2 + 5;
	return {x_position, y_position};
}
