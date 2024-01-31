-- (c) Spyridon Zervos


project('PolarCoordinatesTest')
kind('ConsoleApp')
language('C++')
cppdialect('C++20')
staticruntime('on')
targetdir('bin/%{cfg.buildcfg}')
debugdir('%{wks.location}')

files({
    '../inc/**.h',
    '../src/**.cpp'
})

includedirs({
    '../inc',
    '../src'
})

targetdir('../bin/' .. outputdir .. '/%{prj.name}')
objdir('../bin-int/' .. outputdir .. '/%{prj.name}')

filter('system:windows')
systemversion('latest')
defines({ 'RT_PLATFORM_WINDOWS' })

filter('configurations:Debug')
defines({ 'RT_DEBUG' })
runtime('Debug')
symbols('On')

filter('configurations:Release')
defines({ 'RT_RELEASE' })
runtime('Release')
optimize('On')
symbols('On')

filter('configurations:Dist')
defines({ 'RT_DIST' })
runtime('Release')
optimize('Speed')
symbols('Off')