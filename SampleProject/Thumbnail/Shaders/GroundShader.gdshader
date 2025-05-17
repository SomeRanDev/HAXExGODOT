// Based on:
// https://godotshaders.com/snippet/voronoi/

shader_type spatial;

uniform sampler2D palette: filter_nearest;
uniform sampler2D normal_map;
uniform float scale = 1.0;

vec2 random(vec2 uv) {
	return vec2(fract(sin(dot(uv.xy, vec2(12.9898,78.233))) * 43758.5453123));
}

vec2 voronoi(vec2 uv, float columns, float rows) {
	vec2 index_uv = floor(vec2(uv.x * columns, uv.y * rows));
	vec2 fract_uv = fract(vec2(uv.x * columns, uv.y * rows));
	float minimum_dist = 1.0;
	vec2 minimum_point;

	for(int y = -1; y <= 1; y++) {
		for(int x = -1; x <= 1; x++) {
			vec2 neighbor = vec2(float(x),float(y));
			vec2 point = random(index_uv + neighbor);

			vec2 diff = neighbor + point - fract_uv;
			float dist = length(diff);

			if(dist < minimum_dist) {
				minimum_dist = dist;
				minimum_point = point;
			}
		}
	}
	return minimum_point;
}

vec3 hsv2rgb(vec3 c) {
	vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
	vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
	return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void fragment() {
	vec3 voronoi = vec3(voronoi(UV * scale, 10.0, 5.0).r);
	float amount = vec4(voronoi, 1.0).r;
	ALBEDO = texture(palette, vec2(amount, 0.5)).rgb;//hsv2rgb(vec3(amount, 1.0, 1.0));\

	float centerness = SCREEN_UV.x < 0.5 ? (1.0 - (SCREEN_UV.x / 0.5)) : (0.0 - ((SCREEN_UV.x - 0.5) / 0.5));
	NORMAL = mix(vec3(0.0, 1.0, 0.0), texture(normal_map, UV * scale * 0.1).rgb, 1.0 - centerness);
	ROUGHNESS = 0.0;// + amount * 0.7;
	METALLIC = 1.0;// - amount * 0.5;
}
