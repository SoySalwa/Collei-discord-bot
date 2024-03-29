#pragma once
#ifndef BOT_TOKEN_H
#define BOT_TOKEN_H

#include <iostream>

class botToken {
public:
	/** Is a function for to get the token of the bot in a place determinated.
		@return The bot token. */
	static std::string Token() {
		std::string token = "MTIyMzMyMDA3NTc4MDc1NTQ3Ng.GclH8L.a-RFP1_S_aVO8PWejdEd0dKp8RNTqDEc6Evb04";
		return token;
	}
};

#endif // !BOT_TOKEN_H
