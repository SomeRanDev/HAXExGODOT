#include "HXGScriptLanguage.hpp"
#include "HXGScript.hpp"

#include <godot_cpp/classes/resource_loader.hpp>

void HXGScriptLanguage::_bind_methods() {
}

// ---

void HXGScriptLanguage::_add_global_constant(const godot::StringName& p_name, const godot::Variant& p_value) {
	// TODO
}

void HXGScriptLanguage::_add_named_global_constant(const godot::StringName& p_name, const godot::Variant& p_value) {
	// TODO
}

godot::String HXGScriptLanguage::_auto_indent_code(const godot::String& p_code, int32_t p_from_line, int32_t p_to_line) const {
	// TODO
	return p_code;
}

bool HXGScriptLanguage::_can_inherit_from_file() const {
	// TODO
	return true;
}

bool HXGScriptLanguage::_can_make_function() const {
	// TODO
	return false;
}

/**
 * Godot 4.4 link to how this function is used (search for `complete_code` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L412
 */
godot::Dictionary HXGScriptLanguage::_complete_code(const godot::String& p_code, const godot::String& p_path, godot::Object* p_owner) const {
	// TODO
	return godot::Dictionary();
}

godot::Object* HXGScriptLanguage::_create_script() const {
	HXGScript* result = memnew(HXGScript);
	result->set_language(this);
	return result;
}

godot::TypedArray<godot::Dictionary> HXGScriptLanguage::_debug_get_current_stack_info() {
	// Not planned
	return godot::TypedArray<godot::Dictionary>();
}

godot::String HXGScriptLanguage::_debug_get_error() const {
	// Not planned
	return godot::String();
}

godot::Dictionary HXGScriptLanguage::_debug_get_globals(int32_t p_max_subitems, int32_t p_max_depth) {
	// Not planned
	return godot::Dictionary();
}

int32_t HXGScriptLanguage::_debug_get_stack_level_count() const {
	// Not planned
	return 0;
}

godot::String HXGScriptLanguage::_debug_get_stack_level_function(int32_t p_level) const {
	// Not planned
	return godot::String();
}

void* HXGScriptLanguage::_debug_get_stack_level_instance(int32_t p_level) {
	// Not planned
	return nullptr;
}

int32_t HXGScriptLanguage::_debug_get_stack_level_line(int32_t p_level) const {
	// Not planned
	return 0;
}

godot::Dictionary HXGScriptLanguage::_debug_get_stack_level_locals(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) {
	// Not planned
	return godot::Dictionary();
}

godot::Dictionary HXGScriptLanguage::_debug_get_stack_level_members(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) {
	// Not planned
	return godot::Dictionary();
}

godot::String HXGScriptLanguage::_debug_get_stack_level_source(int32_t p_level) const {
	// Not planned
	return godot::String();
}

godot::String HXGScriptLanguage::_debug_parse_stack_level_expression(int32_t p_level, const godot::String& p_expression, int32_t p_max_subitems, int32_t p_max_depth) {
	// Not planned
	return godot::String();
}

int32_t HXGScriptLanguage::_find_function(const godot::String& p_function, const godot::String& p_code) const {
	// TODO
	return -1;
}

void HXGScriptLanguage::_finish() {
	// TODO
}

void HXGScriptLanguage::_frame() {
	// TODO
}

/**
 * Godot 4.4 link to how this function is used (search for `get_built_in_templates` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L288
 */
godot::TypedArray<godot::Dictionary> HXGScriptLanguage::_get_built_in_templates(const godot::StringName& p_object) const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

godot::PackedStringArray HXGScriptLanguage::_get_comment_delimiters() const {
	// TODO
	return godot::PackedStringArray();
}

godot::PackedStringArray HXGScriptLanguage::_get_doc_comment_delimiters() const {
	// TODO
	return godot::PackedStringArray();
}

godot::String HXGScriptLanguage::_get_extension() const {
	return "hxg";
}

/**
 * Godot 4.4 link to how this function is used (search for `get_global_class_name` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L675
 */
godot::Dictionary HXGScriptLanguage::_get_global_class_name(const godot::String& path) const {
	godot::Ref<HXGScript> script = godot::ResourceLoader::get_singleton()->load(path);
	if(!script.is_valid() || !script->_is_valid()) {
		return godot::Dictionary();
	}

	godot::Dictionary result;
	result["name"] = script->_get_global_name();
	result["base_type"] = script->_get_instance_base_type();
	result["icon_path"] = script->_get_class_icon_path();
	result["is_abstract"] = script->_is_abstract();
	result["is_tool"] = script->_is_tool();
	return result;
}

godot::String HXGScriptLanguage::_get_name() const {
	return "Haxe";
}

/**
 * Godot 4.4 link to how this function is used (search for `get_public_annotations` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L640
 */
godot::TypedArray<godot::Dictionary> HXGScriptLanguage::_get_public_annotations() const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

