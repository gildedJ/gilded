workspace "gilded"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "gilded.Engine"
    location "gilded.Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "GILDED_PLATFORM_WINDOWS",
            "GILDED_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "GILDED_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GILDED_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GILDED_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "gilded.Engine/vendor/spdlog/include",
        "gilded.Engine/src"
    }

    links
    {
        "gilded.Engine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines
        {
            "GILDED_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GILDED_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GILDED_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GILDED_DIST"
        optimize "On"