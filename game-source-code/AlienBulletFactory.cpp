#include <AlienBulletFactory.h>


AlienBulletFactory::AlienBulletFactory()
{
	srand(time(0));
}
const vec_of_bullets AlienBulletFactory::getOnslaught()
{
	removeWaste();
	return bullets_;
}

void AlienBulletFactory::generateBullets(const aliens_2d &aliens, const int &size)
{
	if (stopwatch_.getTimeElapsed() > Constants::TIME_BETWEEN_ALIEN_SHOTS
			&& size > 0)
	{
		stopwatch_.start();

		std::vector<unsigned int> endOfCols;
		std::for_each(begin(aliens), end(aliens), [&](auto i)
		{	endOfCols.push_back(i.size()-1);});

		auto shot_col1 = rand() % aliens.size();
		addBullet(endOfCols, shot_col1, aliens);

		for (auto i = 1u; i <= Constants::MAX_ALIEN_SHOTS_PER_ROW; i++)
		{
			shot_col1 = (shot_col1 + i) % aliens.size();
			addBullet(endOfCols, shot_col1, aliens);
		}
	}
}

void AlienBulletFactory::addBullet(const std::vector<unsigned int> &endOfCols,
		const unsigned int &index, const aliens_2d &aliens)
{
	if (aliens.at(index).size() > 0)
	{
		auto shot_row = endOfCols.at(index);
		auto newBullet = std::make_shared<Bullet>(
				aliens.at(index).at(shot_row)->shoot());
		bullets_.push_back(newBullet);
	}
}

void AlienBulletFactory::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bullets_.begin(),
			bullets_.end(), lambda);

	bullets_.erase(remove_idiom, bullets_.end());

}
