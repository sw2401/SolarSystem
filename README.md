3D OpenGL Animation Model of our SolarSystem

How to setup freeglut with Visual Studio Using Windows:

    Download the Freeglut package 2015 from OnCourse
    Extract Freeglut folder from zip file
    Navigate to directory: “C:\Program Files\Common Files\”
    Create folder named: “MSVC”
    Move Freeglut folder to: “C:\Program Files\Common Files\MSVC\freeglut\”
    Determine if you have a 32 or 64 bit system (if you a 32 bit system you will use the files in the directories we will be working in shortly and if you have a 64 bit system you will use the files in the directories that are in the x64 folders). I will continuing the rest of this as if it is a 64 bit system, because most of you I assume will have 64 bit system.
    Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\bin\x64” and copy the freeglut.dll file (if you have a 32 bit system use the file in the bin directory)
    Navigate to: “C:\Windows\System32” and paste the freeglut.dll file in this directory
    Now open Visual Studios and create an empty C++ project
    Add new item, main.cpp file
    Right click on your project name in the Solution Explorer panel on the right of your screen and select properties
    Make sure the Platform is set to x64
    Click on VC++ Directories
    Click on Include Directories and then on the drop-down arrow on the right side and click edit
    Click on the new folder icon at the top and then the “...”
    Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\include” so that the include folder is selected and click select folder.
    Click on the new folder icon at the top and then the “...” again
    Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\lib\x64” so that the x64 folder is selected and click select folder.
    Click OK
    Now Click on Library Directories and then on the drop-down arrow on the right side and click edit
    Click on the new folder icon at the top and then the “...”
    Navigate to: “C:\Program Files\Common Files\MSVC\freeglut\lib\x64” so that the x64 folder is selected and click select folder.
    Click OK
    Make sure to click “Apply”!
    Click OK
    At the top of the screen next to Debug set it to x64 You should be all setup. You can paste the test code from the freeglut_help doc on OnCourse to make sure it works. For every new project you create you will have to repeat steps 9 through 26.
