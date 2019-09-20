#include <AlienFactory.h>


void AlienFactory::initializeArmada(aliens_2d & armada,Orientation orientation)
{
	Alien alien(orientation);
	size_ = alien.getSize();
	armada.resize(Constants::MAX_ARMADA_COLS);

	std::for_each(begin(armada), end(armada), [&](auto &i)
	{	i.resize(Constants::MAX_ARMADA_ROWS);});

	position_ = Position{ alien.getPosition()};
	generateRows(orientation,armada);
}

unsigned int AlienFactory::getCounter() const
{
	return counter_;
}

void AlienFactory::incrementCounter()
{
	counter_++;
}

void AlienFactory::setCounter(unsigned int i)
{
	counter_ = i;
}

void AlienFactory::generateRows(Orientation & orientation,aliens_2d & armada)
{
	auto x_position = std::get<0>(size_);

	for (auto i = 0u; i < Constants::MAX_ARMADA_COLS; i++)
	{
		generateColumn(x_position, i, orientation,armada);

		x_position += std::get<0>(size_) + Constants::SPACE_BETWEEN_ARMADA_COLS;
	}
}

void AlienFactory::generateColumn(const double &x_position,
		const unsigned int &index, Orientation & orientation,aliens_2d & armada)
{
	auto y_position = position_.getYPosition();

	for (auto j = 0u; j < Constants::MAX_ARMADA_ROWS; j++)
	{
		auto new_alien = std::make_shared<Alien>(orientation);
		two_floats new_position = {x_position,y_position};
		new_alien->setPosition(new_position);
		armada.at(index).at(j) = new_alien;

		if (orientation == Orientation::FACE_DOWN)
			y_position += std::get<1>(size_)
					+ Constants::SPACE_BETWEEN_ARMADA_ROWS;
		else if (orientation == Orientation::FACE_UP)
			y_position -= std::get<1>(size_)
					+ Constants::SPACE_BETWEEN_ARMADA_ROWS;

		counter_++;
	}

}
