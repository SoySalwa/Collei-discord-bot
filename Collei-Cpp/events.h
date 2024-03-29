#pragma once
#ifndef EVENTS_H
#define EVENTS_H

#include <dpp/dpp.h>
#include <iostream>

class evs {
public:
	/** Function for load all collei events. 
		@param dpp::cluster for to valite the event. 
		@return Two events for now: guild_member_add and guild_member_remove. */
	static void load_collei_events(dpp::cluster& collei) {
		collei.on_guild_member_add([&collei](const dpp::guild_member_add_t & member) {
		});

		collei.on_guild_member_remove([&collei](const dpp::guild_member_remove_t& member) {
		});
	}
};

#endif // !EVENTS_H
