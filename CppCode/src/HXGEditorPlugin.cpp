#include "HXGEditorPlugin.hpp"

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/resource_saver.hpp>

HXGEditorPlugin* HXGEditorPlugin::self = nullptr;

void HXGEditorPlugin::_bind_methods() {
}

// ---

void HXGEditorPlugin::_enter_tree() {
	self = this;
	_create_language();
	_create_loader();
	_create_saver();
}

void HXGEditorPlugin::_exit_tree() {
	self = nullptr;
	_delete_language();
	_delete_loader();
	_delete_saver();
}

// ---

HXGScriptLanguage* HXGEditorPlugin::get_language() const {
	return language;
}

void HXGEditorPlugin::_create_language() {
	if(unlikely(language != nullptr)) {
		_delete_language();
	}

	language = memnew(HXGScriptLanguage);
#ifdef DEBUG_ENABLED
	ERR_FAIL_NULL(language);
#endif
	godot::Engine::get_singleton()->register_script_language(language);
}

void HXGEditorPlugin::_create_loader() {
	if(unlikely(loader.is_valid())) {
		_delete_loader();
	}

	loader.instantiate();
	godot::ResourceLoader::get_singleton()->add_resource_format_loader(loader);
}

void HXGEditorPlugin::_create_saver() {
	if(unlikely(saver.is_valid())) {
		_delete_saver();
	}

	saver.instantiate();
	godot::ResourceSaver::get_singleton()->add_resource_format_saver(saver);
}

void HXGEditorPlugin::_delete_language() {
	if(likely(language != nullptr)) {
		godot::Engine::get_singleton()->unregister_script_language(language);
		memdelete(language);
		language = nullptr;
	}
}

void HXGEditorPlugin::_delete_loader() {
	if(likely(loader.is_valid())) {
		godot::ResourceLoader::get_singleton()->remove_resource_format_loader(loader);
		loader.unref();
	}
}

void HXGEditorPlugin::_delete_saver() {
	if(likely(saver.is_valid())) {
		godot::ResourceSaver::get_singleton()->remove_resource_format_saver(saver);
		saver.unref();
	}
}
