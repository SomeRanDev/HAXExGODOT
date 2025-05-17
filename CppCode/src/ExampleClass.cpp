#include "ExampleClass.hpp"

void ExampleClass::_bind_methods() {
	godot::ClassDB::bind_method(godot::D_METHOD("print_type", "variant"), &ExampleClass::print_type);
}

void ExampleClass::print_type(const godot::Variant& p_variant) const {
	print_line(vformat("Type: %d", p_variant.get_type()));
}
