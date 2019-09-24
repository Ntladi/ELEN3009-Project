#include <Score.h>

Score::Score()
{
	high_score_ = 0;
	current_score_ = 0;
	loadHighScore();
	initializeText();
}

void Score::loadHighScore()
{
	std::ifstream inFile = std::ifstream("highscore.txt");
	inFile >> high_score_;
	inFile.close();
}

text_ptr Score::getScore(ScreenStates screenstate)
{
	switch(screenstate)
	{
	case ScreenStates::GAME_SCREEN:
		setGamePosition();
		break;
	case ScreenStates::GAME_OVER:
		setFinalScorePosition();
		break;
	case ScreenStates::GAME_WON:
		setFinalScorePosition();
		break;
	default:
		break;
	}
	setScore();
	return score_ptr_;
}

text_ptr Score::getHighScore(ScreenStates screenstate)
{
	switch(screenstate)
	{
	case ScreenStates::SPLASHSCREEN:
		setSplashPosition();
		break;
	case ScreenStates::GAME_OVER:
		setFinalHighScorePosition();
		break;
	case ScreenStates::GAME_WON:
		setFinalHighScorePosition();
		break;
	default:
		break;
	}

	setHighScore();
	return high_score_ptr_;
}
void Score::initializeText()
{
	score_ptr_ = std::make_shared<sf::Text>();
	high_score_ptr_ = std::make_shared<sf::Text>();
	setFont();
	setColour();
	setSplashPosition();
}

void Score::setScore(const int & score)
{
	current_score_ = score;
}

void Score::setSplashPosition()
{
	high_score_ptr_->setCharacterSize(Constants::HIGH_SCORE_INITIAL_CHAR_SIZE);
	high_score_ptr_->setPosition(sf::Vector2f(Constants::HIGH_SCORE_INITIAL_X, Constants::HIGH_SCORE_INITIAL_Y));
}

void Score::setFinalHighScorePosition()
{
	saveScore();
	high_score_ptr_->setCharacterSize(Constants::FINAL_SCORE_CHAR_SIZE);
	high_score_ptr_->setPosition(sf::Vector2f(Constants::FINAL_SCORE_X, Constants::FINAL_HIGH_SCORE_Y));
}

void Score::setGamePosition()
{
	score_ptr_->setCharacterSize(Constants::SCORE_CHAR_SIZE);
	score_ptr_->setPosition(sf::Vector2f(Constants::SCORE_INITIAL_X, Constants::SCORE_INITIAL_Y));
}

void Score::setFinalScorePosition()
{
	score_ptr_->setCharacterSize(Constants::FINAL_SCORE_CHAR_SIZE);
	score_ptr_->setPosition(sf::Vector2f(Constants::FINAL_SCORE_X, Constants::FINAL_SCORE_Y));
}

void Score::setFont()
{
	score_font_.loadFromFile("Assets/PermanentMarker.ttf");
	score_ptr_->setFont(score_font_);
	high_score_ptr_->setFont(score_font_);
}

void Score::setColour()
{
	sf::Color color(255,100,0);
	score_ptr_->setFillColor(color);
	high_score_ptr_->setFillColor(color);
}

void Score::setScore()
{
	auto score_string = std::to_string(current_score_);
	score_ptr_->setString(score_string);
}

void Score::setHighScore()
{
	auto score_string = std::to_string(high_score_);
	high_score_ptr_->setString(score_string);
}

void Score::saveScore()
{
	if(current_score_ > high_score_)
		high_score_ = current_score_;

	std::ofstream outFile = std::ofstream("highscore.txt");
	outFile << high_score_;

	outFile.close();
}
