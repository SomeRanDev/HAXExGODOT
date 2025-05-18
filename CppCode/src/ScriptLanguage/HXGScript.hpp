#pragma once

#include <godot_cpp/classes/script_extension.hpp>

#include "HXGScriptLanguage.hpp"

class HXGScript : public godot::ScriptExtension {
	GDCLASS(HXGScript, ScriptExtension);

	const HXGScriptLanguage* language;

public:
	static void _bind_methods();

	// ---

	void set_language(const HXGScriptLanguage* language);

	// ---

	bool _can_instantiate() const override;
	bool _editor_can_reload_from_file() override;

	godot::Ref<godot::Script> _get_base_script() const override;
	godot::String _get_class_icon_path() const override;
	godot::Dictionary _get_constants() const override;
	godot::StringName _get_doc_class_name() const override;
	godot::TypedArray<godot::Dictionary> _get_documentation() const override;
	godot::StringName _get_global_name() const override;
	godot::StringName _get_instance_base_type() const override;
	HXGScriptLanguage* _get_language() const override;
	int32_t _get_member_line(const godot::StringName& p_member) const override;
	godot::TypedArray<godot::StringName> _get_members() const override;
	godot::Dictionary _get_method_info(const godot::StringName& p_method) const override;
	godot::Variant _get_property_default_value(const godot::StringName& p_property) const override;
	godot::Variant _get_rpc_config() const override;
	godot::Variant _get_script_method_argument_count(const godot::StringName& p_method) const override;
	godot::TypedArray<godot::Dictionary> _get_script_method_list() const override;
	godot::TypedArray<godot::Dictionary> _get_script_property_list() const override;
	godot::TypedArray<godot::Dictionary> _get_script_signal_list() const override;
	godot::String _get_source_code() const override;

	bool _has_method(const godot::StringName& p_method) const override;
	bool _has_property_default_value(const godot::StringName& p_property) const override;
	bool _has_script_signal(const godot::StringName& p_signal) const override;
	bool _has_source_code() const override;
	bool _has_static_method(const godot::StringName& p_method) const override;

	bool _inherits_script(const godot::Ref<godot::Script>& p_script) const override;
	void* _instance_create(godot::Object* p_for_object) const override;
	bool _instance_has(godot::Object* p_object) const override;

	bool _is_abstract() const override;
	bool _is_placeholder_fallback_enabled() const override;
	bool _is_tool() const override;
	bool _is_valid() const override;

	void _placeholder_erased(void* p_placeholder) override;
	void* _placeholder_instance_create(godot::Object* p_for_object) const override;

	godot::Error _reload(bool p_keep_state) override;

	void _set_source_code(const godot::String& p_code) override;

	void _update_exports() override;
};
