#pragma once

#include <godot_cpp/classes/script_extension.hpp>

#include "HXGScriptLanguage.hpp"

class HXGScriptBase : public godot::ScriptExtension {
	GDCLASS(HXGScriptBase, ScriptExtension);

public:
	static void _bind_methods();

	HXGScriptLanguage* _get_language() const override;
	godot::StringName _get_global_name() const override;
	bool _editor_can_reload_from_file() override;
	bool _can_instantiate() const override;
	bool _inherits_script(const godot::Ref<godot::Script>& p_script) const override;
};
