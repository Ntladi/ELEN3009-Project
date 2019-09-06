#include <Armada.h>
#include <iostream>

Armada::Armada(Orientation orientation)
{
	parameters_ = ArmadaParameters
	{ orientation };

	armada_.resize(parameters_.getMaxCols());

	std::for_each(begin(armada_), end(armada_), [&](vec_of_aliens &i)
	{	i.resize(parameters_.getMaxRows());});

	generateRows();

}

vec_of_aliens Armada::getArmada()
{

	removeWaste();
	generateBullets();
	checkEdges();
	return aliens1D();
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
	for (auto &i : aliens1D())
		if (i->isAtEndOfScreen())
			return true;

	return false;
}

void Armada::generateBullets()
{
	if (std::fmod(parameters_.getElapsedTime(),
			parameters_.getSecondsBetweenShots()) >= 0
			&& std::fmod(parameters_.getElapsedTime(),
					parameters_.getSecondsBetweenShots()) <= 0.001
			&& parameters_.getCounter() > 0)
	{
		std::vector<unsigned int> endOfCols;

		std::for_each(begin(armada_), end(armada_), [&](auto i)
		{	endOfCols.push_back(i.size()-1);});

		auto shot_col = rand() % armada_.size();

		if (armada_.at(shot_col).size() > 0)
		{
			auto shot_row = endOfCols.at(shot_col);

			auto newBullet = std::make_shared<Bullet>(
					armada_.at(shot_col).at(shot_row)->shoot());
			bullets_.push_back(newBullet);
		}

	}
}

void Armada::generateRows()
{
	auto x_position = std::get<0>(parameters_.getAlienSize());

	for (auto i = 0u; i < parameters_.getMaxCols(); i++)
	{
		generateColumn(x_position, i);

		x_position += std::get<0>(parameters_.getAlienSize())
				+ parameters_.getSpaceBetweenCols();
	}
}

void Armada::generateColumn(const double &x_position, const unsigned int &index)
{

	auto y_position = std::get<1>(parameters_.getAlienPosition());

	for (auto j = 0u; j < parameters_.getMaxRows(); j++)
	{
		auto newAlien = std::make_shared<Alien>(parameters_.getOrientation());
		newAlien->setPosition(
		{ x_position, y_position });
		armada_.at(index).at(j) = newAlien;

		if (parameters_.getOrientation() == Orientation::FACE_DOWN)
			y_position += std::get<1>(parameters_.getAlienSize())
					+ parameters_.getSpaceBetweenRows();
		else if (parameters_.getOrientation() == Orientation::FACE_UP)
			y_position -= std::get<1>(parameters_.getAlienSize())
					+ parameters_.getSpaceBetweenRows();

		parameters_.incrementCounter();
	}
}

void Armada::removeWaste()
{

	parameters_.setCounter(0);
	for (auto &i : armada_)
	{
		removeForEach(i);
		std::for_each(begin(i), end(i), [&](auto &j)
		{	parameters_.incrementCounter();});
	}

}

void Armada::checkEdges()
{
	if (parameters_.getCounter() > 0)
		if (aliens1D().at(0)->isAtEdgeOfScreen()
				|| aliens1D().at(parameters_.getCounterMinus())->isAtEdgeOfScreen())
		{
			moveAllVertically();
			parameters_.changeDirection();
		}

}

void Armada::moveAllVertically()
{
	std::for_each(begin(armada_), end(armada_), [](auto &i)
	{	for(auto &j:i)
		j->moveAlienVertically();});
}

vec_of_aliens Armada::aliens1D()
{
	vec_of_aliens aliens;

	std::for_each(begin(armada_), end(armada_), [&](auto &i)
	{	for(auto &j:i)
		aliens.push_back(j);});

	return aliens;
}

void Armada::removeForEach(vec_of_aliens &aliens)
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(begin(aliens), end(aliens), lambda);
	aliens.erase(remove_idiom, end(aliens));

}
