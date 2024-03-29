#pragma once
#ifndef SLASH_COMMANDS_H
#define SLASH_COMMANDS_H

#include <dpp/dpp.h>
#include <iostream>

class slc {
public:
		/** Create a new slash commands. 
			@param dpp::cluster for register commands. */
	static void create_slash_commands(dpp::cluster& collei) {
		if (dpp::run_once<struct register_slash_commands>()) {
			/* Create a new global slash commands for the event ready. */
			std::vector<dpp::slashcommand> slash_commands;
			slash_commands.emplace_back("bot_info", "The information this bot.", collei.me.id);
			slash_commands.emplace_back("genshin_help", "For to request help in the server.", collei.me.id)
				.add_option(dpp::command_option(dpp::co_integer, "UID", "Your UID of player."))
				.add_option(dpp::command_option(dpp::co_string, "Region", "You region AM/EU,"))
				.add_option(dpp::command_option(dpp::co_string, "Request", "You request."));

			/* In now register the commands. */
			collei.global_bulk_command_create(slash_commands, [&collei](const dpp::confirmation_callback_t& result) {
				if (result.is_error()) {
					std::cout << "error: " << result.get_error().human_readable << std::endl;
				}
				else {
					std::cout << "Slash commands registered: " << result.get<dpp::slashcommand_map>().size() << std::endl;
				}
			});
		}
	}
		/* Load the slash commands and the use it for this bot. */
	static void load_slash_commands(dpp::cluster & collei) {
		collei.on_slashcommand([&collei](const dpp::slashcommand_t& interaction) {

			if (interaction.command.get_command_name() == "bot_info") {
				dpp::user* user = dpp::find_user(collei.me.id);
				dpp::application app = dpp::application();
				dpp::embed bot_embed = dpp::embed()

					.set_color(dpp::colors::alien_green)
					.set_author(user->username, "", user->get_avatar_url(1024, dpp::i_png))
					.set_thumbnail(user->get_avatar_url(1024, dpp::i_png))
					.add_field("Bot Name", user->username, true)
					.add_field("Bot Id", std::to_string(collei.me.id), true)
					.add_field("Library", "Discord C++ (DPP)", true)
					.add_field("Library Version", dpp::utility::version(), true)
					.add_field("Owner", "<@399254838438789130>", true)
					.set_footer(dpp::embed_footer().set_text("Okay, this is my information").set_icon(user->get_avatar_url(1024, dpp::i_png)))
					.set_timestamp(time(0));

				dpp::message embed(interaction.command.channel_id, bot_embed);
				interaction.reply(embed);
			}

			if (interaction.command.get_command_name() == "genshin_help") {
				interaction.reply("This command it's in maintenance.");
			}
		});
	}
};

#endif // !SLASH_COMMANDS_H
