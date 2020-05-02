#pragma once
class Player
{
public:
	Player(char c) : mPlayerType{ c }, mScore{ 0 } {}
	char getType() { return mPlayerType; }
	int getScore() { return mScore; }
	void setType(char c) { mPlayerType = c; }
	bool isTurn() { return bTurn; }
	void setTurn(bool b) { bTurn = b; }
	void incrementScore() { mScore++; }

private:
	char mPlayerType;
	int mScore;
	bool bTurn;

};

