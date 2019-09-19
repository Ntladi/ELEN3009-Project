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
	LifeFactory(Orientation orientation,const float &lives);
	vec_of_glyph_ptrs getGlyphs();
private:
	vec_of_glyph_ptrs glyphs_;
	float lives_;
	void generateUpGlyphs();
	void generateDownGlyphs();
};

#endif
