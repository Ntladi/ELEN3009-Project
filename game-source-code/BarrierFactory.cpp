#include <BarrierFactory.h>

BarrierFactory::BarrierFactory(Orientation orientation)
{
	generateBarriers(orientation);
}

vec_of_barriers BarrierFactory::getBarriers()
{
	removeWaste();
	return barriers_;
}

void BarrierFactory::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(barriers_.begin(),
			barriers_.end(), lambda);

	barriers_.erase(remove_idiom, barriers_.end());

}

void BarrierFactory::generateBarriers(Orientation orientation)
{
	auto temp_barrier = Barrier{orientation};
	auto[x_position, y_position] = temp_barrier.getPosition();

	for(auto i=0; i<Constants::MAX_BARRIERS; i++)
	{
		auto position = two_floats{x_position, y_position};

		generateRows(orientation,position,temp_barrier.getSize());

		x_position += Constants::BARRIER_OFFSET;
	}

}

void BarrierFactory::generateRows(Orientation orientation, two_floats position, two_floats size)
{
	auto y_size = std::get<1>(size);
	auto [x_position, y_position] = position;

	for(auto i=0u; i<Constants::MAX_BARRIER_ROWS; i++)
	{
		x_position = std::get<0>(position);
		auto new_position = two_floats{x_position, y_position};
		generateColumns(orientation,new_position,size);
		if(orientation == Orientation::FACE_UP)
			y_position -= y_size;
		else if (orientation == Orientation::FACE_DOWN)
			y_position += y_size;
	}
}

void BarrierFactory::generateColumns(Orientation orientation, two_floats position, two_floats size)
{
	auto x_size = std::get<0>(size);
	auto [x_position, y_position] = position;

	for(auto j=0u; j<Constants::MAX_BARRIER_COLS; j++)
	{
		auto new_barrier = std::make_shared<Barrier>(orientation);
		auto position = two_floats{x_position, y_position};
		new_barrier->setPosition(position);
		barriers_.push_back(new_barrier);

		x_position += x_size;
	}
}
