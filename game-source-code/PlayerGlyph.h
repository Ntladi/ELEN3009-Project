#ifndef PLAYERGLYPH_H_
#define PLAYERGLYPH_H_
#include "IEntity.h"
#include "Constants.h"

class PlayerGlyph : public IEntity
{
public:
	PlayerGlyph(Orientation orientation = Orientation::FACE_UP);
};

#endif
