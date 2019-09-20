#include <AlienBulletFactory.h>


BulletFactory::BulletFactory()
{
	srand(time(0));
}
vec_of_bullets BulletFactory::getOnslaught()
{
	removeWaste();
	return bullets_;
}

void BulletFactory::generateBullets(aliens_2d &aliens, const int &size)
{
	if (stopwatch_.getTimeElapsed() > Constants::SECONDS_BETWEEN_ALIEN_SHOTS
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

void BulletFactory::addBullet(std::vector<unsigned int> &endOfCols,
		const unsigned int &index, aliens_2d &aliens)
{
	if (aliens.at(index).size() > 0)
	{
		auto shot_row = endOfCols.at(index);
		auto newBullet = std::make_shared<Bullet>(
				aliens.at(index).at(shot_row)->shoot());
		bullets_.push_back(newBullet);
	}
}

void BulletFactory::removeWaste()
{
	auto lambda = [](auto i)
	{	return !(i->getStatus());};

	auto remove_idiom = std::remove_if(bullets_.begin(),
			bullets_.end(), lambda);

	bullets_.erase(remove_idiom, bullets_.end());

}
