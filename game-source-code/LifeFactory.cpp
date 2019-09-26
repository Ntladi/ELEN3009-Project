#include <LifeFactory.h>

LifeFactory::LifeFactory(Orientation orientation,const int & lives)
{
	lives_ = lives;
	orientation_ = orientation;
		generateGlyphs();
}

void LifeFactory::manageLives(const int& i)
{
	if(i!=lives_)
	{
		lives_ = i;
		glyphs_.clear();
		generateGlyphs();
	}
}

vec_of_glyph_ptrs LifeFactory::getGlyphs() const
{
	return glyphs_;
}

void LifeFactory::generateGlyphs()
{
	auto temp_glyph = PlayerLife{orientation_};
	auto x_position = std::get<0>(temp_glyph.getPosition());
	auto y_position = std::get<1>(temp_glyph.getPosition());

	for(auto i=0u; i< lives_; i++)
	{
		auto new_life = std::make_shared<PlayerLife>(orientation_);
		two_floats position = {x_position,y_position};
		new_life->setPosition(position);
		glyphs_.push_back(new_life);

		if(orientation_ == Orientation::FACE_UP)
			x_position += std::get<0>(temp_glyph.getSize()) + Constants::PLAYER_GLYPH_OFFSET;
		else if(orientation_ == Orientation::FACE_DOWN)
			x_position -= std::get<0>(temp_glyph.getSize()) + Constants::PLAYER_GLYPH_OFFSET;
	}
}
