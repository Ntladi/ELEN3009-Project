#include <Armada.h>
#include <iostream>

Armada::Armada(Orientation orientation)
{
	this->aliens_ = vec_of_aliens
	{ };
	this->counter_ = 0;
	this->orientation_ = orientation;
	this->latestCol = std::vector<Alien>
	{ };
	generateRows();

}

vec_of_aliens Armada::getArmada()
{
	removeWaste();
	checkEdges();
	return aliens_;
}

two_floats Armada::getAlienSize() const
{
	auto parameters = Parameters
	{ ObjectType::ALIEN, orientation_ };

	return
	{	parameters.getXLength(), parameters.getYHeight()};
}
bool Armada::isGameOver()
{
	for(auto &i:aliens_)
		if(i->isAtEndOfScreen())
			return true;

	return false;
}
void Armada::generateRows()
{
	auto parameters = Parameters
	{ ObjectType::ALIEN, orientation_ };
	auto x_position = parameters.getXposition();
	auto x_length = parameters.getXLength();

	for (auto i = 0u; i < MAX_COLS_; i++)
	{
		generateColumn(x_position);

		x_position += x_length + SPACE_BETWEEN_COLS_;
	}
}

void Armada::generateColumn(const double &x_position)
{
	auto parameters = Parameters
	{ ObjectType::ALIEN, orientation_ };
	auto y_position = parameters.getYposition();
	auto y_height = parameters.getYHeight();

	for (auto i = 0u; i < MAX_ROWS_; i++)
	{
		auto newAlien = std::make_shared<Alien>(orientation_);
		newAlien->setYPosition(y_position);
		newAlien->setXPosition(x_position);
		aliens_.push_back(newAlien);
		if (orientation_ == Orientation::FACE_DOWN)
			y_position += y_height + SPACE_BETWEEN_ROWS_;
		else if (orientation_ == Orientation::FACE_UP)
			y_position -= y_height + SPACE_BETWEEN_ROWS_;
		counter_++;
	}
}

void Armada::removeWaste()
{
	auto lambda = [](std::shared_ptr<Alien> i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(aliens_.begin(), aliens_.end(), lambda);

	aliens_.erase(remove_idiom, aliens_.end());
}

void Armada::checkEdges()
{
		if (aliens_.at(0)->isAtEdgeOfScreen() || aliens_.at(counter_-1)->isAtEdgeOfScreen())
			moveAllVertically();

}

void Armada::moveAllVertically()
{
	for (auto i : aliens_)
		i->moveAlienVertically();
}
