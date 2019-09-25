#ifndef BARRIERFACTORY_H_
#define BARRIERFACTORY_H_
#include "Barrier.h"
#include <memory>
#include <vector>
#include <tuple>
#include <algorithm>
using vec_of_barriers = std::vector<std::shared_ptr<Barrier>>;
using two_floats = std::tuple<float, float>;

class BarrierFactory
{
public:
	BarrierFactory(Orientation orientation = Orientation::FACE_UP);
	vec_of_barriers getBarriers();
private:
	vec_of_barriers barriers_;
	void removeWaste();
	void generateBarriers(Orientation orientation);
	void generateRows(Orientation orientation, two_floats position, two_floats size);
	void generateColumns(Orientation orientation, two_floats position, two_floats size);
};

#endif
