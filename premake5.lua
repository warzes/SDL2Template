workspace "SDL2Template"
	location "Prj"
	architecture "x64" 
	startproject "SDL2Template"
	
	configurations
	{ 
		"Debug", 
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}
	
externalproject "SDL"
	location "Lib/SDL2/VisualC/SDL"
	uuid "8d54ac68-4caf-4b5d-b65a-d5ce4b4c0d95"
	kind "SharedLib"
	language "C++"
	
externalproject "SDLmain"
	location "Lib/SDL2/VisualC/SDLmain"
	uuid "7b7f7515-754f-462c-aa70-c9f8947008ad"
	kind "StaticLib"
	language "C++"
	
project "SDL2Template"
	location "Prj/SDL2Template"
	uuid "2afe1a70-54d4-4778-80b8-b62c61e555ae"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"
	
	targetdir "Bin"
	targetname "%{prj.name}%{cfg.buildcfg}"
	
	objdir "Tmp/%{prj.name}%{cfg.architecture}%{cfg.buildcfg}"
	
	files 
	{ 
		"Inc/**.h",
		"Src/**.cpp"
	}
	
	includedirs
	{
		"Inc",
		"Lib/SDL2/include"
	}
	
	dependson
	{
		"SDL",
		"SDLmain"
	}
	
	links
	{
		"SDL",
		"SDLmain"
	}

	postbuildcommands { "{COPY} ../x64/%{cfg.buildcfg}/SDL2.dll %{cfg.targetdir}" }
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "On"