#pragma once

#include <godot_cpp/classes/resource_format_saver.hpp>

class HXGResourceFormatSaver : public godot::ResourceFormatSaver {
	GDCLASS(HXGResourceFormatSaver, ResourceFormatSaver);

public:
	static void _bind_methods();

	godot::PackedStringArray _get_recognized_extensions(const godot::Ref<godot::Resource>& resource) const override;
	bool _recognize(const godot::Ref<godot::Resource>& resource) const override;
	godot::Error _save(const godot::Ref<godot::Resource>& resource, const godot::String& path, uint32_t flags) override;
};
