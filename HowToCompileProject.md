# Introduction #

Short guide on compilation


# Details #

This project depends on QJson library.

You need to get all two projects by:

  * **git clone https://code.google.com/p/qt-google-maps/**
  * **git clone git://gitorious.org/qjson/qjson.git**

All two folders: **qt-google-maps, qjson** must be in the same directory.

Then you need to compile **qjson** library first.
We count that **qjson** library is in the **qjson/build/lib** directory.


Then the **qt-google-maps** project will be compiled OK. To run it you need to adjust **LD\_LIBRARY\_PATH** on Linux (or **PATH** on Windows) so that variable points to the **qjson/build/lib** directory.