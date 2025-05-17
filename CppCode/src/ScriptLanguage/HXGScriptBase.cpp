#include "HXGScriptBase.hpp"

void HXGScriptBase::_bind_methods() {
}

HXGScriptLanguage* HXGScriptBase::_get_language() const {
	return HXGScriptLanguage::get_singleton();
}

godot::StringName HXGScriptBase::_get_global_name() const {
	return godot::StringName("Blablabla");
}

bool HXGScriptBase::_editor_can_reload_from_file() {
	return false;
}

bool HXGScriptBase::_can_instantiate() const {
	return false;
}

bool HXGScriptBase::_inherits_script(const godot::Ref<godot::Script>& p_script) const {
	return false;
}
