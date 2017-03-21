#FVO is an Fast Visual Odometry library.#

 ##1. Dependencies##

###OpenCV, 3.2 or high###
​		Uses with its binary library, so you must build it and place it in correct folder.

###Sophus###



###Boost###
​		DONT USE ITS SRC FILES, strongly suggest to download its binary installer package.






##2. Build instruction##
###Windows###
​		x64: 
​		cmake -H. -Bbuild_x64 -G"Visual Studio 14 2015 Win64"

​		w32: 
​		cmake -H. -Bbuild_x86 -G"Visual Studio 14 2015"


###Linux/macOS###
​		cmake -H. -Bbuild -G"Unix Makefiles"




##3. Attentions##
