C on x86
========

A test of C running on x86 hardware with no OS. Using GRUB for bootloader.
Enters VGA mode and sets up a stack with Assembly. C functions are called from Assembly which then write to the framebuffer with a basic driver.

TODO
----

None of the more advanced OS concepts have yet been implemented (Interrupts, paging, user mode).  
Keyboard input is not yet possible due to the lack of interrupt handing. I intend to get to this at some point.


Dependencies
------------

"make run" requires bochs to be installed to launch Bochs after building.
Change the "display_library" line in bochsrc.txt to reflect what you have installed. Options are listed here: http://bochs.sourceforge.net/doc/docbook/user/bochsrc.html


Run on Linux
------------

To launch with bochs use:  

  make run  
if Bochs hangs type this in the terminal: c  
press enter  

To make just an iso type:  
  make
