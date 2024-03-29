#include "Collei.h"
#include <dpp/dpp.h>
#include <dpp/guild.h>
#include "botToken.h"
#include "slash_commands.h"
#include "events.h"

/* A dpp::guild is a pointer is necessary for encounter the guild.*/
// const dpp::guild* guild = dpp::find_guild(1084471620086804490);
/* The name of the guild of this collei. */
// std::string guild_name = guild->name;

int main() {
	dpp::cluster collei(botToken::Token(), dpp::i_all_intents);
	
	collei.on_ready([&collei](const dpp::ready_t& event) {
		collei.set_presence(dpp::presence(
			dpp::ps_online,
			dpp::at_watching,
			"Colleigas De Tabibito"
			));
		std::cout << "Hi. I'm collei and i'm here!!" << std::endl;

		slc::create_slash_commands(collei);
	});

	slc::load_slash_commands(collei);
	evs::load_collei_events(collei);

	collei.start(dpp::st_wait);
	return 0;
}