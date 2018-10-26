{
	"targets":[
		{
			"target_name":"wrapping_object",
			"include_dirs": [
				"include"
			],
			"defines": [
				"BUILDING_NODE_EXTENSION"
			],
			"sources": [
				"src/main.cc",
				"src/myobject.cc"
			]
		}
	]
}