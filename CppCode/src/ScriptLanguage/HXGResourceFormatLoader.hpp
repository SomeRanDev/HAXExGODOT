#pragma once

#include <godot_cpp/classes/resource_format_loader.hpp>

class HXGResourceFormatLoader : public godot::ResourceFormatLoader {
	GDCLASS(HXGResourceFormatLoader, ResourceFormatLoader);

public:
	static void _bind_methods();

	godot::PackedStringArray _get_recognized_extensions() const override;
	godot::String _get_resource_type(const godot::String& p_path) const override;
	bool _exists(const godot::String& p_path) const override;
	bool _handles_type(const godot::StringName& p_type) const override;
	godot::Variant _load(const godot::String& p_path, const godot::String& p_original_path, bool p_use_sub_threads, int32_t p_cache_mode) const override;
};
