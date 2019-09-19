#include <PlayerGlyph.h>

PlayerGlyph::PlayerGlyph(Orientation orientation)
{
	four_floats params =
	{ Constants::GLYPH_X_LENGTH, Constants::GLYPH_Y_LENGTH,
			Constants::GLYPH_HIT_POINTS, 0 };

	parameters_ = Parameters
	{ ObjectType::PLAYER_GLYPH, orientation, params };

	hitbox_ = HitBox{getSize(), getPosition()};

}
