#FVO is an Fast Visual Odometry library.#

##required thirdparties##

###OpenCV, 3.2 or high###
How is it be used and how to install it?
Used by binary library, so you must build it and place it in correct folder.

###Sophus###



###Boost###
DONT USE SRC FILES, strongly suggest download and install boost by binary boost install package.


##Build by cmake##

###Windows x86_x64 on Windows 10###
cmake -H. -Bbuild_x64 -G"Visual Studio 14 2015 Win64"

###Windows x86 on Windows 10###
cmake -H. -Bbuild_x86 -G"Visual Studio 14 2015"