/**
 * Godot 4.4 link to how this function is used (search for `get_public_constants` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L629
 */
godot::Dictionary HXGScriptLanguage::_get_public_constants() const {
	// TODO
	return godot::Dictionary();
}

/**
 * Godot 4.4 link to how this function is used (search for `get_public_functions` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L620
 */
godot::TypedArray<godot::Dictionary> HXGScriptLanguage::_get_public_functions() const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

godot::PackedStringArray HXGScriptLanguage::_get_recognized_extensions() const {
	return godot::PackedStringArray({"hxg"});
}

godot::PackedStringArray HXGScriptLanguage::_get_reserved_words() const {
	// TODO
	return godot::PackedStringArray();
}

godot::PackedStringArray HXGScriptLanguage::_get_string_delimiters() const {
	// TODO
	return godot::PackedStringArray();
}

godot::String HXGScriptLanguage::_get_type() const {
	return "HXGScript";
}

bool HXGScriptLanguage::_handles_global_class_type(const godot::String& type) const {
	return type == _get_type();
}

bool HXGScriptLanguage::_has_named_classes() const {
	// TODO
	return false;
}

void HXGScriptLanguage::_init() {
	// TODO
}

bool HXGScriptLanguage::_is_control_flow_keyword(const godot::String& p_keyword) const {
	// TODO
	return false;
}

bool HXGScriptLanguage::_is_using_templates() {
	// TODO
	return false;
}

/**
 * Godot 4.4 link to how this function is used (search for `lookup_code` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L461
 */
godot::Dictionary HXGScriptLanguage::_lookup_code(const godot::String& p_code, const godot::String& p_symbol, const godot::String& p_path, godot::Object* p_owner) const {
	// TODO
	return godot::Dictionary();
}

godot::String HXGScriptLanguage::_make_function(const godot::String& p_class_name, const godot::String& p_function_name, const godot::PackedStringArray& p_function_args) const {
	// TODO
	return godot::String();
}

godot::Ref<godot::Script> HXGScriptLanguage::_make_template(const godot::String& p_template, const godot::String& p_class_name, const godot::String& p_base_class_name) const {
	godot::Ref<HXGScript> script;
	script.instantiate();
	script->set_language(this);
	script->set_source_code("None");
	return script;
}

godot::Error HXGScriptLanguage::_open_in_external_editor(const godot::Ref<godot::Script>& p_script, int32_t p_line, int32_t p_column) {
	// TODO
	return godot::Error::ERR_UNAVAILABLE;
}

bool HXGScriptLanguage::_overrides_external_editor() {
	// TODO
	return false;
}

godot::ScriptLanguage::ScriptNameCasing HXGScriptLanguage::_preferred_file_name_casing() const {
	return godot::ScriptLanguage::SCRIPT_NAME_CASING_AUTO;
}

int32_t HXGScriptLanguage::_profiling_get_accumulated_data(godot::ScriptLanguageExtensionProfilingInfo* p_info_array, int32_t p_info_max) {
	// Not planned
	return 0;
}

int32_t HXGScriptLanguage::_profiling_get_frame_data(godot::ScriptLanguageExtensionProfilingInfo* p_info_array, int32_t p_info_max) {
	// Not planned
	return 0;
}

void HXGScriptLanguage::_profiling_set_save_native_calls(bool p_enable) {
	// Not planned
}

void HXGScriptLanguage::_profiling_start() {
	// Not planned
}

void HXGScriptLanguage::_profiling_stop() {
	// Not planned
}

void HXGScriptLanguage::_reload_all_scripts() {
	// TODO
}

void HXGScriptLanguage::_reload_scripts(const godot::Array& p_scripts, bool p_soft_reload) {
	// TODO
}

void HXGScriptLanguage::_reload_tool_script(const godot::Ref<godot::Script>& p_script, bool p_soft_reload) {
	// TODO
}

void HXGScriptLanguage::_remove_named_global_constant(const godot::StringName& p_name) {
	// TODO
}

bool HXGScriptLanguage::_supports_builtin_mode() const {
	// TODO
	return false;
}

bool HXGScriptLanguage::_supports_documentation() const {
	// TODO
	return false;
}

void HXGScriptLanguage::_thread_enter() {
}

void HXGScriptLanguage::_thread_exit() {
}

/**
 * Godot 4.4 link to how this function is used (search for `validate` function):
 * https://github.com/godotengine/godot/blob/4.4/core/object/script_language_extension.h#L315
 */
godot::Dictionary HXGScriptLanguage::_validate(const godot::String& p_script, const godot::String& p_path, bool p_validate_functions, bool p_validate_errors, bool p_validate_warnings, bool p_validate_safe_lines) const {
	// TODO
	return godot::Dictionary();
}

godot::String HXGScriptLanguage::_validate_path(const godot::String& p_path) const {
	// TODO
	return godot::String();
}
