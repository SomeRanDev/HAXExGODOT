#include "HXGResourceFormatLoader.hpp"
#include "HXGEditorPlugin.hpp"
#include "HXGScript.hpp"
#include "HXGUtils.hpp"

#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/script.hpp>

void HXGResourceFormatLoader::_bind_methods() {
}

// ---

godot::PackedStringArray HXGResourceFormatLoader::_get_recognized_extensions() const {
	return godot::PackedStringArray({"hxg"});
}

bool HXGResourceFormatLoader::_handles_type(const godot::StringName& p_type) const {
	return p_type == HXGScript::get_class_static() || p_type == godot::Script::get_class_static();
}

godot::String HXGResourceFormatLoader::_get_resource_type(const godot::String& p_path) const {
	if(p_path.get_extension() == "hxg") {
		return HXGScript::get_class_static();
	} else {
		return "";
	}
}

bool HXGResourceFormatLoader::_exists(const godot::String& p_path) const {
	return godot::FileAccess::file_exists(p_path);
}

godot::Variant HXGResourceFormatLoader::_load(const godot::String& p_path, const godot::String& p_original_path, bool p_use_sub_threads, int32_t p_cache_mode) const {
	godot::Ref<HXGScript> script = HXGEditorPlugin::self->get_language()->_create_script();
	script->set_path(p_original_path);
	script->set_source_code(godot::FileAccess::get_file_as_string(p_path));

	godot::Error status = script->reload();
	if(status != godot::OK) {
		HXGUtils::print_verbose(vformat("HXGResourceFormatLoader::_load returned error on load: %d", status));
		return status;
	}

	HXGUtils::print_verbose(vformat("HXGResourceFormatLoader::_load returned successfully loaded: %s", p_path));
	return script;
}
