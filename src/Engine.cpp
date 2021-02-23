//
// Created by professor on 2/23/21.
//

#include "Engine.h"

std::vector<Token> Engine::Tokenize(std::fstream &it) {
	char c;
	std::string buff;
	bool is_insn_found = false;

	while (it.get(c)) {
		///{spaces}{comment|insn}{comment|insn - parse}{spaces}{arg|no arg}{parse}{spaces}{new_line|end of input};
		///tokenizaation in two phases:
		/// insn arg|noarg comment(maybe skip) new line|end of input
		///determine which insn and what it is followed by
	}
	return tokens;
}