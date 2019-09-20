#ifndef LIFEFACTORY_H_
#define LIFEFACTORY_H_
#include "PlayerGlyph.h"
#include <vector>
#include <memory>
using glyph_ptr = std::shared_ptr<PlayerGlyph>;
using vec_of_glyph_ptrs = std::vector<std::shared_ptr<PlayerGlyph>>;

class LifeFactory
{
public:
	LifeFactory(Orientation orientation = Orientation::FACE_UP, const int &lives = 0);
	vec_of_glyph_ptrs getGlyphs() const;
	void manageLives(const int& i);
private:
	Orientation orientation_;
	vec_of_glyph_ptrs glyphs_;
	float lives_;
	void generateGlyphs();
	void generateUpGlyphs();
	void generateDownGlyphs();
};

#endif
