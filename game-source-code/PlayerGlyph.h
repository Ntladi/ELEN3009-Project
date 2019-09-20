#ifndef PLAYERGLYPH_H_
#define PLAYERGLYPH_H_
#include "IEntity.h"
#include "Constants.h"
#include <tuple>
using two_floats = std::tuple<float, float>;

class PlayerGlyph : public IEntity
{
public:
	PlayerGlyph(Orientation orientation = Orientation::FACE_UP);
	void setPosition(const two_floats & position);

private:
	virtual two_floats initializePosition() override;

};

#endif
