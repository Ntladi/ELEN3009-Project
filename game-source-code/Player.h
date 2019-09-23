#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <memory>
#include <tuple>
#include "Bullet.h"
#include "IMovingEntity.h"
#include "PlayerBulletFactory.h"
using two_floats = std::tuple<float, float>;
using vec_of_bullets = std::vector<std::shared_ptr<Bullet>>;

class Player : public IMovingEntity
{
public:
	Player(Orientation orientation = Orientation::FACE_UP);
	void setPosition(const two_floats & position);
	vec_of_bullets getShotsFired();
	void setMoveDirection(const MoveDirection &direction);
	bool isNotMovingVertucally();
	virtual void move() override;
	void shoot();
	bool getHit() const;
	void resetPosition(Orientation orientation);
	void startClock();
private:
	PlayerBulletFactory bullet_factory_;
	void incrementPlayerPosition();
	void movePlayerHorizontally();
	void movePlayerVertically();
	void changeOrientation();
	virtual two_floats initializePosition() override;
};

#endif
