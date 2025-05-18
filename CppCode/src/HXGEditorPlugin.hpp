#pragma once

#include <godot_cpp/classes/editor_plugin.hpp>

#include "ScriptLanguage/HXGResourceFormatLoader.hpp"
#include "ScriptLanguage/HXGResourceFormatSaver.hpp"
#include "ScriptLanguage/HXGScriptLanguage.hpp"

// Check RegisterTypes.cpp for why this isn't an EditorPlugin YET
class HXGEditorPlugin /*: public godot::EditorPlugin*/ {
	//GDCLASS(HXGEditorPlugin, EditorPlugin);

	HXGScriptLanguage* language;
	godot::Ref<HXGResourceFormatLoader> loader;
	godot::Ref<HXGResourceFormatSaver> saver;

public:
	static HXGEditorPlugin* self;

	static void _bind_methods();

	HXGEditorPlugin() {}

	// ---

	void _enter_tree(); // override;
	void _exit_tree();	// override;

	// ---

	HXGScriptLanguage* get_language() const;

private:
	void _create_language();
	void _create_loader();
	void _create_saver();

	void _delete_language();
	void _delete_loader();
	void _delete_saver();
};
