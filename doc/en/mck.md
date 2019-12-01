# Sound Driver for FAMICOM / NES [MCK] #
Last Edited 2003.02.28
        
## What's this ?
This is a sound driver for the Famicom.
It makes it easy to manipulate various sounds on the Famicom.
Remain assured that it won't rewrite your registry.

## Usage
`mck` doesn't do anything by itself; it requires 6502 assembly as input.
You need to grab a copy of NESASM from [MagicKit](http://www.magicengine.com/mkit/index.html) first.

You can also find some other helpful utility programs [here](https://www.zophar.net/utilities/nsf.html).

1. Create your song data using whatever tool you prefer
2. Output various data formats (.nes / .nsf / .fds ) using `mck` and `nesasm`
3. Enjoy!

## Files
`mck.md` - You are here.

`history.txt` - Changelog

`sounddrv.h` - 2A03 internal sound driver

`fds.h` - Famicom Disk System expansion audio sound driver

`n106.h` - Namcot106 expansion audio sound driver

`freqdata.h` - Frequency data for various sound sources




`songdata.h` - Your song data

`effect.h` - FDS / N106 expansion audio tones, effect processors, settings, etc.

 ^ these two files are created by the user. A detailed explanation is in the next section.
 
 
`make_nsf.bat` - BAT script for creating NSF files.
 
`make_nsf.txt` - Data used for creating NSF files. (header information is also written into here)
 
`make_nes.bat` - BAT script for creating NES files

`make_nes.txt` - The data used for creating NES files (It outputs NES files with [Mapper 19](https://wiki.nesdev.com/w/index.php/INES_Mapper_019), for n106 support)

`make_fds.bat` - BAT script for creating FDS files

`make_fds.txt` - The data used for creating FDS files (which can use the FDS expansion audio)

`fdshdr.bin` - The header data used for creating FDS files.

`fdsboot.bin` - The data used for creating FDS files.

`make_nat.bat`
`make_nat.txt` - These are used for generating input files for an old program called `N-Line AT` that appears to have fallen off the internet.
 
 
