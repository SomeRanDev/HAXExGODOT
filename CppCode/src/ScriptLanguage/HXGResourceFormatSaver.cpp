#include "HXGResourceFormatSaver.hpp"
#include "HXGScript.hpp"

#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/resource_saver.hpp>
#include <godot_cpp/core/error_macros.hpp>

void HXGResourceFormatSaver::_bind_methods() {
}

// ---

godot::PackedStringArray HXGResourceFormatSaver::_get_recognized_extensions(const godot::Ref<godot::Resource>& resource) const {
	return godot::PackedStringArray({"hxg"});
}

bool HXGResourceFormatSaver::_recognize(const godot::Ref<godot::Resource>& resource) const {
	return godot::Ref<HXGScript>(resource).is_valid();
}

godot::Error HXGResourceFormatSaver::_save(const godot::Ref<godot::Resource>& resource, const godot::String& p_path, uint32_t flags) {
	godot::Ref<HXGScript> hxg = godot::Ref<HXGScript>(resource);
	if(hxg.is_null()) {
		return godot::ERR_INVALID_PARAMETER;
	}

	godot::Ref<godot::FileAccess> file = godot::FileAccess::open(p_path, godot::FileAccess::ModeFlags::WRITE);
	if(file.is_null()) {
		return godot::ERR_FILE_CANT_WRITE;
	}
	file->store_string(hxg->get_source_code());
	return file->get_error();
}
