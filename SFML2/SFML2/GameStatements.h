/*!
* \file
* \brief Header file, which store types current game statement.
*/
#ifndef GAME_STATEMENTS
#define GAME_STATEMENTS
//! Set of types of statements of game
enum GameStatements
{
	NOT_STARTED, //!< Game in main menu
	STARTED, //!< Game is playing
	PAUSED, //!< Game in pause menu
	LOOSED, //!< Player loosed. Menu with score
};
#endif // !GAME_STATEMENTS

