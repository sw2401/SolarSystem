# SolarSystem
3D OpenGL Animation Model of our SolarSystem

How to setup freeglut with Visual Studio Using Windows:
1) Download the Freeglut package 2015 from OnCourse
2) Extract Freeglut folder from zip file
3) Navigate to directory: “C:\Program Files\Common Files\”
4) Create folder named: “MSVC”
5) Move Freeglut folder to: “C:\Program Files\Common Files\MSVC\freeglut\”
6) Determine if you have a 32 or 64 bit system (if you a 32 bit system you will use the files in the
directories we will be working in shortly and if you have a 64 bit system you will use the files in
the directories that are in the x64 folders).
I will continuing the rest of this as if it is a 64 bit system, because most of you I assume will have 64 bit
system.
7) Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\bin\x64” and copy the freeglut.dll
file (if you have a 32 bit system use the file in the bin directory)
8) Navigate to: “C:\Windows\System32” and paste the freeglut.dll file in this directory
9) Now open Visual Studios and create an empty C++ project
10) Add new item, main.cpp file
11) Right click on your project name in the Solution Explorer panel on the right of your screen and
select properties
12) Make sure the Platform is set to x64
13) Click on VC++ Directories
14) Click on Include Directories and then on the drop-down arrow on the right side and click edit
15) Click on the new folder icon at the top and then the “...”
16) Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\include” so that the include folder
is selected and click select folder.
17) Click on the new folder icon at the top and then the “...” again
18) Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\lib\x64” so that the x64 folder is
selected and click select folder.
19) Click OK
20) Now Click on Library Directories and then on the drop-down arrow on the right side and click
edit
21) Click on the new folder icon at the top and then the “...”
22) Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\lib\x64” so that the x64 folder is
selected and click select folder.
23) Click OK
24) Make sure to click “Apply”!
25) Click OK
26) At the top of the screen next to Debug set it to x64
You should be all setup. You can paste the test code from the freeglut_help doc on OnCourse to make
sure it works. For every new project you create you will have to repeat steps 9 through 26.
