#pragma once

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/script.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>
#include <godot_cpp/variant/string.hpp>

class HXGScriptLanguage : public godot::ScriptLanguageExtension {
	GDCLASS(HXGScriptLanguage, ScriptLanguageExtension);

public:
	static void _bind_methods();

	// ---

	void _add_global_constant(const godot::StringName& p_name, const godot::Variant& p_value) override;
	void _add_named_global_constant(const godot::StringName& p_name, const godot::Variant& p_value) override;
	godot::String _auto_indent_code(const godot::String& p_code, int32_t p_from_line, int32_t p_to_line) const override;
	bool _can_inherit_from_file() const override;
	bool _can_make_function() const override;
	godot::Dictionary _complete_code(const godot::String& p_code, const godot::String& p_path, godot::Object* p_owner) const override;
	godot::Object* _create_script() const override;
	godot::TypedArray<godot::Dictionary> _debug_get_current_stack_info() override;
	godot::String _debug_get_error() const override;
	godot::Dictionary _debug_get_globals(int32_t p_max_subitems, int32_t p_max_depth) override;
	int32_t _debug_get_stack_level_count() const override;
	godot::String _debug_get_stack_level_function(int32_t p_level) const override;
	void* _debug_get_stack_level_instance(int32_t p_level) override;
	int32_t _debug_get_stack_level_line(int32_t p_level) const override;
	godot::Dictionary _debug_get_stack_level_locals(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) override;
	godot::Dictionary _debug_get_stack_level_members(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) override;
	godot::String _debug_get_stack_level_source(int32_t p_level) const override;
	godot::String _debug_parse_stack_level_expression(int32_t p_level, const godot::String& p_expression, int32_t p_max_subitems, int32_t p_max_depth) override;
	int32_t _find_function(const godot::String& p_function, const godot::String& p_code) const override;
	void _finish() override;
	void _frame() override;
	godot::TypedArray<godot::Dictionary> _get_built_in_templates(const godot::StringName& p_object) const override;
	godot::PackedStringArray _get_comment_delimiters() const override;
	godot::PackedStringArray _get_doc_comment_delimiters() const override;
	godot::String _get_extension() const override;
	godot::Dictionary _get_global_class_name(const godot::String& p_path) const override;
	godot::String _get_name() const override;
	godot::TypedArray<godot::Dictionary> _get_public_annotations() const override;
	godot::Dictionary _get_public_constants() const override;
	godot::TypedArray<godot::Dictionary> _get_public_functions() const override;
	godot::PackedStringArray _get_recognized_extensions() const override;
	godot::PackedStringArray _get_reserved_words() const override;
	godot::PackedStringArray _get_string_delimiters() const override;
	godot::String _get_type() const override;
	bool _handles_global_class_type(const godot::String& p_type) const override;
	bool _has_named_classes() const override;
	void _init() override;
	bool _is_control_flow_keyword(const godot::String& p_keyword) const override;
	bool _is_using_templates() override;
	godot::Dictionary _lookup_code(const godot::String& p_code, const godot::String& p_symbol, const godot::String& p_path, godot::Object* p_owner) const override;
	godot::String _make_function(const godot::String& p_class_name, const godot::String& p_function_name, const godot::PackedStringArray& p_function_args) const override;
	godot::Ref<godot::Script> _make_template(const godot::String& p_template, const godot::String& p_class_name, const godot::String& p_base_class_name) const override;
	godot::Error _open_in_external_editor(const godot::Ref<godot::Script>& p_script, int32_t p_line, int32_t p_column) override;
	bool _overrides_external_editor() override;
	ScriptLanguage::ScriptNameCasing _preferred_file_name_casing() const override;
	int32_t _profiling_get_accumulated_data(godot::ScriptLanguageExtensionProfilingInfo* p_info_array, int32_t p_info_max) override;
	int32_t _profiling_get_frame_data(godot::ScriptLanguageExtensionProfilingInfo* p_info_array, int32_t p_info_max) override;
	void _profiling_set_save_native_calls(bool p_enable) override;
	void _profiling_start() override;
	void _profiling_stop() override;
	void _reload_all_scripts() override;
	void _reload_scripts(const godot::Array& p_scripts, bool p_soft_reload) override;
	void _reload_tool_script(const godot::Ref<godot::Script>& p_script, bool p_soft_reload) override;
	void _remove_named_global_constant(const godot::StringName& p_name) override;
	bool _supports_builtin_mode() const override;
	bool _supports_documentation() const override;
	void _thread_enter() override;
	void _thread_exit() override;
	godot::Dictionary _validate(const godot::String& p_script, const godot::String& p_path, bool p_validate_functions, bool p_validate_errors, bool p_validate_warnings, bool p_validate_safe_lines) const override;
	godot::String _validate_path(const godot::String& p_path) const override;
};
