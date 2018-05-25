# mruby/c library for Wio LTE

This is a mruby/c library for Wio LTE in Arduino environment.
**This is my experimental work. There is no guarantee about this library.**

## Usage

### Condition

This library depends on WioLTEforArduino library. Please install it in advance.

https://github.com/SeeedJP/WioLTEforArduino

### Import the library to Arduino IDE

Clone this repository.

    clone https://github.com/kishima/libmrubycForWioLTEArduino.git

Copy "libmrubycForWioLTEArduino" to your Arduino library directory.

    cp -r libmrubycForWioLTEArduino [your document directory]/Arduino/libraries/libmrubycForWioLTEArduino

Include a header file libmrubyc.h.

### Implement mruby/c functions

Nothing changed in basic usage of mruby/c. You can use mruby/c APIs.
I added following function(s).

- mrbc_define_wiolte_methods
- mrbc_get_wiolte_obj

You can refer example files about detailed usage.
Of course, you need compiled mruby byte code to run on it.

For example, the on board RGB LED can be controled by following script.

    r=0
    g=0
    b=0
    while true
    	r=b/2
    	g=b/3
    	puts "mruby/c example: control LED B="+b.to_s
    	Wio.control_led(r,g,b)
    	sleep(1)
    	b=b+10
    	b=0 if b>60
    end

## Future work (if I'm good...)

- define mruby methods of Arduino and Wio LTE.
- implement an automatical executer and an uploader of mruby byte code.
- implement a function about downloading mruby byte code Over The Air.

## Copyright

Refer LICENSE file.

