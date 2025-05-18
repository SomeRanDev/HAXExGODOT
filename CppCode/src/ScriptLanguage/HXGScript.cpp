#include "HXGScript.hpp"

void HXGScript::_bind_methods() {
}

// ---

void HXGScript::set_language(const HXGScriptLanguage* language) {
	this->language = language;
}

// ---

bool HXGScript::_can_instantiate() const {
	return false;
}

bool HXGScript::_editor_can_reload_from_file() {
	return false;
}

godot::Ref<godot::Script> HXGScript::_get_base_script() const {
	// TODO
	return godot::Ref<godot::Script>();
}

godot::String HXGScript::_get_class_icon_path() const {
	// TODO
	return "";
}

godot::Dictionary HXGScript::_get_constants() const {
	// What is this?
	return godot::Dictionary();
}

godot::StringName HXGScript::_get_doc_class_name() const {
	// Not planned
	return godot::StringName();
}

godot::TypedArray<godot::Dictionary> HXGScript::_get_documentation() const {
	// Not planned
	return godot::TypedArray<godot::Dictionary>();
}

godot::StringName HXGScript::_get_global_name() const {
	// TODO
	return godot::StringName("Blablabla");
}

godot::StringName HXGScript::_get_instance_base_type() const {
	// TODO
	return godot::StringName();
}

HXGScriptLanguage* HXGScript::_get_language() const {
#ifdef DEBUG_ENABLED
	ERR_FAIL_NULL_V_MSG(language, nullptr, "HXGScript was not assigned language pointer.");
#endif
	// TODO: is this really the best way?
	return const_cast<HXGScriptLanguage*>(language);
}

int32_t HXGScript::_get_member_line(const godot::StringName& p_member) const {
	// Returns the line number of the class member of name `p_member`
	// Not planned
	return 1; // Should this be 1 or 0????
}

godot::TypedArray<godot::StringName> HXGScript::_get_members() const {
	// TODO
	return godot::TypedArray<godot::StringName>();
}

godot::Dictionary HXGScript::_get_method_info(const godot::StringName& p_method) const {
	// TODO
	// Need to research what this entails
	return godot::Dictionary();
}

godot::Variant HXGScript::_get_property_default_value(const godot::StringName& p_property) const {
	// TODO
	return godot::Variant();
}

godot::Variant HXGScript::_get_rpc_config() const {
	// Not planned
	return godot::Variant();
}

godot::Variant HXGScript::_get_script_method_argument_count(const godot::StringName& p_method) const {
	// TODO
	return godot::Variant();
}

godot::TypedArray<godot::Dictionary> HXGScript::_get_script_method_list() const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

godot::TypedArray<godot::Dictionary> HXGScript::_get_script_property_list() const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

godot::TypedArray<godot::Dictionary> HXGScript::_get_script_signal_list() const {
	// TODO
	return godot::TypedArray<godot::Dictionary>();
}

godot::String HXGScript::_get_source_code() const {
	// TODO
	// Could this return Haxe source code maybe???
	return "";
}

bool HXGScript::_has_method(const godot::StringName& p_method) const {
	// TODO
	return false;
}

bool HXGScript::_has_property_default_value(const godot::StringName& p_property) const {
	// TODO
	return false;
}

bool HXGScript::_has_script_signal(const godot::StringName& p_signal) const {
	// TODO
	return false;
}

bool HXGScript::_has_source_code() const {
	// TODO
	return false;
}

bool HXGScript::_has_static_method(const godot::StringName& p_method) const {
	// TODO
	return false;
}

bool HXGScript::_inherits_script(const godot::Ref<godot::Script>& p_script) const {
	// TODO
	return false;
}

void* HXGScript::_instance_create(godot::Object* p_for_object) const {
	// TODO
	godot::print_line("CALLLLLLLLLLED::: HXGScript::_instance_create");
	return nullptr;
}

bool HXGScript::_instance_has(godot::Object* p_object) const {
	// TODO
	// Not sure what this does, it checks if this script is attached to this specific object??
	return true;
}

bool HXGScript::_is_abstract() const {
	// TODO
	return false;
}

bool HXGScript::_is_placeholder_fallback_enabled() const {
	// TODO
	// WHAT DOES THIS MEAN WHAT DOES THIS MEAN
	return false;
}

bool HXGScript::_is_tool() const {
	// TODO
	return false;
}

bool HXGScript::_is_valid() const {
	// TODO
	return true;
}

void HXGScript::_placeholder_erased(void* p_placeholder) {
	// TODO
	// WHAT DOES THIS MEAN WHAT DOES THIS MEAN
}

void* HXGScript::_placeholder_instance_create(godot::Object* p_for_object) const {
	// TODO
	// WHAT DOES THIS MEAN WHAT DOES THIS MEAN
	return nullptr;
}

godot::Error HXGScript::_reload(bool p_keep_state) {
	// TODO
	return godot::OK;
}

void HXGScript::_set_source_code(const godot::String& p_code) {
	// TODO
}

void HXGScript::_update_exports() {
	// TODO
	// WHAT DOES THIS MEAN WHAT DOES THIS MEAN
}
