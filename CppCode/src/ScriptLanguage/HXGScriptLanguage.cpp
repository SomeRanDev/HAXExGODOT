#include "HXGScriptLanguage.hpp"

HXGScriptLanguage* HXGScriptLanguage::singleton = nullptr;

void HXGScriptLanguage::_bind_methods() {
}

HXGScriptLanguage* HXGScriptLanguage::get_singleton() {
	if(singleton == nullptr) {
		singleton = memnew(HXGScriptLanguage);
		godot::Engine::get_singleton()->register_script_language(singleton);
	}
	return singleton;
}

HXGScriptLanguage* HXGScriptLanguage::delete_singleton() {
	if(singleton != nullptr) {
		godot::Engine::get_singleton()->unregister_script_language(singleton);
		memdelete(singleton);
		singleton = nullptr;
	}
	return singleton;
}

godot::String HXGScriptLanguage::_get_name() const {
	return "Haxe";
}

godot::String HXGScriptLanguage::_get_type() const {
	return "HXGScript";
}

godot::String HXGScriptLanguage::_get_extension() const {
	return "hx";
}

godot::PackedStringArray HXGScriptLanguage::_get_reserved_words() const {
	return godot::PackedStringArray();
}

bool HXGScriptLanguage::_supports_documentation() const {
	return false;
}

bool HXGScriptLanguage::_handles_global_class_type(const godot::String& type) const {
	godot::print_line(type);
	return type == "HXGScript" || type == "GDScript";
}

void HXGScriptLanguage::_thread_enter() {}
void HXGScriptLanguage::_thread_exit() {}
void HXGScriptLanguage::_frame() {}
