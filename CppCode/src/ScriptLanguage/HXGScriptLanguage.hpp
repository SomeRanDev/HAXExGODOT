#pragma once

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>

class HXGScriptLanguage : public godot::ScriptLanguageExtension {
	GDCLASS(HXGScriptLanguage, ScriptLanguageExtension);

	static HXGScriptLanguage* singleton;

public:
	static void _bind_methods();

	static HXGScriptLanguage* get_singleton();
	static HXGScriptLanguage* delete_singleton();

	godot::String _get_name() const override;
	godot::String _get_type() const override;
	godot::String _get_extension() const override;
	godot::PackedStringArray _get_reserved_words() const override;

	bool _supports_documentation() const override;

	bool _handles_global_class_type(const godot::String& p_type) const override;

	void _thread_enter() override;
	void _thread_exit() override;
	void _frame() override;
};
