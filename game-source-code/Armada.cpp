#include <Armada.h>
#include <iostream>

Armada::Armada(Orientation orientation)
{
	alien_factory_.initializeArmada(armada_,orientation);
}

vec_of_aliens Armada::getArmada()
{
	removeWaste();
	checkEdges();
	return aliens1D();
}

vec_of_bullets Armada::getOnslaught()
{
	bullet_factory_.generateBullets(armada_, aliens1D().size());
	return bullet_factory_.getOnslaught();
}


bool Armada::isGameOver()
{
	for (auto &i : aliens1D())
		if (i->isAtEndOfScreen())
			return true;

	return false;
}

void Armada::removeWaste()
{

	alien_factory_.setCounter(0);
	for (auto &i : armada_)
	{
		removeForEach(i);
		std::for_each(begin(i), end(i), [&](auto &j)
		{	alien_factory_.incrementCounter();});
	}

}

void Armada::checkEdges()
{
	if (alien_factory_.getCounter() > 0)
		if (aliens1D().at(0)->isAtEdgeOfScreen()
				|| aliens1D().at(alien_factory_.getCounter()-1)->isAtEdgeOfScreen())
		{
			moveAllVertically();
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

bool Armada::isArmadaEmpty()
{
	return aliens1D().size() == 0;
}
