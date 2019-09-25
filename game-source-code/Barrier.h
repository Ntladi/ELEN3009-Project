#ifndef BARRIER_H_
#define BARRIER_H_
#include "IEntity.h"

class Barrier : public IEntity
{
public:
	Barrier(Orientation orientation = Orientation::FACE_UP);
	void setPosition(const two_floats & position);
private:
	virtual two_floats initializePosition() override;
};

#endif
