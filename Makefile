obj-m += ili9341Driver.o

all: module dt
	@echo Builded Device Tree Overlay and kernel module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
dt: ili9341Overlay.dts
	dtc -@ -I dts -O dtb -o ili9341Overlay.dtbo ili9341Overlay.dts
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf ili9341Overlay.dtbo