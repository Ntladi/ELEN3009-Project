#include <Armada.h>
#include <iostream>

Armada::Armada(Orientation orientation)
{
	aliens_ = vec_of_aliens
	{ };
	bullets_ = vec_of_bullets{};
	parameters_ = ArmadaParameters{orientation};
	generateRows();

}

vec_of_aliens Armada::getArmada()
{

	if( std::fmod(parameters_.getElapsedTime(),1.5) == 0)
	{
		auto newBullet = std::make_shared<Bullet>(aliens_.at(parameters_.getCounterMinus())->shoot());
		bullets_.push_back(newBullet);

	}

	removeWaste();
	checkEdges();
	return aliens_;
}

vec_of_bullets Armada::getOnslaught()
{
	return bullets_;
}
two_floats Armada::getAlienSize() const
{
	return parameters_.getAlienSize();
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
	auto x_position = std::get<0>(parameters_.getAlienSize());

	for (auto i = 0u; i < parameters_.getMaxCols(); i++)
	{
		generateColumn(x_position);

		x_position += std::get<0>(parameters_.getAlienSize()) + parameters_.getSpaceBetweenCols();
	}
}

void Armada::generateColumn(const double &x_position)
{

	auto y_position = std::get<1>(parameters_.getAlienPosition());

	for (auto i = 0u; i < parameters_.getMaxRows(); i++)
	{
		auto newAlien = std::make_shared<Alien>(parameters_.getOrientation());
		newAlien->setPosition({x_position, y_position});
		aliens_.push_back(newAlien);

		if (parameters_.getOrientation() == Orientation::FACE_DOWN)
			y_position += std::get<1>(parameters_.getAlienSize()) + parameters_.getSpaceBetweenRows();
		else if (parameters_.getOrientation() == Orientation::FACE_UP)
			y_position -= std::get<1>(parameters_.getAlienSize()) + parameters_.getSpaceBetweenRows();

		parameters_.incrementCounter();
	}
}

void Armada::removeWaste()
{
	auto lambda = [](std::shared_ptr<Alien> i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(aliens_.begin(), aliens_.end(), lambda);

	aliens_.erase(remove_idiom, aliens_.end());
	parameters_.setCounter(aliens_.size());
}

void Armada::checkEdges()
{
	if(aliens_.size() > 0)
		if (aliens_.at(0)->isAtEdgeOfScreen() || aliens_.at(parameters_.getCounterMinus())->isAtEdgeOfScreen())
			moveAllVertically();

}

void Armada::moveAllVertically()
{
	for (auto &i:aliens_)
		i->moveAlienVertically();
}
