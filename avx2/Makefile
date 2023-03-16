#CFLAGS += -mavx2 -mbmi2 -mpopcnt -maes -march=native -mtune=native -O3 -fomit-frame-pointer -D KYBER_90S -DKYBER_K=3
ccflags-y := -g -mavx2 -mbmi2 -mpopcnt -maes -march=native -mtune=native -O3 -D KYBER_90S -DKYBER_K=3
all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
#obj-m += kem.o indcpa.o polyvec.o poly.o fq.o shuffle.o ntt.o invntt.o basemul.o consts.o rejsample.o cbd.o verify.o aes256ctr.o randombytes.o test_kyber.o
test_kyber-objs := kem.o indcpa.o polyvec.o poly.o basemul.o consts.o rejsample.o cbd.o verify.o aes256ctr.o randombytes.o test_kyber_main.o 
test_kyber-y := fq.o shuffle.o ntt.o invntt.o
obj-m += test_kyber.o 
clean:
	rm -rf *.o *.ko *.mod.c .an* .lab* .tmp_versions Module.oymvers Module.markers modules.order .*.cmd *.mod
