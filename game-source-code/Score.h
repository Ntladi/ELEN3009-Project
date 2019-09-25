#ifndef SCORE_H_
#define SCORE_H_
#include <ScreenState.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <memory>
#include "Constants.h"
using text_ptr = std::shared_ptr<sf::Text>;

class Score
{
public:
	Score();
	void setScore(const int & score);
	text_ptr getScore(ScreenState screen_state);
	text_ptr getHighScore(ScreenState screen_state);
private:
	int high_score_;
	int current_score_;
	text_ptr score_ptr_;
	text_ptr high_score_ptr_;
	sf::Font score_font_;
	void saveScore();
	void loadHighScore();
	void initializeText();
	void setSplashPosition();
	void setGamePosition();
	void setFinalHighScorePosition();
	void setFinalScorePosition();
	void setFont();
	void setColour();
	void setScore();
	void setHighScore();
};

#endif
