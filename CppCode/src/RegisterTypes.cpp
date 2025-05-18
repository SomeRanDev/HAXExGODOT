#include "RegisterTypes.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "HXGEditorPlugin.hpp"
#include "HXGUtils.hpp"
#include "ScriptLanguage/HXGResourceFormatLoader.hpp"
#include "ScriptLanguage/HXGResourceFormatSaver.hpp"
#include "ScriptLanguage/HXGScript.hpp"
#include "ScriptLanguage/HXGScriptLanguage.hpp"

// Tragically, there is a bug with Godot where custom scripting languages that are added post-initialization
// aren't updated to appear in the "Attach Node Script" dialog. EditorPlugin._enter_tree runs too late.
//
// Fix can be tracked here: https://github.com/godotengine/godot/pull/104868
// Will treat this like normal EditorPlugin after fix is stable.
static HXGEditorPlugin* plugin = nullptr;

void nocheck_delete_plugin() {
	plugin->_exit_tree();
	delete plugin;
	plugin = nullptr;
}

void initialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	// if(p_level == godot::MODULE_INITIALIZATION_LEVEL_EDITOR) {
	// 	GDREGISTER_CLASS(HXGEditorPlugin);
	// 	return;
	// }

	if(p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	HXGUtils::print_verbose("Initializing (scene)");

	GDREGISTER_ABSTRACT_CLASS(HXGScript);
	GDREGISTER_ABSTRACT_CLASS(HXGScriptLanguage);
	GDREGISTER_ABSTRACT_CLASS(HXGResourceFormatLoader);
	GDREGISTER_ABSTRACT_CLASS(HXGResourceFormatSaver);

	if(unlikely(plugin != nullptr)) {
		nocheck_delete_plugin();
	}
	plugin = new HXGEditorPlugin();
	plugin->_enter_tree();
}

void uninitialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	if(p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	HXGUtils::print_verbose("Uninitializing (scene)");

	if(likely(plugin != nullptr)) {
		nocheck_delete_plugin();
	}
}

extern "C" {

GDExtensionBool GDE_EXPORT haxe_x_godot_init( // clang-format off
	GDExtensionInterfaceGetProcAddress p_get_proc_address,
	GDExtensionClassLibraryPtr p_library,
	GDExtensionInitialization* r_initialization // clang-format on
) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
	init_obj.register_initializer(initialize_gdextension_types);
	init_obj.register_terminator(uninitialize_gdextension_types);
	init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);
	return init_obj.init();
}
}
