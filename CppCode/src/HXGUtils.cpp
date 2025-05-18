#include "HXGUtils.hpp"

#include <godot_cpp/core/print_string.hpp>

void HXGUtils::print_verbose(const godot::String p_message) {
#ifdef DEBUG_ENABLED
	if(godot::is_print_verbose_enabled()) {
		godot::print_line_rich(vformat(godot::String::utf8("『[color=orange]HAXE[/color]x[color=aqua]GODOT[/color]』 %s"), p_message));
	}
#endif
}
