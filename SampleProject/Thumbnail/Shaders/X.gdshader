shader_type spatial;

render_mode depth_test_disabled;

void vertex() {
	// Called for every vertex the material is visible on.
}

void fragment() {
	ALBEDO = vec3(9999999.0, 0.0, 0.0);
	METALLIC = 1.0;
}
