#include "RegisterTypes.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "ExampleClass.hpp"
#include "ScriptLanguage/HXGScriptBase.hpp"
#include "ScriptLanguage/HXGScriptLanguage.hpp"

void initialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	if(p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(ExampleClass);
	GDREGISTER_CLASS(HXGScriptBase);
	GDREGISTER_CLASS(HXGScriptLanguage);

	HXGScriptLanguage::get_singleton();
}

void uninitialize_gdextension_types(godot::ModuleInitializationLevel p_level) {
	if(p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" GDExtensionBool GDE_EXPORT haxe_x_godot_init( // clang-format off
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
